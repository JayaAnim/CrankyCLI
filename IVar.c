#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IVar.h"


char* tVar_get_name_key(const char* argv) {
    char* name_key = (char*)malloc(sizeof(argv) - 2);
    strcpy(name_key, argv + 2);
    return name_key;
}

int tVar_is_valid(tVar* self, char* argv) {
    return 1;
}

void tVar_uninit(tVar* self) {
    if (self->name_key != NULL) free(self->name_key); 
}

int is_verbose(char* argv) {
    if (strlen(argv) < 4) return 0;
    else if (argv[0] != '-' || argv[1] != '-') return 0;
    else if (argv[2] == '-' || argv[3] == '-') return 0;
    return 1;
}

int is_flag(char* argv) {
    if (strlen(argv) != 2) return 0;
    else if (argv[0] != '-' || argv[1] == '-') return 0;
    return 1;
}

int tOptNode_init(tVar* inst, const char* argv) {
    if (!is_verbose((char*)argv)) {
        printf("[ERROR] Invalid Option Error (%s): Please use a valid option, see docs for more details\n", argv);
        return 1;
    }
    inst->name_key = tVar_get_name_key(argv);
    inst->is_valid = &tVar_is_valid;
    inst->uninit = &tVar_uninit;
    return 0;
}

int tFlagNode_init(tVar* inst, const char* argv) {
    if (!is_verbose((char*)argv) && !is_flag((char*)argv)) {
        printf("[ERROR] Invalid Flag Error (%s): Please use a valid flag, see docs for more details\n", argv);
        return 1;
    }
    inst->name_key = tVar_get_name_key(argv);
    inst->is_valid = NULL;
    inst->uninit = &tVar_uninit;
    return 0;
}

