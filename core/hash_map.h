#ifndef HASH_MAP_H
#define HASH_MAP_H

#ifndef HASH_MAP_CAPACITY
#define HASH_MAP_CAPACITY 100
#endif

typedef struct {
    void *items[HASH_MAP_CAPACITY];
    size_t size;
} HashMap;

void *hashmap_insert(HashMap *hm, size_t key, void *value);
void *hashmap_get(HashMap *hm, size_t key);
void hashmap_free(HashMap *hm);


#endif