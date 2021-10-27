#include "ft_head.h"

int	ft_zeroline1(char *file_name)
{
	int		a;
	int		m;
	char	buffer;
	int		fd;

	m = 0;
	a = 0;
	fd = open(file_name, O_RDONLY);
	m = read(fd, &buffer, 1);
	if (fd != -1)
	{
		while ((buffer >= '0' && buffer <= '9') && m != -1)
		{
			a = a * 10 + (buffer - '0');
			m = read(fd, &buffer, 1);
		}
	}
	close (fd);
	return (a);
}
