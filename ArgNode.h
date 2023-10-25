#ifndef ARGNODE_H
#define ARGNODE_H

typedef struct sArgNode {
    struct sArgNode* next;
    const char* name_key; /* key to be stored in namespace */
    int (*append)(struct sArgNode** tail, const char* name_key);
    struct sArgNode* (*search)(struct sArgNode* self, char* key); 
} tArgNode;

int tArgNode_init(tArgNode* inst, const char* name_key);

#endif
