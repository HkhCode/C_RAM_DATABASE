#include <stdio.h>
#include <string.h>
#include "user.h"
#include "dynamic_array.h"
#include "hash.h"
user test_users[] = { 
    {1, 10, 3, 4, 4, "wd1", "qwer", "1234"},
    {2, 10, 3, 4, 4, "wd2", "qwer", "1234"},
    {3, 10, 3, 4, 4, "wd3", "qwer", "1234"},
    {4, 10, 3, 4, 4, "wd4", "qwer", "1234"},
    {5, 10, 3, 4, 4, "wd5", "qwer", "1234"},
    {6, 10, 3, 4, 4, "wd6", "qwer", "1234"},
    {7, 10, 3, 4, 4, "wd7", "qwer", "1234"},
    {8, 10, 3, 4, 4, "wd8", "qwer", "1234"},
    {9, 10, 3, 4, 4, "wd9", "qwer", "1234"},
    {10, 10, 4, 4, 4, "wd10", "qwer", "1234"},
    {11, 10, 4, 4, 4, "wd11", "qwer", "1234"},
    {12, 10, 4, 4, 4, "wd12", "qwer", "1234"},
    {13, 10, 4, 4, 4, "wd13", "qwer", "1234"},
    {14, 10, 4, 4, 4, "wd14", "qwer", "1234"},
    {15, 10, 4, 4, 4, "wd15", "qwer", "1234"},
    {16, 10, 4, 4, 4, "wd16", "qwer", "1234"},
    {17, 10, 4, 4, 4, "wd17", "qwer", "1234"},
    {18, 10, 4, 4, 4, "wd18", "qwer", "1234"},
    {19, 10, 4, 4, 4, "wd19", "qwer", "1234"},
    {20, 10, 4, 4, 4, "wd20", "qwer", "1234"}
};

int main(int argc, char *argv[]) {
    dynamic_array *test_array = init_dynamic_array(5, &test_users[0], 1);
    for (int i = 1; i < sizeof(test_users) / sizeof(test_users[0]); i++) {
        insert_item(test_users[i], test_array);
    }
    

    delete_item(&test_users[3], test_array);
    delete_item(&test_users[12], test_array);
    delete_item(&test_users[8], test_array);
    user *new_test_users_16 = malloc(sizeof(user));
    new_test_users_16->id = 16;
    new_test_users_16->age = 12;
    new_test_users_16->name_length = 12;
    new_test_users_16->email_length = 4;
    new_test_users_16->password_length = 4;
    strcpy(new_test_users_16->name, "wd16_updated");
    strcpy(new_test_users_16->password, "1234");
    strcpy(new_test_users_16->email, "qwer");


    update_item(&test_users[16], new_test_users_16, test_array);
    free(new_test_users_16);
    remove_dynamic_array(test_array);
    return 0;
}
