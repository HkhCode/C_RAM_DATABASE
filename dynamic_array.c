#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"
#include "user.h"

dynamic_array *init_dynamic_array(int size, user *items, int items_count)
{
    if (items == NULL || items_count > size)
    {
        return;
    }

    dynamic_array *dyn_array = malloc(sizeof(dynamic_array));
    dyn_array->free = size - items_count;
    dyn_array->users = items;
    dyn_array->size = size;
    dyn_array->alocated = items_count;
    return dyn_array;
}

void *insert_item(user *new_user, dynamic_array *target_array, int items_count)
{

    if (target_array == NULL || new_user == NULL || items_count == 0) {
        return;
    }
    int final_alocated = target_array->alocated + items_count;
    target_array->alocated = final_alocated;
    
    if (target_array->size < final_alocated) 
    {
        target_array->size = final_alocated + ADD_ON_REALOC;
        user *temp = realloc(target_array->users, target_array->size * sizeof(user));
        if (temp == NULL) {
            return;
        }
        target_array->users = temp;
    }
    if (items_count == 1){
        target_array->users[target_array->alocated] = *new_user;
    }
    else {
        for (int i = 0; i < items_count; i++) {
            target_array->users[target_array->alocated] = new_user[i];
            target_array->alocated += 1;
        }
    }
    //user *new_users = realloc(target_array->users, target_array->size * sizeof(user));
}

dynamic_array *delete_item(int userid, dynamic_array *target_array) {
    
}