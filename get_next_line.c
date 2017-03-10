#include "libft/libft.h"
#include "get_next_line.h"

int	get_line(int fd, char **line,char *buff)
{
	static int nx;

	while ((nx = read(fd, buff, 1)))
	{
		if ( nx == -1)
			return (-1);
		if (buff[0] == '\n')
			return (1);
		buff[1] = '\0';
		if (!*line && buff[0])
			*line = ft_strdup(buff);
		else
			*line = ft_strjoin(*line,buff);
		if (!buff[0] && !*line)
			return (0);
		else if (!buff[0])
			return (1);
	}
	if (nx == 0 && line[0])
		nx = 1;
	return (nx);
}


int	get_next_line(int  fd, char **line)
{
	char		*buff;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	*line = NULL;
	if (!(buff = (char*)malloc(3)))
		return (-1);
	return (get_line(fd,line, buff));
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
	line = (char*)malloc(100);
	while ((sz = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n",line);
		free(line);
		line = (char*)malloc(50);
	}
	return (0);
}
