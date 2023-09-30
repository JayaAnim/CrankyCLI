#include <stdio.h>
#include <stdlib.h>
#include "../include/HashNode.h"

void tHashNode_uninit(tHashNode* self) {
    if (self->obj != NULL) free(self->obj);
    if (self->next != NULL) self->uninit(self);
}

void* tHashNode_search(tHashNode* self, char* key) {
    if (strcmp(self->key, key) == 0) return self->obj;
    else if (self->next != NULL) return self->search(self->next, key);
    return NULL;
}

int tHashNode_append(tHashNode* self, const char* key, void* obj) {
    if (strcmp(self->key, key) == 0) {
        printf("[ERROR] Invalid Key Error (%s): Key's must be unique", key);
        return 1;
    }
    else if (self->next != NULL) self->append(self->next, key, obj);
    tHashNode* new_node = malloc(sizeof(tHashNode));
    tHashNode_init(new_node);
    new_node->key = key;
    new_node->obj = obj;
    return 0;
}

int tHashNode_init(tHashNode* inst) {
    inst->uninit = &tHashNode_uninit;
    inst->search = &tHashNode_search;
    inst->append = &tHashNode_append;
    inst->next = NULL;
    inst->key = NULL;
    inst->obj = NULL;
    return 0;
}


/*
    struct sHashNode* next;
    const char* key;
    void* obj;
    void (*uninit)(struct sHashNode* self);
    void* (*search)(struct sHashNode* self, char* key);
    int (*append)(struct sHashNode* self, const char* key, void* obj);
    int hash_node_init(tHashNode* node);
*/
