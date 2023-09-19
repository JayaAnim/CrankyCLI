#ifndef HASHMAP_H
#define HASHMAP_H
#include "HashNode.h"

template <typename V>
class HashMap {
    public:
        HashMap();
        int hash(const char* key);
        HashNode<V>* insert(const char* key, V* obj);
        V* get_elem(const char* key);
        ~HashMap();
    private:
        HashNode<V>* map;
};

#endif
