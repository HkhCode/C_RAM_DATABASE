#include <stdio.h>
#include "user.h"
#include "dynamic_array.h"
#include "hash.h"

int main() {
    user users[] = {{1, 10, 2, 4, 4, "wd", "qwer", "1234"}, {2, 12, 2, 4, 4, "we", "qwer", "1234"}};
    dynamic_array *array_addr = init_dynamic_array(10, users, 2);
    user inserting_user = {1, 10, 3, 5, 5, "wd1", "qwer1", "12341"};
    insert_item(&inserting_user, array_addr);
    printf("user inserted succesfully \n");
    return 0;
}