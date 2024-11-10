#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char *ft_putstr(char *str)
{
    while (str && *str != '\r') // checkar se isso também é assim na distro do campus
    {
        write(1, str, 1);
        str++;
    }   
    return(str);  
}

int main()
{
	char    letter;
	char    buffer[BUFFER_SIZE];
	int     fd;
    int num;
    int i;

	fd = open("text.txt", O_RDWR);
    for (i = 0; i < 6; i++)
    {
        num = read(fd, buffer, BUFFER_SIZE);
        printf("%d\n" , num);
        ft_putstr(buffer);
    }
	close(fd);
}

//checkar se o fd é anceitavel
// checaar se o arquivo tem algo para ser lido
// tem que retornar null caso algo dê errado

