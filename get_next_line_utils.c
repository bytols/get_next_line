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

char	*ft_putstr(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\r')
	{
		write (1, &s[i], 1);
		i++;
	}
	return(&s[i]);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		len;
	char	*str;

	len = 0;
	str = (char *) s;
	while (str[len] != '\0' && str[len] != '\n')
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
	free(s);
	return (ptr);
}
