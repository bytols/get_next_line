#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void ft_putstr(char *str)
{
    while (str && *str != '\r') // checkar se isso também é assim na distro do campus
    {
        write(1, str, 1);
        str++;
    }
    
}
int main()
{
	char    letter;
	char    buffer[400];
	int     fd;

	fd = open("text.txt", O_RDWR);
    read(fd, buffer, 300);
    //printf("%s" , buffer);
    ft_putstr(buffer);
	close(fd);
}

//checkar se o fd é anceitavel
// checaar se o arquivo tem algo para ser lido
// tem que retornar null caso algo dê errado
