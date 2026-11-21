#include <stdio.h>
#include "user.h"
#include "dynamic_array.h"
#include "hash.h"
user test_users[] = { 
    {1, 10, 2, 4, 4, "wd1", "qwer", "1234"},
    {2, 10, 2, 4, 4, "wd2", "qwer", "1234"},
    {3, 10, 2, 4, 4, "wd3", "qwer", "1234"},
    {4, 10, 2, 4, 4, "wd4", "qwer", "1234"},
    {5, 10, 2, 4, 4, "wd5", "qwer", "1234"},
    {6, 10, 2, 4, 4, "wd6", "qwer", "1234"},
    {7, 10, 2, 4, 4, "wd7", "qwer", "1234"},
    {8, 10, 2, 4, 4, "wd8", "qwer", "1234"},
    {9, 10, 2, 4, 4, "wd9", "qwer", "1234"},
    {10, 10, 2, 4, 4, "wd10", "qwer", "1234"},
    {11, 10, 2, 4, 4, "wd11", "qwer", "1234"},
    {12, 10, 2, 4, 4, "wd12", "qwer", "1234"},
    {13, 10, 2, 4, 4, "wd13", "qwer", "1234"},
    {14, 10, 2, 4, 4, "wd14", "qwer", "1234"},
    {15, 10, 2, 4, 4, "wd15", "qwer", "1234"},
    {16, 10, 2, 4, 4, "wd16", "qwer", "1234"},
    {17, 10, 2, 4, 4, "wd17", "qwer", "1234"},
    {18, 10, 2, 4, 4, "wd18", "qwer", "1234"},
    {19, 10, 2, 4, 4, "wd19", "qwer", "1234"},
    {20, 10, 2, 4, 4, "wd20", "qwer", "1234"}
};

int main(int argc, char *argv[]) {
    user users[] = {{1, 10, 2, 4, 4, "wd", "qwer", "1234"}, {2, 12, 2, 4, 4, "we", "qwer", "1234"}};
    dynamic_array *array_addr = init_dynamic_array(10, users, 2);
    user inserting_user = {1, 10, 3, 5, 5, "wd1", "qwer1", "12341"};
    insert_item(inserting_user, array_addr);
    user *test_item = find_item(inserting_user.id, inserting_user.name, inserting_user.name_length, array_addr);
    printf("Found user! id is %d \n", test_item->id);
    //printf("user inserted succesfully \n");
    //printf("arr pointer: %p", array_addr);
    //delete_item(users, array_addr);
    print_dynamic_array_items(array_addr);
    return 0;
}
