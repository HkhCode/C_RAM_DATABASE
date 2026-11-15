#include <stdio.h>
#include "user.h"
#include "dynamic_array.h"
#include "hash.h"

int main() {
    user users[] = {{1, 10, 2, 4, 4, "wd", "qwer", "1234"}, {2, 12, 2, 4, 4, "we", "qwer", "1234"}};
    init_dynamic_array(10, users, 2);
    return 0;
}