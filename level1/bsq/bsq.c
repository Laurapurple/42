#include "bsq.h"

void free_map(t_bsq *bsq)
{
    if (bsq->map)
    {
        for (int i = 0; i < bsq->height + 1 ; i++)
        {
            if (bsq->map[i])
                free(bsq->map[i]);
        }
    }
    free(bsq->map);
}

int ft_isprint(char c)
{
    if (c >= 32 || c <= 126)
        return 1;
    return 0;
}

void print_map(t_bsq *bsq)
{
    for (int i = 0; i < bsq->height; i++)
        fprintf(stdout, bsq->map[i]);
}

int load_first_line(FILE *file, t_bsq *bsq)
{
    int res = fscanf(file, "%i %c %c %c", &(bsq->height), &(bsq->empty), &(bsq->obstacle), &(bsq->full));
    if (res != 4)
        return 0;
    if (bsq->height <= 0)
        return 0;
    if (bsq->empty == bsq->full || bsq->empty == bsq->obstacle || bsq->full == bsq->obstacle)
        return 0;
    if (!ft_isprint(bsq->empty) || !ft_isprint(bsq->full) || !ft_isprint(bsq->obstacle))
        return 0;
    return 1;
}

int load_map(FILE *file, t_bsq *bsq)
{
    char *line = NULL;
    size_t read, len;

    bsq->map = (char**)malloc((bsq->height + 1) * (sizeof(char *)));
    if (!bsq->map)
        return 0;

    read = getline(&line, &len, file);
    if (read <= 0)
    {
        free(line);
        return 0;
    }

    for (int i = 0; i < bsq->height; i++)
    {
        int read = getline(&line, &len, file);
        bsq->map[i] = (char *)malloc((read + 1) * sizeof(char));
        if (read <= 0)
        {
            free(line);
            free_map(bsq);
            return 0;
        }
        for (int j = 0; j < read; j++)
            bsq->map[i][j] = line[j];
        bsq->map[i][read] = 0;
    }
    bsq->map[bsq->height] = 0;
    free(line);
    return 1;
}

int bsq(FILE *file)
{
    t_bsq bsq;
    if (!load_first_line(file, &bsq))
        return 0;
    if (!load_map(file, &bsq))
        return 0;
    if (!check_map(&bsq));
        return 0;
    print_map(&bsq);
    free_map(&bsq);
    return 1;
}

int open_file(char *input)
{
    FILE *file = fopen(input, "r");
    if (!file)
        return 0;
    if (bsq(file))
    {
        fclose(file);
        return 1;
    }
    else
    {
        fclose(file);
        return 0;
    }
}

int main (int ac, char **av)
{
    if (ac == 1)
    {
        if (!bsq(stdin))
            fprintf(stderr, "map error\n");
    }
    else
    {
        for (int i = 1; i < ac; i++)
        {
            if (!open_file(av[i]))
                fprintf(stderr, "map error\n");
            if (i < ac - 1)
                fprintf(stdout, "\n");
        }
    }
}