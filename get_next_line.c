#include"get_next_line.h"
char *get_next_line(int fd)
{
    char *buf;

    buf = malloc(BUFFER_SIZE + 1);
    read(fd, buf, BUFFER_SIZE);
    return(buf);
}
#include<stdio.h>
int main()
{
    int fd;

    fd = open("file", O_RDONLY);
    printf("%s", get_next_line(fd));
    return (0);
}