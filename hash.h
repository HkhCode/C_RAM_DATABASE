#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>

#include "user.h"

struct ChainNode { 
    user *value;
    struct ChainNode *next;
};

//typedef ChainNode ChainNode;

int find_index(char *username, int arraySize);
user *find_user(char *username, uint id, int arraySize);
int mix(int h);
int make_index(char *s, int s_size, int array_size);
int hash(char *s, int s_size);

#endif