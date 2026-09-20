#ifndef BSQ
# define BSQ

#include <stdio.h>
#include <stdlib.h>

typedef struct s_bsq
{
    int height;
    int width;
    char empty;
    char obstacle;
    char full;
    char **map;
} t_bsq;

#endif