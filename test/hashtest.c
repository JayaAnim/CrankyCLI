/*
 * 
 * Tested for leaks, no leaks found
 *
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
    int* new_y = map->search(map, "--y");
    int* new_z = map->search(map, "--z");
    map->uninit(map);
    free(map);
*/
