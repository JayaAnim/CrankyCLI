#ifndef HASHMAP_H
#define HASHMAP_H
#include <iostream>
#include <cstring>
#include "../include/OptNode.h"
#include "HashNode.h"


template <typename V>
class HashMap {
    public:
        HashMap() {
            map = new HashNode<V>[30];
        }

        int hash(const char* key) {
            int hash = 0;
            for (unsigned long i = 0; i < strlen(key); ++i) {
                hash += ((int)key[i] + i);
            }
            hash = hash % 30;
            return hash;

        }

        HashNode<V>* insert(const char* key, V& obj) {
            int hash_code = this->hash(key);
            return map[hash_code].append(key, obj);
        }

        V* search(char* key) {
            int hash_code = this->hash(key);
            if (map[hash_code].get_key() == nullptr) return nullptr;
            return map[hash_code].search(key);
        }

        ~HashMap() {
            if (map != nullptr) {
                delete[] map;
            }
        }

    private:
        HashNode<V>* map;
};

#endif
