#include <iostream>
#include <map>
#include <vector>
//#include "../include/ArgNode.h"
//#include "../include/FlagNode.h"
#include "../include/HashMap.h"
#include "../include/HashNode.h"
#include "../include/OptNode.h"
#include "../include/NameSpace.h"


//Changes to make - remove optnode n, replace with optional const char* alias
//Use n with ArgNode
int main(int argc, char* argv[]) {
    try {
        HashMap<OptNode>* hashmap = new HashMap<OptNode>();
        NameSpace* res = new NameSpace();
        OptNode node1("--flag1");
        OptNode node2("--option1", 1);
        OptNode node3("--flag2");
        OptNode node4("--flag1");
        hashmap->insert("--option1", node2);
        hashmap->insert("--flag2", node3);
        hashmap->insert("-a", node4);
        hashmap->insert("--flag1", node1);
        for (int i = 1; i < argc; ++i) {
            std::cout << "Searching" << std::endl;
            OptNode* node = hashmap->search(argv[i]);
            if (node == nullptr) {
                std::cout << argv[i] << " not found" << std::endl;
            }
            else {
                res->insert(argv[i], node->get_opt()); 
            }
        }
        res->print();
        delete hashmap;
    } catch (const char* error) {
        std::cout << error << std::endl;
    }
    

    return 0;
}
