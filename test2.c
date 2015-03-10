#include <stdio.h>
#include <stdlib.h>
#define BUFF_SIZE 1000
# define BUFFER		get_buffer(1)
# define BUFFER_ORIGIN get_buffer(0)
#include <fcntl.h>
#include <string.h>
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;
	size_t			index;

	index = 0;
	tmp = (unsigned char*)b;
	while (index < len)
	{
		tmp[index] = (unsigned char)c;
		index++;
	}
	return (tmp);
}

void	ft_bzero(void *s, size_t n)
{
	if (s != NULL)
		ft_memset(s, 0, n);
}

size_t		ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char		*ft_strdup(const char *s1)
{
	size_t	len;
	char	*output;
	size_t	index;

	len = ft_strlen(s1);
	output = (char *)malloc(sizeof(char) * (len + 1));
	index = 0;
	while (s1[index])
	{
		output[index] = s1[index];
		index++;
	}
	output[index] = '\0';
	return (output);
}

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i_s1;
	size_t	i_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i_s1 = ft_strlen(s1);
	i_s2 = 0;
	while (s2[i_s2])
	{
		s1[i_s1] = s2[i_s2];
		i_s1++;
		i_s2++;
	}
	s1[i_s1] = '\0';
	return (s1);
}

char	*ft_strcpy(char *s1, const char *s2)
{
	size_t	index1;
	size_t	index2;

	index1 = 0;
	index2 = 0;
	while (s2[index2] != '\0')
	{
		s1[index1] = s2[index2];
		index1++;
		index2++;
	}
	s1[index1] = '\0';
	return (s1);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char			*output;
	size_t			len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if ((output = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	ft_strcpy(output, s1);
	ft_strcat(output, s2);
	return (output);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	index;
	char	*ptr;

	index = 0;
	ptr = (char *)s;
	while ((s[index] != c) && (s[index] != '\0'))
	{
		index++;
		ptr = (char *)s + index;
	}
	if ((c != '\0') && (s[index] == '\0'))
		return (NULL);
	return (ptr);
}

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
		if (read_val == 0 && !str)
			return (0);
		*line = str;
		if (!fd && read_val != 0)
			return (1);
		if (!BUFFER[0])
			return (0);
		return (1);
	}
	return (-1);
}

int main(int argc, char *argv[])
{
  int fd = open("poisson.txt", O_RDONLY);
  char *line = NULL;
  while ((get_next_line(fd, &line)) > 0)
  {
         printf("%s\n", line);
  }
  while ((get_next_line(0, &line)) > 0)
  {
         printf("%s\n", line);
  }
  system("PAUSE");
  return 0;
}
