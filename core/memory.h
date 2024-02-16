#ifndef MEMORY_H
#define MEMORY_H

#include <stddef.h>

void *malloc(size_t size);
void free();

void memset(void *ptr, int value, size_t size);
void memcpy(void *dest, const void *src, size_t n);
int memcmp(const void *dest, const void *src, size_t n);

#endif
