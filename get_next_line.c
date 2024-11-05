#include "get_next_line.h"

char *get_next_line(int fd)
{
	char    letter;
	char    buffer[400];

    read(fd, buffer, 300);
    ft_putstr_fd(buffer, 1);
	close(fd);
}
int main()
{
    int fd;
    
    fd = open("text.txt", O_RDWR);
    get_next_line(fd);
    return (0);
}
