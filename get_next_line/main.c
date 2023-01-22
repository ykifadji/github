#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int ac, char **av)
{
    int     i;
    int     fd;
    char    *str;
    if (ac != 2)
    {
        printf("Wrong number of arguments !\n");
        return (-1);
    }
    i = 0;
    fd = open("file.txt", O_RDONLY);
    if (fd == -1)
        printf("open() failed\n");
    while (i < atoi(av[1]))
    {
        str = get_next_line(fd);
        printf("\033[0;32m%s\033[0m", str);
        i++;
    }
    close(fd);
    free (str);
    //system("leaks a.out");
    return (0);
}