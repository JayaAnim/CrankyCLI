#include <iostream>
#include <map>
#include <vector>

int main(int argc, char* argv[]) {
    try {
        /*
         * runtime opt test
         *
        OptNode* head = new OptNode();
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
        std::cout << "Bad search: " << res << std::endl;
        std::cout << hashmap.size() << std::endl;



        delete head;
        */

        /*
         * duplicate flag test
         *
        FlagNode* head = new FlagNode();
        head->insert("--flag1", "-f");
        head->insert("--flag1", "-f");
        delete head; 
        */

        /*
         * bad flag test
         *
        FlagNode* head = new FlagNode();
        head->insert("-flag1", "--f");
        head->insert("--flag1", "-f");
        delete head; 
        */

        /*
         * runtime flag test
         *
        std::map<const char*, std::vector<const char*>> hashmap;
        int pos = 1;

        FlagNode* head = new FlagNode();
        head->insert("--flag1", "-f");
        head->insert("--flag2", "-d");
        bool res = head->parse(hashmap, pos, argc, argv);

        for (auto i : hashmap) {
            std::cout << i.first << ": ";
            for (auto j : i.second) {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "Bad search: " << res << std::endl;


        delete head; 
        */
        return 0;
    } catch (const char* error) {
        std::cout << error << std::endl;
    }
}
