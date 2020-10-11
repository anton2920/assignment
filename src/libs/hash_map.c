#include <stdlib.h>
#include <string.h>

#include "hash_map.h"

static size_t hashCode(const char *str, size_t size) {

    /* Initializing variables */
    auto size_t hash = 5381;
    auto char c;

    /* Main part */
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    /* Returning value */
    return hash % size;
}

struct DataItem *search(const hashMap *hashArray, size_t size, const char *key) {

    /* Initializing variables */
    auto size_t hashIndex;

    /* Main part */
    for (hashIndex = hashCode(key, size); hashArray[hashIndex] != NULL; hashIndex = (hashIndex + 1) % size) {
        if (!strcmp(hashArray[hashIndex]->key, key))
            return hashArray[hashIndex];
    }

    return NULL;
}

void insert(hashMap *hashArray, size_t size, char *key, int data) {

    /* Initializing variables */
    auto struct DataItem *item = (struct DataItem *) malloc(sizeof(struct DataItem));
    auto size_t hashIndex;

    /* Main part */

    /* Copying value */
    item->key = key;
    item->value = data;

    for (hashIndex = hashCode(key, size); hashArray[hashIndex] != NULL; hashIndex = (hashIndex + 1) % size)
        ;

    hashArray[hashIndex] = item;
}

void cleanMap(hashMap *map, size_t size) {

    /* Initializing variables */
    register size_t i;

    /* Main part */
    for (i = 0; i < size; ++i) {
        if (*(map + i) != NULL) {
            free(map[i]->key);
            free(*(map + i));
            map[i] = NULL;
        }
    }
}