#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "dynamic_array.h"
#include "user.h"
#include "hash.h"

user *find_item(int userid, char *name, int name_length, dynamic_array *target_array) {
    int item_index = make_index(name, name_length, target_array->size);
    if (target_array->list[item_index].value != NULL) {
        if (target_array->list[item_index].value->id == userid) {
            return target_array->list[item_index].value;
        }
        else {
            linked_list_node *current = &target_array->list[item_index];
            while (current->next != NULL && current->value->id != userid) {
                current = current->next;
            }
            if (current != NULL) {
                return current->value;
            }
        }
    }
    return;   
}

dynamic_array *init_dynamic_array(int size, user *items, int items_count)
{
    if (items == NULL)
    {
        return;
    }

    dynamic_array *dyn_array = calloc(1, sizeof(dynamic_array));
    dyn_array->size = size;
    linked_list_node *initiated_dyn_arr_users = calloc(size, sizeof(linked_list_node));
    int alocated_slots = 0;
    dyn_array->list = initiated_dyn_arr_users;
    for (int i = 0; i < items_count; i++) {
        int item_index = make_index(items[i].name, items[i].name_length, size);
        //linked_list_node new_node = {true, &items[i], NULL};
        linked_list_node *new_node = malloc(sizeof(linked_list_node));
        new_node->filled = true;
        new_node->next = NULL;
        user *cur_user = malloc(sizeof(user));
        cur_user->id = items[i].id;
        cur_user->password_length = items[i].password_length;
        cur_user->email_length = items[i].email_length;
        cur_user->email_length = items[i].email_length;
        cur_user->age = items[i].age;
        strcpy(cur_user->email, items[i].email);
        strcpy(cur_user->password, items[i].password);
        strcpy(cur_user->name, items[i].name);
        new_node->value = cur_user;
        //free(cur_user);
        if (!dyn_array->list[item_index].filled) {
            dyn_array->list[item_index] = *new_node;
            alocated_slots++;
            free(new_node);
        } 
        else { 
            linked_list_node *old_head = malloc(sizeof(linked_list_node));

            old_head->filled = dyn_array->list[item_index].filled;
            old_head->next = dyn_array->list[item_index].next;
            old_head->value = dyn_array->list[item_index].value;

            new_node->next = old_head;
            dyn_array->list[item_index] = *new_node;
            free(new_node);
        }
    }
    dyn_array->alocated = alocated_slots;
    return dyn_array;
}

// inserts one user
void *insert_item(user new_user, dynamic_array *target_array)
{
    printf("Called insert \n");
    printf("==================================================== \n");
    int target_index = make_index(new_user.name, new_user.name_length, target_array->size);
    user *new_user_copy = malloc(sizeof(user));
    new_user_copy->id = new_user.id;
    new_user_copy->password_length = new_user.password_length;
    new_user_copy->email_length = new_user.email_length;
    new_user_copy->email_length = new_user.email_length;
    new_user_copy->age = new_user.age;
    strcpy(new_user_copy->email, new_user.email);
    strcpy(new_user_copy->password, new_user.password);
    strcpy(new_user_copy->name, new_user.name);
    linked_list_node new_node = {true, new_user_copy, NULL};
    if (target_array->list[target_index].filled) {
        printf("inserting index : %d\n", target_index);
        linked_list_node *old_head = malloc(sizeof(linked_list_node));
        old_head->filled = true;
        old_head->next = target_array->list[target_index].next;
        old_head->value = target_array->list[target_index].value;
        new_node.next = old_head;
        target_array->list[target_index] = new_node;
    }
    else { 
        printf("inserting index at else block : %d\n", target_index);
        target_array->list[target_index] = new_node;
        target_array->alocated = target_array->alocated + 1;
    }
    return target_array;

}

void delete_item(user *target_user, dynamic_array *target_array) {
    int target_index = make_index(target_user->name, target_user->name_length, target_array->size);
    if (target_array->list[target_index].filled) {
        linked_list_node *head = &target_array->list[target_index];
        if (head->value->id == target_user->id) {
            if (head->next != NULL)  {
                linked_list_node *node_to_delete = head->next;
                free(head->value);
                head->value = node_to_delete->value;
                head->next = node_to_delete->next;
                free(node_to_delete); 
            }
            else {
                linked_list_node empty_head;
                empty_head.filled = false;
                empty_head.next = NULL;
                //empty_head.value = calloc(1, sizeof(user));
                target_array->list[target_index] = empty_head;
            }
            printf("item with id: %d deleted succesfully \n", target_user->id);
        }
        else {
            linked_list_node *current = head->next;
            //printf("current id is %d\n", current->next->value->id);
            while(current != NULL) {
                if (current->next != NULL) {
                    if (current->next->value->id == target_user->id)
                        break;
                }
                current = current->next;
            }

            if (current != NULL) {
                if (current->next != NULL) {
                    linked_list_node *delete_node = current->next;
                    if (delete_node->next != NULL) {
                        current->next = delete_node->next;
                    }
                    else {
                        current->next = NULL;
                    }
                    free(delete_node->value);
                    free(delete_node);
                }

                printf("item with id: %d deleted succesfully \n", target_user->id);           
            }
        }     
    }
    else { 
        printf("item not found, wrong id or index! \n");
    }
    
}

void *update_item(user *target_user, user *new_user, dynamic_array *target_array) {
    delete_item(target_user, target_array);
    insert_item(*new_user, target_array);
}

void remove_dynamic_array(dynamic_array *target_array) {
    for (int i = 0; i < target_array->size; i++) {
        if (target_array->list[i].filled) {
            linked_list_node *current;
            current = &target_array->list[i];
            bool is_first = true;
            while (current != NULL) {
                if (current->value != NULL) {
                    free(current->value);
                }

                linked_list_node *next_node = current->next;
                if (current != &target_array->list[i]) {
                    free(current); 
                }

                current = next_node;
            }
        }
    }
    free(target_array->list);
    free(target_array);
}

dynamic_array *resize_dynamic_array(dynamic_array *target_array, int new_size) {
    if (new_size < target_array->alocated) {
        printf("Shriking array is not possible, alocated item's count is more than new size! \n");
        return;
    }
    target_array->size = new_size;
    linked_list_node *new_list = realloc(target_array->list, sizeof(linked_list_node) * new_size);
    if (new_list == NULL) {
        printf("Resize failed! not enough memory. \n");
        return;
    }
    target_array->list = new_list;
    return target_array;
}

void print_dynamic_array_items(dynamic_array *target_array) {
    for (int i = 0; i < target_array->size; i++) {
        if (target_array->list[i].filled) {
            printf("at index %d: \n", i);
            printf("user id :%d \n", target_array->list[i].value->id);
            printf("user name :%s \n", target_array->list[i].value->name);
            linked_list_node *current = target_array->list[i].next;
            while (current != NULL) {
                printf("next node: \n");
                if (current->value != NULL) {
                    printf("\t user id : %d\n", current->value->id);
                    printf("\t user name : %s\n", current->value->name);
                }
                if (current->next == NULL) {
                    break; // just added for more care XD
                }
                current = current->next;
            }
            printf("\n");
        }
        else {
            printf("empty index %d\n", i);
        }

    }
}