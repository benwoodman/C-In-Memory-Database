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
    for (int i = 0; i < list_size * sizeof(struct member); i += sizeof(struct member)) {
        if (list[i].key <= 0) {
            struct member* m = malloc(sizeof(struct member));
            m->key = key;
            m->value = val;
            list[i] = *m;
            break;
        }
    }

    // space[hash(key)] = val;
    return 0;
}

int retrieve(struct member **space, int *space_size, int key) {
    int hashed_value;
    hashed_value = hash(key);
    for (int i = 0; i < space_size[hashed_value] * sizeof(struct member); i += sizeof(struct member)) {
        if (space[hashed_value][i].key == key) {
            return space[hashed_value][i].value;
        }
    }
    
    return -1;
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
        for (int i = 0; i < sizeof(struct member) * 2; i += sizeof(struct member)) {
            list[i].key = -1;
            list[i].value = -1;
        }
        space[i] = list;
        space_size[i] = 2;
    }
    return space_size;
}



int main() {
    // IDEA: each key should correspond to a memory address. that memory
    // address will correspond with a list
    // that list with auto resize as it grows

    struct member ** space = init();
    int * space_size = init_list(space);

    // insert two keys into the database

    insert(space, space_size, 110, 1);
    insert(space, space_size, 126, 2);

    // retrieve two values from the database from previous inserts

    printf("\n\n%d", retrieve(space, space_size, 110));
    printf("\n\n%d", retrieve(space, space_size, 126));
    
    return 0;
}