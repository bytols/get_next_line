#include "get_next_line.h"

char *get_next_line(int fd)
{
	char    *letter;
    int k;
    static char* overflow;

    k = 3;
    read(fd, buffer, k);
    next_line = ft_putstr(buffer);
    return(next_line);  
}

void get_line(int fd, overflow)
{
    char    *chunk;
    char    *line
    int     text;

    chunk = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    chunk[BUFFER_SIZE] = '\0';

    while (text)
    {
        text = read(fd, chunk, BUFFER_SIZE);
        ft_strjoin(line, chunk);
        
        if(/*line não tiver encontrado ainda o \n*/)
            break;
        ft_putstr(line);
    }
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
