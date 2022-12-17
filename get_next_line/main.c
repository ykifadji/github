#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void	ft_putstr(char *str)
{
	while (*str)
		write(1, &*str++, 1);
}

int main(void)
{
    int     fd;
    char    *buf;
    fd = open("file.txt", O_RDONLY);
    if (fd == -1)
        write(1, "open() failed\n", 15);
    buf = get_next_line(fd);
    ft_putstr(buf);
    if (close(fd) == -1)
        write(1, "close() failed\n", 16);
    return (0);
}