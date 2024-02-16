#include <stddef.h>
#include "hash_map.h"


void *hash_map_insert(HashMap hm, size_t key, void *value) {
    size_t k = key % hm.size;
    if (hm.items[k] != NULL) {
        // item already at index, need to widen the HashMap (not handeled yet)
        return NULL;
    }

    hm.items[k] = value;
    return value;
}

void *hash_map_get(HashMap hm, size_t key) {
    size_t k = key % hm.size;
    return hm.items[k];
}

void hash_map_free(HashMap _hm) {
    // TODO: implement
}
