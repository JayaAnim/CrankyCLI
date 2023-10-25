#ifndef IVAR_H
#define IVAR_H


typedef struct iVar {
    char* name_key; /* key option will be stored under in optnode */
    void (*uninit)(struct iVar* self);
    int (*is_valid)(struct iVar* self, char* argv);
} tVar;

char* tOptNode_get_name_key(const char* argv);
int is_verbose(char* argv);
int is_flag(char* argv);
int tOptNode_init(tVar* inst, const char* argv);
int tFlagNode_init(tVar* inst, const char* argv);

#endif
