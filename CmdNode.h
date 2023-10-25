#ifndef CMDNODE_H
#define CMDNODE_H
#include "HashMap.h"
#include "ArgNode.h"
#include "IVar.h"

typedef struct sCmdNode {
    tHashMap* flag_opts; 
    tArgNode* arg_head;
    tArgNode* arg_tail;
    const char* name_key;
    int (*add_opt)(struct sCmdNode* self, tVar* opt, const char* key);
    int (*add_flag)(struct sCmdNode* self, tVar* flag, const char* key, const char* short_key);
    int (*add_arg)(struct sCmdNode* self, tArgNode* arg, const char* key);
    int (*parse_args)(struct sCmdNode* self);
    int (*parse_flags)(struct sCmdNode* self);
    int (*parse_opts)(struct sCmdNode* self);
    int (*parse)(struct sCmdNode* self);
} tCmdNode;

int tCmdNode_init(tCmdNode* inst, const char* key);

#endif
