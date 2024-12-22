#include "OpenSSL.h"
#pragma comment (lib, "crypt32")
#pragma comment (lib, "Ws2_32")
#include <openssl/err.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/core_names.h>
#include <string>
#include <iostream>

const static string IV = OpenSSL::hashear256("Este es un vector de inicialización super ultra mega secreto").substr(0, 12);
const static string ADD = "-_-_-_-";

string OpenSSL::encriptar(string key, const string STR, string& tag) {
    tag = "";
    key = OpenSSL::hashear256(key);

    static OSSL_LIB_CTX* libctx = NULL;
    static const char* propq = NULL;

    EVP_CIPHER_CTX* ctx;
    EVP_CIPHER* cipher = NULL;
    int outlen, tmplen;
    size_t ivlen = IV.size();
    unsigned char outbuf[1024];
    unsigned char outtag[16];
    OSSL_PARAM params[2] = {
        OSSL_PARAM_END, OSSL_PARAM_END
    };

    if ((ctx = EVP_CIPHER_CTX_new()) == NULL)
        return "";

    if ((cipher = EVP_CIPHER_fetch(libctx, "AES-256-GCM", propq)) == NULL)
        return "";

    params[0] = OSSL_PARAM_construct_size_t(OSSL_CIPHER_PARAM_AEAD_IVLEN, &ivlen);

    if (!EVP_EncryptInit_ex2(ctx, cipher, reinterpret_cast<const unsigned char*>(key.c_str()), reinterpret_cast<const unsigned char*>(IV.c_str()), params))
        return "";

    if (!EVP_EncryptUpdate(ctx, NULL, &outlen, reinterpret_cast<const unsigned char*>(ADD.c_str()), ADD.size()))
        return "";

    if (!EVP_EncryptUpdate(ctx, outbuf, &outlen, reinterpret_cast<const unsigned char*>(STR.c_str()), STR.size()))
        return "";

    if (!EVP_EncryptFinal_ex(ctx, outbuf, &tmplen))
        return "";

    params[0] = OSSL_PARAM_construct_octet_string(OSSL_CIPHER_PARAM_AEAD_TAG, outtag, 16);

    if (!EVP_CIPHER_CTX_get_params(ctx, params))
        return "";

    string t(reinterpret_cast<char*>(outtag), 16);
    tag = t;

    string rta(reinterpret_cast<char*>(outbuf), outlen);
    return rta;
}

string OpenSSL::desencriptar(string key, const string STR, const string TAG) {
	return "";
}