/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:22:22 by erocha-l          #+#    #+#             */
/*   Updated: 2024/11/14 13:22:22 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
    chunk = NULL;
    if (!line)
    {
        free(overflow);
        overflow = NULL;
        return (NULL);
    }
    cut_excess(&line ,&overflow);
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
        if (text == 0)
            return (*overflow);
        chunk[text] = '\0';
        if(!(*overflow))
            *overflow = ft_strdup("");
        temp = *overflow;
        *overflow = ft_strjoin(temp, chunk);
        free(temp);
        temp = NULL;
        if(ft_strchr(*overflow, '\n'))
            break;
    }
    return(*overflow);
}

static void cut_excess(char **line, char **overflow)
{
    char *space_position;
    char *new_overflow;

    space_position = ft_strchr(*overflow, '\n');
    if (!space_position)
    {
        *line = ft_strdup(*overflow);
        free(*overflow);
        *overflow = NULL;
        return;
    }
    *line = ft_substr(*overflow, 0, (space_position - *overflow + 1));
    if (*(space_position + 1) != '\0')
        new_overflow = ft_strdup(space_position + 1);
    else
        new_overflow = NULL;
    free(*overflow);
    *overflow = new_overflow;
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

//ver os testes do tester e testar aqui com o debbuger!
/*int main()
{
    int fd;
    int i;
    char    *line;

    fd = open("text.txt", O_RDWR);
    for(i = 0; i < 7; i++)
    {
        line = get_next_line(fd);
        printf("%s", line);
        free(line);
        line = NULL;
    }
    close(fd);
    return (0);
}*/