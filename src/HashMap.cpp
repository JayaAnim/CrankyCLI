#include <iostream>
#include <cstring>
#include "../include/HashMap.h"
#include "../include/HashNode.h"

template <typename V>
HashMap<V>::HashMap() {
    map = new HashNode<V>[30];
}

template <typename V>
int HashMap<V>::hash(const char* key) {
    int hash = 0;
    for (int i = 0; i < strlen(key); ++i) {
        hash += ((int)key[i] + i);
    }
    hash = hash % 30;
    return hash;
}

template <typename V>
HashNode<V>* HashMap<V>::insert(const char* key, V* obj) {
    int hash_code = this->hash(key);
    return map[hash_code]->append(key, obj);
}

template <typename V>
V* HashMap<V>::get_elem(const char* key) {
   int hash_code = this->hash(key);
   if (map[hash_code] == nullptr) return nullptr;
   return map[hash_code]->find(key);
}
