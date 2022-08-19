#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int TABLE_SIZE = 16;

struct member {
    int key;
    int value;
};

int hash(int val) {
    return val % TABLE_SIZE;
}

int insert(struct member **space, int *space_size, int key, int val) {
    int position;
    position = hash(key);
    int list_size = space_size[position];
    struct member * list = space[position];
    for (int i = 0; i < list_size; i++) {
        if (list[i].key <= 0) {
            struct member* m = malloc(sizeof(struct member));
            m->key = key;
            m->value = val;
            list[i] = *m;
        }
    }

    // space[hash(key)] = val;
    return 0;
}

int retrieve(struct member **space, int key) {
    
    
    return space[hash(key)][0].value;
}

struct member ** init() {
    struct member ** space;
    space = (struct member **) malloc(TABLE_SIZE);
    return space;
}

int * init_list(struct member **space) {
    int * space_size;
    space_size = (int *) malloc(TABLE_SIZE);
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct member* list;
        list = (struct member *) malloc(sizeof(struct member));
        list[0].key = -1;
        list[0].value = -1;
        list[1].key = -1;
        list[1].value = -1;
        space[i] = list;
        space_size[i] = 2;
    }
    return space_size;
}

// int * list_append() {

// }

int main() {
    // IDEA: each key should correspond to a memory address. that memory
    // address will correspond with a list
    // that list with auto resize as it grows

    // int *space;
    // space = (int *) malloc(TABLE_SIZE);
    // space[3] = 11;
    // strcpy(space, "tutorialspoint");
    struct member ** space = init();
    int * space_size = init_list(space);
    insert(space, space_size, 110, 1);
    // insert(space, 1110, 2);

    // printf("%c", space[0]);
    printf("hello world!");
    // for (int i = 0; i < TABLE_SIZE; i++) {
    //     printf("%d", space[i]);
    // }

    printf("\n\n%d", retrieve(space, 110));
    
    return 0;
}