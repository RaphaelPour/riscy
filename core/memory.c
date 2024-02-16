#include <stddef.h>
#include "memory.h"

#define HEAP_CAPACITY 64000

static char heap[HEAP_CAPACITY] = {0};
static size_t heap_size = 0;

void * malloc(size_t size) {
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
  for (size_t i = 0; i < size; i++) {
    ((unsigned char *) p)[i] = (unsigned char) val;
  }
}

void memcpy(void *dest, const void *src, size_t n) {
  for (size_t i = 0; i < n; i++) {
    ((unsigned char *) d)[i] = ((const unsigned char *) s)[i];
  }
}

int memcmp(const void *dest, const void *src, size_t n) {
  for (size_t i = 0; i < n; i++) {
    if (((const unsigned char *) s)[i] != ((const unsigned char *) d)[i]) {
      return 0;
    }
  }

  return 1;
}
