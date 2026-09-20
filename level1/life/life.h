#ifndef LIFE_H
# define LIFE_H

# include <stdio.h>
# include <stdbool.h>
#include <stdlib.h>
# include <unistd.h>

typedef struct s_game
{
    int width;
    int height;
    int iteration;
    char **board;
} t_game;

#endif