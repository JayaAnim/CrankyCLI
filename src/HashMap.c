#include <stdio.h>
#include <stdlib.h>
#include "../include/HashMap.h"
#include "../include/HashNode.h"


void tHashMap_uninit(tHashMap* self) {
    for (int i = 0; i < 30; ++i) {
        if (self->map[i].key == NULL) free(&self->map[i]);
        else {
            self->map[i].uninit(&self->map[i]);
        }
    }
}

int tHashMap_hash(const char* key) {
    int hash = 0;
    for (size_t i = 0; i < strlen(key); ++i) {
        hash += ((int)key[i] + i);
    }
    hash = hash % 30;
    return hash;
}

int tHashMap_insert(tHashMap* self, const char* key, void* obj) {
    int index = tHashMap_hash(key);
    if (self->map[index].key == NULL) {
        self->map[index].key = key;
        self->map[index].obj = obj;
        return 0;
    }
    return self->map[index].append(&self->map[index], key, obj);
}

void* tHashMap_search(tHashMap* self, char* key) {
    int index = tHashMap_hash(key);
    if (self->map[index].key == NULL) return NULL; 
    return self->map[index].search(&self->map[index], key);
}


int tHashMap_init(tHashMap* inst) {
    inst->map = (tHashNode*)malloc(sizeof(tHashNode) * 30); 
    inst->uninit = &tHashMap_uninit;
    inst->insert = &tHashMap_insert;
    inst->search = &tHashMap_search;
    return 0;
}



/*
struct sHashNode* map;
void (*uninit)(struct sHashMap* self);
tHashNode* (*insert)(struct sHashMap* self, const char* key, void* obj);
void* (*search)(struct sHashMap* self, char* key);
int hash_map_init(tHashMap* map);
*/
