#include"get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (*s)
	{
		l++;
		s++;
	}
	return (l);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str_joined;
	size_t		i;
	size_t		j;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str_joined = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str_joined == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		str_joined[i] = s1[i];
		i++;
	}
	while (i < (ft_strlen(s1) + ft_strlen(s2)) && j < ft_strlen(s2))
	{
		str_joined[i++] = s2[j++];
	}
	str_joined[i] = '\0';
	return ((char *)str_joined);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*s2;

	len = ft_strlen(s1);
	s2 = malloc(len + 1);
	if (s2 == NULL)
		return (NULL);
	s2[len] = '\0';
	while (len--)
	{
		s2[len] = s1[len];
	}
	return ((char *)s2);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char )c == '\0')
		return ((char *)s);
	return (0);
}
