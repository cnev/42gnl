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
	{
		if (i == BUFF_SIZE)
			return (buffer);
		i++;
	}
	return (buffer + i);
}

int				read_fd(const int fd, int *nl_found)
{
	int				nb;

	nb = read(fd, BUFFER, BUFF_SIZE);
	if (nb <= 0)
		return (nb);
	BUFFER[nb] = '\0';

	return (1);
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
	char			*str;
	int				nl_found;
	int				read_val;

	str = NULL;
	nl_found = 0;
	while (!nl_found)
	{
		if ((read_val = read_fd(fd, &nl_found)) == 0)
			return (read_val);
		str = extract_line(str);
		if (read_val == 0 && !str)
			return (0);
		*line = str;
		return (1);
	}


}
