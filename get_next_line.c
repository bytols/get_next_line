#include "get_next_line.h"

char *get_next_line(int fd)
{
	char    letter;
	char    buffer[4];
    int k;
    static char* next_line;

    k = 3;
    read(fd, buffer, k);
    buffer[k] = '\0';
    next_line = ft_putstr(buffer);
    return(next_line);  
}

int main()
{
    int fd;
    int i;

    fd = open("text.txt", O_RDWR);
    for(i = 0; i < 2; i++)
    {
        get_next_line(fd);
    }
    close(fd);
    return (0);
}
