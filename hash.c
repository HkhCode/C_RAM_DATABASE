#include <stdio.h>
#include <stdlib.h>

#include "user.h"
#include "hash.h"

int mix(int h) {
    u_int32_t u = (u_int32_t) h;
    u ^= u >> 16;
    u *= 0x85ebca6bu;
    u ^= u >> 13;
    u *= 0xc2b2ae35u;
    u ^= u >> 16;
    return (int) u;
}

int hash(char *s, int s_size) {
    int h = 17;
    for (int i = 0; i < s_size; i++) {
        h = h *31 + s[i];
    }
    return mix(h);
}

int make_index(char *s, int s_size, int array_size) {
    return (hash(s, s_size) & 0x7FFFFFFF) % array_size;
}
/*int find_index(char *username, int arraySize) {

}*/