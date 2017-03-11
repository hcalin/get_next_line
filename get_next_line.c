#include "libft/libft.h"
#include "get_next_line.h"

int	get_line(int fd, char **line)
{
	static int nx;
	char *buff;

	buff = (char*)malloc(3);
	while ((nx = read(fd, buff, 1)))
	{
		if ( nx == -1)
			return (-1);
		if (buff[0] == '\n')
			break;
		buff[1] = '\0';
		if (!*line && buff[0])
			*line = ft_strdup(buff);
		else
			*line = ft_strjoin(*line,buff);
	}
	free(buff);
	if (!nx && **line)
		nx = 1;
	return (nx);
}


int	get_next_line(int  fd, char **line)
{
	if (fd < 0 || !line)
		return (-1);
	*line = (char*)malloc(2);
	*line[0] = '\0';
	return (get_line(fd,line));
}

int	main(int argc, char **argv)
{
	int fd,sz;
	char *line;
	if (argc < 2)
	{
		ft_putendl("usage: insert_file_name.");
		return (0);
	}
	else if (argc > 2)
	{
		ft_putendl("too many parameters.");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	line = NULL;
	while ((sz = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n",line);
		free(line);
	}
	return (0);
}
