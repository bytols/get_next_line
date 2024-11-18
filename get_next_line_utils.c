/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:24:46 by erocha-l          #+#    #+#             */
/*   Updated: 2024/11/18 20:24:46 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static void	f_strncmp(char *dest, char *src, int *n)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[*n] = src[i];
		i++;
		(*n)++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len;
	char	*ptr;

	i = 0;
	len = ft_strlen(s1);
	len += ft_strlen(s2);
	ptr = (char *) malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	f_strncmp(ptr, (char *)s1, &i);
	f_strncmp(ptr, (char *)s2, &i);
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		len;
	char	*str;

	len = 0;
	str = (char *) s;
	while (str[len] != '\0')
		len++;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	len = 0;
	while (str[len] != '\0')
	{
		ptr[len] = str[len];
		len++;
	}
	ptr[len] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*str;
	size_t	s_len;
	size_t	i;

	i = 0;
	str = (char *)s;
	s_len = ft_strlen(str);
	if (s_len <= start)
		len = 0;
	if (len > s_len - start)
		len = s_len - start;
	ptr = (char *) malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while ((i < len) && (str[start] != '\0'))
	{
		ptr[i] = str[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}
