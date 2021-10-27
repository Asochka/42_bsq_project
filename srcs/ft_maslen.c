#include "ft_head.h"

int	*ft_maslen(char *file_name)
{
	int		fd;
	int		i;
	int		*maslen;
	char	buffer[1];
	int		m;
	int		len;

	i = 0;
	m = 0;
	len = 0;
	maslen = (int *)malloc((ft_zeroline1(file_name) + 1) * sizeof(int));
	fd = open(file_name, O_RDONLY);
	if (fd != -1)
	{
		while (i < (ft_zeroline1(file_name) + 1))
		{
			m = read(fd, &buffer, 1);
			maslen[i] = 0;
			while (buffer[0] != '\n' && m != -1)
			{
				len++;
				m = read(fd, &buffer, 1);
			}
			maslen[i] = len;
			len = 0;
			i++;
		}
	}
	close(fd);
	return (maslen);
}

int	check(char *file_name, int *k)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < (ft_zeroline1(file_name) - 1))
	{
		j = i + 1;
		while (j < ft_zeroline1(file_name))
		{
			if (k[i] != k[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check1(char *s)
{
	int	i;
	int	j;
	int	len;

	len = 3;
	i = 0;
	j = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (s[i] == s[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
