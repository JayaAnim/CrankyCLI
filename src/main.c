#include <stdio.h>
#include <stdlib.h>
#include "../include/HashMap.h"
#include "../include/HashNode.h"


int main(int argc, char* argv[]) {
    tHashMap* map = (tHashMap*)malloc(sizeof(tHashMap)); 
    tHashMap_init(map);
    int* x;
    int* y;
    int* z;
    x = (int*)malloc(sizeof(int));
    y = (int*)malloc(sizeof(int));
    z = (int*)malloc(sizeof(int));
    *x = 2;
    *y = 4;
    *z = 6;
    map->insert(map, "--x", x);
    map->insert(map, "--y", y);
    map->insert(map, "--z", z);
    int* new_x = map->search(map, "--x");
    printf("New x is: %d", *new_x);
    /*
    int* new_y = map->search(map, "--y");
    printf("New y is: %d", *new_y);
    int* new_z = map->search(map, "--z");
    printf("New z is: %d", *new_z);
    return 0;
    */
}
