#include <stdio.h>
#include "user.h"
#include "dynamic_array.h"
#include "hash.h"

int main() {
    char *test1 = "hosein";
    char *test2 = "hkhcode";
    int index1 = make_index(test1, 6, 10);
    int index2 = make_index(test2, 7, 10);
    printf("index1 is %d \n", index1);
    printf("index2 is %d \n", index2);
    return 0;
}