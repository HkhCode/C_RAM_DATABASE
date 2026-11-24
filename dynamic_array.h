#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <stdbool.h>
#include "user.h"

#define ADD_ON_REALOC 5

struct chain_node { 
    bool filled;
    user *value;
    struct chain_node *next;
};

typedef struct chain_node linked_list_node;

typedef struct {
    int size;
    int free;
    int alocated;
    linked_list_node *list;
} dynamic_array;

user *find_item(int userid, char *name, int name_length, dynamic_array *target_array);

dynamic_array *init_dynamic_array(int size, user *items, int items_count);

void *insert_item(user user, dynamic_array *target_array);

void delete_item(user *target_user, dynamic_array *target_array);

void *update_item(user *target_user, user *new_user, dynamic_array *target_array);

void print_dynamic_array_items(dynamic_array *target_array);

void remove_dynamic_array(dynamic_array *target_array);

dynamic_array *resize_dynamic_array(dynamic_array *target_array, int new_size);

#endif