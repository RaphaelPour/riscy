#include <stddef.h>
#include "memory.h"

#define HEAP_CAPACITY 64000

char heap[HEAP_CAPACITY] = {0};
size_t heap_size = 0;

void *malloc(size_t size) {
    void *addr = heap + heap_size;
    if ((size_t) addr > (size_t) (heap + HEAP_CAPACITY)) {
        // memory could not be allocated => ran out of memory
        return NULL;
    }

    heap_size += size;
    return addr;
}

void free() {
    heap_size = 0;
}

void memset(void *ptr, int value, size_t size) {
    unsigned char *p = ptr;
    unsigned char val = (unsigned char) value;
    
    for (size_t i = 0; i < size; i++) {
        p[i] = val;
    }
}

void memcpy(void *dest, const void *src, size_t n) {
    unsigned char *d = dest;
    const unsigned char *s = src;
    
    for (size_t i = 0; i < n; i++) {
        d[i] = s[i];
    }
}

int memcmp(const void *dest, const void *src, size_t n) {
    const unsigned char *d = dest;
    const unsigned char *s = src;
    
    for (size_t i = 0; i < n; i++) {
        if (s[i] != d[i]) {
            return 0;
        }
    }

    return 1;
}
