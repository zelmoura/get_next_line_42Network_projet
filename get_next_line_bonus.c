#include "get_next_line_bonus.h"
#include <stdio.h>



char *get_global_char(char *str, int fd)
{
    char *buff;
    int count;

    buff = malloc(BUFFER_SIZE + 1);
    if (buff == NULL)
        return (NULL);
    count = 1;
    while (count > 0 && ft_strchr(str, '\n') == NULL)
    {
        count = read(fd, buff, BUFFER_SIZE);
        if (count == 0)
            break;
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

char *get_line_from_glchar(char *str)
{
    int i;
    int j;
    char *line;

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

char *ft_update(char *str)
{

    int i;
    int j;
    char *new;

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
        new[j] = str[i++];
        j++;
    }
    new[j] = '\0';
    free(str);
    return (new);
}
char *get_next_line(int fd)
{
    static char *gl_char[10240];
    char *retuned_line;

    if (fd < 0 || fd > 10240 || BUFFER_SIZE < 0)
        return (NULL);
    gl_char[fd] = get_global_char(gl_char[fd], fd);
    if (gl_char[fd] == NULL)
        return (free(gl_char[fd]), NULL);
    retuned_line = get_line_from_glchar(gl_char[fd]);
    gl_char[fd] = ft_update(gl_char[fd]);
    return (retuned_line);
}

// #include <stdio.h>

// void    s(void)
// {çç

//     get_next_line(fd);
//     // while (p)
//     // {
//     //     get_next_line()
//     //     free(p);
//     //     p = get_next_line(fd);
//     // }
//     close(fd);
  
// }
// #include<stdio.h>
// int main()
// {
//     char *p;
//     int fd = open("/Users/zelmoura/francinette/tests/get_next_line/fsoares/read_error.txt", O_RDONLY);
//     while (p)
//     {
//         p = get_next_line(fd);
//         printf("%s", p);
//         free(p);
        
//     }
//     while(1);
    
// }