#include <iostream>
#include <map>
#include <vector>
//#include "../include/ArgNode.h"
//#include "../include/FlagNode.h"
#include "../include/HashMap.h"
#include "../include/HashNode.h"
#include "../include/OptNode.h"


int main(int argc, char* argv[]) {
    try {
        HashMap<OptNode>* hashmap = new HashMap<OptNode>();
        OptNode node1("--flag1");
        OptNode node2("--option1", 1);
        OptNode node3("--flag2");
        OptNode node4("--flag1");
        hashmap->insert("--option1", node2);
        hashmap->insert("--flag2", node3);
        hashmap->insert("-a", node4);
        hashmap->insert("--flag1", node1);
        for (int i = 0; i < argc; ++i) {
            if (hashmap->
        }
        delete hashmap;
    } catch (const char* error) {
        std::cout << error << std::endl;
    }
    

    return 0;
}
