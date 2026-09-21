#include "bsq.h"

void free_map(char **map)
{
    int i = 0;
    if (map)
    {
        while (map[i])
        {
            free(map[i]);
            i++;
        }
    }
    free(map);
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
    fprintf(stdout, "\n");
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
    bsq->width = 0;
    return 1;
}

int load_map(FILE *file, t_bsq *bsq)
{
    char *line = NULL;
    size_t read, len;

    bsq->map = malloc((bsq->height + 1) * (sizeof(char *)));
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
        bsq->map[i] = malloc((read + 1) * sizeof(char));
        if (read <= 0)
        {
            free(line);
            free_map(bsq->map);
            return 0;
        }
        for (int j = 0; j < read; j++)
            bsq->map[i][j] = line[j];
        bsq->map[i][read] = '\0';
    }
    bsq->map[bsq->height] = '\0';
    free(line);
    return 1;
}

int check_map(t_bsq *bsq)
{
    int i = 0;
    while (bsq->map[0][i] != '\n' && bsq->map[0][i] != '\0')
    {
        bsq->width++;
        i++;
    }
    for (int j = 1; j < bsq->height; j++)
    {
        int len = 0;
        while (bsq->map[j][len] != '\n' && bsq->map[j][len] != '\0')
        {
            if (bsq->map[j][len] != bsq->empty || bsq->map[j][len] != bsq->obstacle)
                len++;
        }
        if (bsq->width != len)
            return 0;
    }
    if (bsq->width < 0)
        return 0;
    return 1;
}

int solver(t_bsq *bsq)
{
    char **tmp;
    tmp = malloc((bsq->height + 1) * (sizeof(char *)));
    if (!tmp)
        return 0;
    for (int i = 0; i < bsq->height; i++)
    {
        for (int j = 0; i < bsq->width; j++)
        tmp[i] = malloc((bsq->width + 1) * sizeof(char));
        if (!tmp[i])
        {
            free_map(tmp);
            return 0;
        }
        tmp[i][bsq->width] = '\0';
    }
    tmp[bsq->height] = '\0';
}

int bsq(FILE *file)
{
    t_bsq bsq;
    if (!load_first_line(file, &bsq))
        return 0;
    if (!load_map(file, &bsq))
        return 0;
    if (!check_map(&bsq))
    {
        free_map(bsq.map);
        return 0;
    }
    
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