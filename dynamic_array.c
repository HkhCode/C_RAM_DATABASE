#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_array.h"
#include "user.h"
#include "hash.h"

dynamic_array *init_dynamic_array(int size, user *items, int items_count)
{
    if (items == NULL || items_count > size)
    {
        return;
    }

    dynamic_array *dyn_array = calloc(1, sizeof(dynamic_array));
    dyn_array->size = size;
    linked_list_node initiated_dyn_arr_users[size];
    int alocated_slots = 0;
    dyn_array->list = initiated_dyn_arr_users;
    for (int i = 0; i < items_count; i++) {
        int item_index = make_index(items[i].name, items[i].name_length, size);
        linked_list_node new_node = {true, &items[i], NULL};
        if (!dyn_array->list[item_index].filled) {
            dyn_array->list[item_index] = new_node;
            alocated_slots++;
        } 
        else { 
            linked_list_node current = dyn_array->list[item_index];
            new_node.next = &current;
            dyn_array->list[item_index].next = &new_node;
        }
    }
    dyn_array->alocated = alocated_slots;
    return dyn_array;
}

// inserts one user
void *insert_item(user *new_user, dynamic_array *target_array)
{
    if (new_user == NULL || 1 > (target_array->size - target_array->alocated))
    {
        printf("update array size to a larger number or pass a proper user");
        return;
    }

    int target_index = make_index(new_user->name, new_user->name_length, target_array->size);
    linked_list_node new_node = {true, new_user, NULL};
    if (target_array->list[target_index].filled) {
        linked_list_node current = target_array->list[target_index];
        new_node.next = &current;
        target_array->list[target_index] = new_node;
    }
    else { 
        target_array->list[target_index] = new_node;
        target_array->alocated++;
    }
    return target_array;

}

dynamic_array *delete_item(int userid, dynamic_array *target_array) {
    
}