#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# define BUFF_SIZE 100000
# include <stdio.h>

int get_next_line(int fd, char **line);

#endif
