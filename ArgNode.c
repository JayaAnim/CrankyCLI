#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArgNode.h"

int append(tArgNode** tail, const char* name_key) {
    tArgNode* new_node = (tArgNode*)malloc(sizeof(tArgNode));
    if (tArgNode_init(new_node, name_key)) return NULL;
    (*tail) = new_node;
}

tArgNode* search(struct sArgNode* self, char* key) {
    if (strcmp(self->name_key, key) == 0) return self;
    else if (self->next != NULL) return search(self->next, key);
    return NULL;
}

int tArgNode_init(tArgNode* inst, const char* name_key) {
    inst->name_key = name_key; 
    inst->next = NULL;
    inst->append = &append;
    inst->search = &search;
    return 0;
}

/*
    sArgNode* next;
    const char* name_key; 
    int (*append)(sArgNode* head, sArgNode** tail, const char* name_key);
    sArgNode* (*search)(char* key); 
    int tArgNode_init(tArgNode* inst);
*/
