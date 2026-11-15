#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>

#include "user.h"

int mix(int h);
int make_index(char *s, int s_size, int array_size);
int hash(char *s, int s_size);

#endif