#include <stddef.h>
#include "memory.h"

#define HEAP_CAPACITY 64000
#define HASH_MAP_CAPACITY HEAP_CAPACITY
#include "hash_map.h"


char heap[HEAP_CAPACITY] = {0};
HashMap heap_watcher = {
    {0},
    HASH_MAP_CAPACITY,
};
size_t heap_size = 0;

void *malloc(size_t size) {
    heap_size += size;
    return NULL;
}

void free(void *ptr) {

}
