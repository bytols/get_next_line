#include "get_next_line.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c);
char* get_line(int fd, char **overflow);


char *get_next_line(int fd)
{
    static char* overflow = NULL;
    char *line;
    
    line = get_line(fd, &overflow);
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

char    *cut_overflow(char *overflow, char **line)
{
    int len_overflow;
    int len_line;
    int i;
    char    *new_line;

    i = 0;
    len_overflow = ft_strlen(overflow);
    len_line = ft_strlen(line);    
    len_line = (len_line - len_overflow + 1);
    new_line = malloc(sizeof(char) *(len_line));
    new_line[len_line] = '\0';
    while (*line[i] != '\n' && *line[i])
    {
        new_line[i] = *line[i];
        i++;
        
    }
    free(line);
    return(line);
    
}

char* get_line(int fd, char **overflow)
{
    char    *chunk;
    char    *line;
    char    *tab_position;
    int     text;

    text = 1;
    chunk = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if(chunk == NULL)
        return (NULL);
    chunk[BUFFER_SIZE] = '\0';
    if (*overflow != NULL)
        line = ft_strjoin(*overflow, chunk);
    free(*overflow);
    while (text)
    {
        text = read(fd, chunk, BUFFER_SIZE);
        line = ft_strjoin(line, chunk);
        tab_position = ft_strchr(line, '\n');
        if(tab_position)
            break;
    }
    *overflow = ft_strdup((tab_position + 1));
    line = cut_overflow(*overflow, &line);
    //printf("\noverflow %s\n" , *overflow);
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
        write(1, "\n",1);
        ft_putstr(line);
        write(1, "\n",1);
    }
    close(fd);
    return (0);
}



