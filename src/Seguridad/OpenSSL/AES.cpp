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

unsigned char* OpenSSL::encriptar(const unsigned char* KEY, const unsigned char* STR, const unsigned short& LEN_STR, unsigned char* tag, unsigned short& LEN_RTA) {
    tag = new unsigned char[16];

    OSSL_LIB_CTX* libctx = NULL;
    const char* propq = NULL;

    EVP_CIPHER_CTX* ctx;
    EVP_CIPHER* cipher = NULL;
    int outlen, tmplen;
    unsigned char outbuf[1024];
    OSSL_PARAM params[2] = {
        OSSL_PARAM_END, OSSL_PARAM_END
    };

    if ((ctx = EVP_CIPHER_CTX_new()) == NULL);

    if ((cipher = EVP_CIPHER_fetch(libctx, "AES-256-GCM", propq)) == NULL);

    params[0] = OSSL_PARAM_construct_size_t(OSSL_CIPHER_PARAM_AEAD_IVLEN, &IV_SIZE);

    if (!EVP_EncryptInit_ex2(ctx, cipher, KEY, IV, params));

    if (!EVP_EncryptUpdate(ctx, NULL, &outlen, &ADD, ADD_SIZE));

    if (!EVP_EncryptUpdate(ctx, outbuf, &outlen, STR, LEN_STR));

    if (!EVP_EncryptFinal_ex(ctx, outbuf, &tmplen));

    params[0] = OSSL_PARAM_construct_octet_string(OSSL_CIPHER_PARAM_AEAD_TAG, tag, 16);

    if (!EVP_CIPHER_CTX_get_params(ctx, params));

    unsigned char* rta = new unsigned char[outlen];
    memcpy(rta, outbuf, outlen);

    LEN_RTA = outlen;

    return rta;
}

/*void OpenSSL::desencriptar(string key, const string STR, const string TAG) {
    EVP_CIPHER_CTX* ctx;
    EVP_CIPHER* cipher = NULL;
    int outlen, rv;
    size_t gcm_ivlen = IV.size();
    unsigned char outbuf[1024];
    OSSL_PARAM params[2] = {
        OSSL_PARAM_END, OSSL_PARAM_END
    };

    printf("AES GCM Decrypt:\n");
    printf("Ciphertext:\n");
    BIO_dump_fp(stdout, gcm_ct, sizeof(gcm_ct));

    if ((ctx = EVP_CIPHER_CTX_new()) == NULL)
        return "";

    if ((cipher = EVP_CIPHER_fetch(libctx, "AES-256-GCM", propq)) == NULL)
        return "";

    params[0] = OSSL_PARAM_construct_size_t(OSSL_CIPHER_PARAM_AEAD_IVLEN, &gcm_ivlen);

    if (!EVP_DecryptInit_ex2(ctx, cipher, gcm_key, gcm_iv, params))
        return "";

    if (!EVP_DecryptUpdate(ctx, NULL, &outlen, gcm_aad, sizeof(gcm_aad)))
        return "";

    if (!EVP_DecryptUpdate(ctx, outbuf, &outlen, gcm_ct, sizeof(gcm_ct)))
        return "";

    params[0] = OSSL_PARAM_construct_octet_string(OSSL_CIPHER_PARAM_AEAD_TAG, (void*)gcm_tag, sizeof(gcm_tag));

    if (!EVP_CIPHER_CTX_set_params(ctx, params))
        return "";

    rv = EVP_DecryptFinal_ex(ctx, outbuf, &outlen);

    return "";
}*/