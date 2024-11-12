#include "get_next_line.h"
#include <stdio.h>

static char	*ft_strchr(const char *s, int c);
static char    *get_line(int fd, char **overflow, char *chunk);
static void cut_excess(char **line , char **overflow);



char *get_next_line(int fd)
{
    static char* overflow = NULL;
    char *chunk;
    char *line;
    
    chunk = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!chunk || BUFFER_SIZE <= 0 || fd < 0)
    {
        free (chunk);
        free (overflow);
        chunk = NULL;
        overflow = NULL;
        return (NULL);
    }
    line = get_line(fd, &overflow, chunk);
    free(chunk);
    if (!line)
    {
        free(overflow);
        overflow = NULL;
        return (NULL);
    }
    cut_excess(&line ,&overflow);
    if (!line)
        return (NULL);
    return(line);  
}

static char* get_line(int fd, char **overflow, char *chunk)
{
    char *temp;
    int text;

    text = 1;
    while (text)
    {
        text = read(fd,chunk, BUFFER_SIZE);
        if (text < 0)
            return (NULL);
        chunk[BUFFER_SIZE] = '\0';
        if (text == 0)
            break;
        if(!(*overflow))
            *overflow = ft_strdup("");
        temp = *overflow;
        *overflow = ft_strjoin(temp, chunk);
        free(temp);
        if(ft_strchr(*overflow, '\n'))
            break;
    }
    return(*overflow);
}

static void cut_excess(char **line , char **overflow)
{
    char    *temp;
    char    *space_position;
    int start;
    int len_after_space;

    start = 0;
    len_after_space = 0;
    space_position = ft_strchr(*overflow, '\n');
    if (!space_position)
    {
        *line = ft_strdup(*overflow);
        free(*overflow);
        *overflow = NULL;
        return ;
    }
    start = ft_strlen(*overflow);
    len_after_space = ft_strlen((space_position) + 1);
    start = start - len_after_space;
    temp = ft_strdup(*overflow);
    *overflow = ft_substr(temp, start, ft_strlen((space_position + 1)));
    *line = ft_substr(temp, 0 , start);
    free(temp);
}
static char	*ft_strchr(const char *s, int c)
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

/*int main()
{
    int fd;
    int i;
    char    *line;

    fd = open("text.txt", O_RDWR);
    for(i = 0; i < 5; i++)
    {
        line = get_next_line(fd);
        if (line){
            ft_putstr(line);
            if (line == NULL)
                printf("é null!\n");
            //free(line);
            //line = NULL;
        }
        write(1, "\n",1);
    }
    close(fd);
    return (0);
}*/