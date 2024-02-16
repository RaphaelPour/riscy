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

void free(void *ptr) {
    (void) ptr;
    heap_size = 0;
}
