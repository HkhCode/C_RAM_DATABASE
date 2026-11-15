#ifndef USER_H
#define USER_H
#include <stdlib.h>

typedef struct {
    uint id;
    int age;
    int name_length;
    int email_length;
    int password_length;
    char name[32];
    char email[32];
    char password[32];

} user;

#endif