static char			*get_buffer(int mode)
{
	static char		*buffer = NULL;
	int				i;

	i = 0;
	if (!buffer)
	{
		if (!(buffer = (char *)malloc(sizeof(char) * (1 + BUFF_SIZE))))
			return (NULL);
		ft_memset(buffer, '\0', BUFF_SIZE + 1);
	}
	if (mode == 0)
		return (buffer);
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
	int				eof_flag;
	char			*tmp;

	if ((nb = read(fd, BUFFER, BUFF_SIZE)) < 1)
		return (nb);
	BUFFER[nb] = 0;
	tmp = ft_strchr(BUFFER, 26);
	eof_flag = (tmp) ? 1 : 0;
	ft_memset(BUFFER + nb, '\0', BUFF_SIZE - nb);
	if (eof_flag)
		return(0);
	if (!nb)
		return (nb);
	if (ft_strchr(BUFFER, '\n'))
		*nl_found = 1;
	return (1);
}

char			*extract_line(char *line)
{
	char			*tmp;
	char			*ret;
	char			*buffer;

	buffer = BUFFER;
	if (!*buffer)
		return (line);
	tmp = ft_strchr(buffer, '\n');
	if (tmp)
	{
		*tmp = '\0';
		ret = ft_strjoin(line, buffer);
		while (tmp != buffer)
		{
			tmp--;
			*tmp = '\0';
		}
	}
	else
		ret = ft_strjoin(line, buffer);
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
	read_val = -1;
	while (!nl_found)
	{
		if (!BUFFER[0])
			if ((read_val = read_fd(fd, &nl_found)) < 0)
				return (read_val);
		str = extract_line(str);
		if (!read_val && !str)
			return (0);
		*line = str;
		if (!fd && read_val != 0)
			return (1);
		if (!fd && !read_val)
			return (0);
		//if (!BUFFER[0])
		//	return (0);
		return (1);
	}
	return (-1);
}

