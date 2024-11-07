#include "get_next_line.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c);
char* get_line(int fd, char *overflow);


char *get_next_line(int fd)
{
    static char* overflow = NULL;
    char *line;
    
    line = get_line(fd, overflow);
    return(line);  
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	ptr = (char *)s;
	i = 0;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == (char)c)
			return (&ptr[i]);
		i++;
	}
	if (c == '\0' && ptr[i] == '\0')
		return (&ptr[i]);
	else
		return (NULL);
}

char* get_line(int fd, char *overflow)
{
    char    *chunk;
    char    *line;
    char    *tab_position;
    int     text;

    chunk = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if(chunk == NULL)
        return (NULL);
    chunk[BUFFER_SIZE] = '\0';
    printf("aqui: %s\n", chunk);
    if (overflow != NULL)
        line = ft_strjoin(overflow, chunk);
    free(overflow);
    while (text)
    {
        text = read(fd, chunk, BUFFER_SIZE);
        line = ft_strjoin(line, chunk);
        tab_position = ft_strchr(line, '\n');
        //printf("tab position: %s\n", tab_position);
        if(tab_position)
        {
            //printf("aqui está a line %s\n" , line);
            break;
        }
    }
    overflow = ft_strdup((tab_position + 1));
    //printf("overflow %s\n" , overflow);
    return(line);
}

int main()
{
    int fd;
    int i;
    char    *line;

    fd = open("text.txt", O_RDWR);
    for(i = 0; i < 10; i++)
    {
        line = get_next_line(fd);
        //printf("retornei: %s\n" , line);
        ft_putstr(line);
        //free(line);
    }
    close(fd);
    return (0);
}
