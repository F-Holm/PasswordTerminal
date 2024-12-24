#include "OpenSSL.h"
#pragma comment (lib, "crypt32")
#pragma comment (lib, "Ws2_32")
#include <openssl/err.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/core_names.h>
#include <string>
#include <iostream>

static size_t IV_SIZE = 12;
const static unsigned char IV_BASICO = reinterpret_cast<unsigned char>("Este es un vector de inicialización super ultra mega secreto");
const static unsigned char* IV = OpenSSL::hash256_x(&IV_BASICO, 60, IV_SIZE);

static size_t ADD_SIZE = 7;
const static unsigned char ADD = reinterpret_cast<unsigned char>("-_-_-_-");

const static size_t TAG_LEN = 16;

unsigned char* OpenSSL::encriptar(const unsigned char* KEY, const unsigned char* STR, const unsigned short& LEN_STR, unsigned char*& tag, unsigned short& LEN_RTA) {
    delete[] tag;
    tag = new unsigned char[TAG_LEN];
    unsigned char* rta;

    OSSL_LIB_CTX* libctx = NULL;
    const char* propq = NULL;

    EVP_CIPHER_CTX* ctx;
    EVP_CIPHER* cipher = NULL;
    int outlen, tmplen;
    unsigned char outbuf[1024];
    OSSL_PARAM params[2] = {
        OSSL_PARAM_END, OSSL_PARAM_END
    };

    if ((ctx = EVP_CIPHER_CTX_new()) == NULL)
        goto err;

    if ((cipher = EVP_CIPHER_fetch(libctx, "AES-256-GCM", propq)) == NULL)
        goto err;

    params[0] = OSSL_PARAM_construct_size_t(OSSL_CIPHER_PARAM_AEAD_IVLEN, &IV_SIZE);

    if (!EVP_EncryptInit_ex2(ctx, cipher, KEY, IV, params))
        goto err;

    if (!EVP_EncryptUpdate(ctx, NULL, &outlen, &ADD, ADD_SIZE))
        goto err;

    if (!EVP_EncryptUpdate(ctx, outbuf, &outlen, STR, LEN_STR))
        goto err;

    if (!EVP_EncryptFinal_ex(ctx, outbuf, &tmplen))
        goto err;

    params[0] = OSSL_PARAM_construct_octet_string(OSSL_CIPHER_PARAM_AEAD_TAG, tag, TAG_LEN);

    if (!EVP_CIPHER_CTX_get_params(ctx, params))
        goto err;

    rta = new unsigned char[outlen];
    memcpy(rta, outbuf, outlen);

    LEN_RTA = outlen;


    EVP_CIPHER_free(cipher);
    EVP_CIPHER_CTX_free(ctx);
    return rta;

err:
    ERR_print_errors_fp(stderr);

    EVP_CIPHER_free(cipher);
    EVP_CIPHER_CTX_free(ctx);

    return nullptr;
}

unsigned char* OpenSSL::desencriptar(const unsigned char* KEY, const unsigned char* STR, const unsigned short& LEN_STR, const unsigned char* TAG, unsigned short& LEN_RTA) {
    unsigned char* rta;
    
    OSSL_LIB_CTX* libctx = NULL;
    const char* propq = NULL;

    EVP_CIPHER_CTX* ctx;
    EVP_CIPHER* cipher = NULL;
    int outlen, rv;
    unsigned char outbuf[1024];
    OSSL_PARAM params[2] = {
        OSSL_PARAM_END, OSSL_PARAM_END
    };

    if ((ctx = EVP_CIPHER_CTX_new()) == NULL)
        goto err;

    if ((cipher = EVP_CIPHER_fetch(libctx, "AES-256-GCM", propq)) == NULL)
        goto err;

    params[0] = OSSL_PARAM_construct_size_t(OSSL_CIPHER_PARAM_AEAD_IVLEN, &IV_SIZE);

    if (!EVP_DecryptInit_ex2(ctx, cipher, KEY, IV, params))
        goto err;

    if (!EVP_DecryptUpdate(ctx, NULL, &outlen, &ADD, ADD_SIZE))
        goto err;

    if (!EVP_DecryptUpdate(ctx, outbuf, &outlen, STR, LEN_STR))
        goto err;

    params[0] = OSSL_PARAM_construct_octet_string(OSSL_CIPHER_PARAM_AEAD_TAG, (void*)TAG, TAG_LEN);

    if (!EVP_CIPHER_CTX_set_params(ctx, params))
        goto err;

    if (!EVP_DecryptFinal_ex(ctx, outbuf, &outlen))
        goto err;

    rta = new unsigned char[outlen];
    memcpy(rta, outbuf, outlen);

    LEN_RTA = outlen;

    EVP_CIPHER_free(cipher);
    EVP_CIPHER_CTX_free(ctx);
    return rta;

err:
    ERR_print_errors_fp(stderr);

    EVP_CIPHER_free(cipher);
    EVP_CIPHER_CTX_free(ctx);

    return nullptr;
}