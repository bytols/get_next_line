#include "get_next_line.h"
#include <stdio.h>

char* get_line(int fd, char **overflow, int text);


// checkar buffersize = 0! :)
char *get_next_line(int fd)
{
    static char* overflow = NULL;
    char *line;
    int text;
    
    text = 1;
    line = get_line(fd, &overflow, text);
    return(line);  
}


char    *cut_overflow(char *overflow, char **line)
{
    int len_overflow;
    int len_line;
    int i;
    char    *new_line;

    i = 0;
    if (overflow != NULL)
        len_overflow = ft_strlen(overflow);
    else
        len_overflow = 0;
    len_line = ft_strlen(*line);   
    len_line = (len_line - len_overflow + 1);
    new_line = (char *)malloc(sizeof(char) *(len_line));
    if (!(new_line))
        return(NULL);
    while (i < len_line)
    {
        new_line[i] = (*line)[i];
        i++; 
    }
    new_line[i] = '\0';
    free(*line);
    *line = NULL;
    return(new_line);
    
}

char *join_line(char **line , char **chunk, char **tab_position)
{
        char    *temp;
        (*chunk)[BUFFER_SIZE] = '\0';
        temp = ft_strjoin(*line, *chunk);
        if (!(temp))
            return NULL;
        free(*line);
        *line = NULL;
        *line = temp;
        *tab_position = ft_strchr(*line, '\n');
        return(*tab_position);
}

char* get_line(int fd, char **overflow, int text)
{
    char    *chunk;
    char    *line;
    char    *tab_position;

    line = ft_strdup("");
    if (!(line))
        return (NULL);
    tab_position = NULL;
    if (*overflow && overflow)
    {
        line = ft_strjoin(*overflow, line);
        if (!(line))
        {
            free(line);
            return(NULL);
        }
    }
    free(*overflow);
    chunk = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if(!(chunk))
        return (NULL);
    while (text)
    {
        text = read(fd, chunk, BUFFER_SIZE);
        if (text < 0)
        {
            free(chunk);
            free(line);
            return (NULL);
        }
        tab_position = join_line(&line ,&chunk, &tab_position);
        if(tab_position)
            break;
    }
    if(tab_position)
    {
        *overflow = ft_strdup((tab_position + 1));
        if (!(*overflow))
            return(NULL);
    }
    else
        *overflow = NULL;
    line = cut_overflow(*overflow, &line);
    return(line);
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
        if (line)
            ft_putstr(line);
        write(1, "\n",1);
        //free(line);
    }
    close(fd);
    return (0);
}*/



