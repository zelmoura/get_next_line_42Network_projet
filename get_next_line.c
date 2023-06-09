/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelmoura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 02:29:58 by zelmoura          #+#    #+#             */
/*   Updated: 2023/03/28 03:25:16 by zelmoura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_global_char(char *str, int fd)
{
	char	*buff;
	int		count;

	buff = malloc(BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	count = 1;
	while (count > 0 && ft_strchr(str, '\n') == NULL)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count == 0)
			break ;
		if (count == -1)
		{
			free(buff);
			free(str);
			return (NULL);
		}
		buff[count] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_line_from_glchar(char *str)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (*str == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (line == NULL)
		return (NULL);
	while (j < i)
	{
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_update(char *str)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	new = malloc(ft_strlen(str) - i + 1);
	if (new == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		new[j++] = str[i++];
	}
	new[j] = '\0';
	free(str);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*gl_char;
	char		*retuned_line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	gl_char = get_global_char(gl_char, fd);
	if (gl_char == NULL)
		return (free(gl_char), NULL);
	retuned_line = get_line_from_glchar(gl_char);
	gl_char = ft_update(gl_char);
	return (retuned_line);
}
