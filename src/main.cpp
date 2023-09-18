#include <iostream>
#include <map>
#include <vector>
#include "../include/ArgNode.h"
#include "../include/OptNode.h"
#include "../include/FlagNode.h"


int main(int argc, char* argv[]) {
    try {
    /*
    OptNode* head = new OptNode("--head_key");
    head->insert("--key1");
    head->insert("--key2");
    head->insert("--key3");
    head->insert("--key4");
    std::map<const char*, std::vector<const char*>> hashmap;


    int pos = 1;
    bool res = head->parse(hashmap, pos, argc, argv);

    for (auto i : hashmap) {
        std::cout << i.first << ": ";
        for (auto j : i.second) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }



    delete head;
    */
    FlagNode* head = new FlagNode("--HeadFlag");
    head->insert("--flag1");
    head->insert("--flag2");
    head->insert("--flag3");
    } catch (const char* error) {
        std::cout << error << std::endl;
    }
    

    return 0;
}
