#include "getnextline.h"

static char			*get_buffer(void)
{
	static char		*buffer = NULL;

	if (!buffer)
	{
		if (!(buffer = (char *)malloc(sizeof(char) * (1 + BUFF_SIZE))))
			return (NULL);
		ft_bzero(buffer, BUFF_SIZE + 1);
	}
	return (buffer);
}

int				read_fd(const int fd, int *nl_found)
{
	int				nb;

	nb = read(fd, BUFFER, BUFF_SIZE);
	if (nb < 0)
		return (nb);
	BUFFER[nb] = '\0';
	return (nb);
}

char			*extract_line(char *line)
{
	char			*tmp;
	char			*ret;

	ret = ft_strchr(line, '\n');

}

int				get_next_line(const int fd, char **line)
{
	char			*line;
	int				nl_found;

	if (!BUFFER[0])
		read_fd(fd, &nl_found);
	else

}
