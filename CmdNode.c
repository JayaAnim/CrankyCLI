#include <stdio.h>
#include <stdlib.h>
#include "CmdNode.h"
#include "IVar.h"
#include "ArgNode.h"

//int tOptNode_init(tVar* inst, const char* argv);
//int tFlagNode_init(tVar* inst, const char* argv);

//int (*insert)(struct sHashMap* self, const char* key, void* obj);
//int tHashMap_init(tHashMap* inst);
int tCmdNode_add_opt(tCmdNode* self, tVar* opt, const char* key) {
    return self->flag_opts->insert(self->flag_opts, key, opt);
}

int tCmdNode_add_flag(tCmdNode* self, tVar* flag, const char* key, const char* short_key) {
    return self->flag_opts->insert(self->flag_opts, key, opt);
}

int tCmdNode_add_arg(tCmdNode* self, tArgNode* arg, const char* key) {
    return 0;
}

int tCmdNode_parse_args(tCmdNode* self) {
    return 0;
}

int tCmdNode_parse_flags(tCmdNode* self) {
    return 0;
}

int tCmdNode_parse_opts(tCmdNode* self) {
    return 0;
}

int tCmdNode_parse(tCmdNode* self) {
    return 0;
}

int tCmdNode_init(tCmdNode* inst, const char* key) {
    inst->flag_opts = (tHashMap*)malloc(sizeof(tHashMap));
    tHashMap_init(inst->flag_opts);  
    inst->name_key = key;
    inst->arg_head = NULL;
    inst->arg_tail = NULL;
    inst->add_opt = &tCmdNode_add_opt;
    inst->add_flag = &tCmdNode_add_flag;
    inst->add_arg = &tCmdNode_add_arg;
    inst->parse_args = &tCmdNode_parse_args;
    inst->parse_opts = &tCmdNode_parse_opts;
    inst->parse_flags = &tCmdNode_parse_flags;
    inst->parse = &tCmdNode_parse;
    return 0;
}

/*
    tHashMap* flag_opts; 
    tArgNode* arg_head;
    tArgNode* arg_tail;
    const char* name_key;
    int (*add_opt)(sCmdNode* self, tVar* opt, const char* key);
    int (*add_flag)(sCmdNode* self, tVar* flag, const char* key, const char* short_key);
    int (*add_arg)(sCmdNode* self, tArgNode* arg, const char* key);
    int (*parse_args)(sCmdNode* self);
    int (*parse_flags)(struct sCmdNode* self);
    int (*parse_opts)(struct sCmdNode* self);
    int (*parse)(sCmdNode* self);
    int tCmdNode_init(tCmdNode* inst, const char* key);
*/
