#include <stdio.h>
#include "user.h"
#include "dynamic_array.h"

int main() {
    user test_users[] = {{1, 18, "hosein", "test@example.com", "12345678"}};
    dynamic_array *arr = init_dynamic_array(10, &test_users, 1);
    printf("dynamic array initiated succesfully!");
    return 0;
}