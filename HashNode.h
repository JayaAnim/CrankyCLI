#ifndef HASHNODE_H
#define HASHNODE_H
#include <stdio.h>
#include <string.h>

typedef struct sHashNode {
        struct sHashNode* next;
        const char* key;
        void* obj;
        void (*uninit)(struct sHashNode* self);
        void (*uninit_obj)(void* obj);
        void* (*search)(struct sHashNode* self, char* key);
        int (*append)(struct sHashNode* self, const char* key, void* obj);
} tHashNode;

int tHashNode_init(tHashNode* inst);

#endif
