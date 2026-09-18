#include "life.h"

void free_board(t_game *game)
{
    if (game->board)
    {
        for (int x = 0; x < game->height; x++)
        {
            if(game->board[x])
                free(game->board[x]);
        }
        free(game->board);
    }
}
void print_board(t_game *game)
{
    for (int x = 0; x < game->height; x++)
    {
        for (int y = 0; y < game->width; y++)
            putchar(game->board[x][y]);
        putchar('\n');
    }
}

bool init_game(t_game *game, char **av)
{
    game->width = atoi(av[1]);
    game->height = atoi(av[2]);
    game->iteration = atoi(av[3]);
    game->board = (char **)malloc((game->height + 1) * sizeof(char *));
    if (!game->board)
        return false;
    for (int i = 0; i < game->height; i++)
    {
        game->board[i] = (char *)malloc((game->width + 1) * sizeof(char));
        if (!game->board)
        {
            free_board(game);
            return false;
        }
        for (int j = 0; j < game->width; j++)
            game->board[i][j] = '_';
        game->board[i][game->width] = 0;
    }
    game->board[game->height] = 0;
    return true;
}

void fill_board(t_game *game)
{
    char buffer;
    int draw = 0;
    int x = 0;
    int y = 0;

    while (read(STDIN_FILENO, &buffer, 1))
    {
        if (buffer == 'w')
        {
            if (y > 0)
            {
                y--;
                if (draw)
                    game->board[y][x] = 'o';
            }
        }
        else if (buffer == 'a')
        {
            if (x > 0)
            {
                x--;
                if (draw)
                    game->board[y][x] = 'o';
            }
        }
        else if (buffer == 's')
        {
            if (y < game->height - 1)
            {
                y++;
                if (draw)
                    game->board[y][x] = 'o';
            }
        }
        else if (buffer == 'd')
        {
            if (x < game->width - 1)
            {
                x++;
                if (draw)
                    game->board[y][x] = 'o';
            }
        }
        else if (buffer == 'x')
        {
            if (draw == 1)
                draw = 0;
            else
            {
                draw = 1;
                if (x < game->width && y < game->height && x >= 0 && y >= 0)
                    game->board[y][x] = 'o';
            }
        }
    }
}

int count_neighbors(t_game *game, int x, int y, char **tab)
{
    int count = 0;
    for (int i = x - 1; i <= x + 1; i++)
    {
        for (int j = y - 1; j <= y + 1; j++)
        {
            if (i == x && j == y)
                continue;
            if (i >= 0 && i < game->width && j >= 0 && j < game->height)
            {
                if (tab[i][j] == 'o')
                {
                    count++;
                }
            }
        }
    }
    return (count);
}

char    **dupli_tab(t_game *game)
{
    char **tmp;
    tmp = (char **)malloc((game->height + 1) * sizeof(char *));
    if (!tmp)
        return false;
    for (int i = 0; i < game->height; i++)
    {
        tmp[i] = (char *)malloc((game->width + 1) * sizeof(char));
        if (!tmp)
        {
            free_board(game);
            return false;
        }
        for (int j = 0; j < game->width; j++)
            tmp[i][j] = game->board[i][j];
        tmp[i][game->width] = 0;
    }
    return (tmp);
}

void free_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

void play_game(t_game *game)
{
    int count = 0;
    char **tmp = dupli_tab(game);

    for (int x = 0; x < game->height; x++)
    {
        for (int y = 0; y < game->width; y++)
        {
            count = count_neighbors(game, x, y, tmp);
            if (game->board[x][y] == 'o')
            {
                if (count != 2 && count != 3)
                    game->board[x][y] = '_';
            }
            else
            {
                if (count == 3)
                    game->board[x][y] = 'o';
            }
        }
    }
    free_tab(tmp);
}

int main (int ac, char **av)
{
    t_game game;

    if (ac != 4)
        return 1;
    if (!init_game(&game, av))
        return 1;
    fill_board(&game);
    for (int i = 0; i < game.iteration; i++)
        play_game(&game);
    print_board(&game);
    free_board(&game);
    return 0;
}