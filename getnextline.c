#include "getnextline.h"

static char			*get_buffer(void)
{
	static char		*buffer = NULL;
	int				i;

	i = 0;
	if (!buffer)
	{
		if (!(buffer = (char *)malloc(sizeof(char) * (1 + BUFF_SIZE))))
			return (NULL);
		ft_bzero(buffer, BUFF_SIZE + 1);
	}
	while (buffer[i] == '\0')
		i++;
	return (buffer + i);
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
	char			*buffer;

	buffer = BUFFER;
	tmp = ft_strchr(BUFFER, '\n');
	if (tmp)
	{
		*tmp = '\0';
		ret = ft_strjoin(line, tmp)
		while (tmp != buffer)
		{
			*tmp = '\0';
			tmp--;
		}
		*tmp = '\0';
	}
	else
		ret = ft_strjoin(line, tmp)
	free(line);
	return (ret);

}

int				get_next_line(const int fd, char **line)
{
	char			*line;
	int				nl_found;

	if (!BUFFER[0])
		read_fd(fd, &nl_found);
	else

}
