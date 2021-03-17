#include "../includes/cub3d.h"

char *ft_realloc(char *line, int *i)
{
    int l = 0;
    char *str;

    if (!(str = malloc(*i * 2)))
        return (NULL);
    *i *= 2;
    while (line && line[l])
    {
        str[l] = line[l];
        l++;
    }
    while(l < *i)
    {
        str[l] = 0;
        l++;
    }
    free(line);
    return(str);
}

int get_next_line(char **line, int fd)
{
    int r = 1;
    int i = -1;
    int malloc_size = 50;

    if (!line)
        return(-1);
    *line = NULL;
    if (!(*line = ft_realloc(*line, &malloc_size)))
        return (-1);
    while ((r = read(fd, &(*line)[++i], 1)))
    {
        if ((*line)[i] == 10)
            break ;
        if (i == malloc_size - 2)
            if (!(*line = ft_realloc(*line, &malloc_size)))
                return (-1);
    }
    (*line)[i] = 0;
    return (r);
}
