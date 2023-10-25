#ifndef HASHMAP_H
#define HASHMAP_H
#include "HashNode.h"


typedef struct sHashMap{
    tHashNode* map;
    void (*uninit)(struct sHashMap* self);
    int (*insert)(struct sHashMap* self, const char* key, void* obj);
    void* (*search)(struct sHashMap* self, char* key);
} tHashMap;

int tHashMap_init(tHashMap* inst);

#endif
