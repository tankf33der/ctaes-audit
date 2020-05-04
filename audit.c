#include <stdlib.h>
#include "ctaes.h"

typedef uint8_t u8;

#define ARRAY(name, size) \
    u8 name[size]; \
    for(size_t i = 0; i < size; i++) name[i] = 123;

void audit(void) {
    ARRAY(key, 16);
    ARRAY(plain, 16);
    ARRAY(txt,   16);
    ARRAY(dec,   16);
    AES128_ctx ctx;

    AES128_init(&ctx, key);
    AES128_encrypt(&ctx, 1, ciphered, plain);
    AES128_decrypt(&ctx, 1, deciphered, cipher);
}
