/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelmoura <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 04:38:44 by zelmoura          #+#    #+#             */
/*   Updated: 2023/03/28 04:52:15 by zelmoura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(char *s1);
char	*ft_strchr(const char *s, int c);
char	*get_global_char(char *str, int fd);
char	*get_line_from_glchar(char *str);
char	*ft_update(char *str);
char	*get_next_line(int fd);

#endif
