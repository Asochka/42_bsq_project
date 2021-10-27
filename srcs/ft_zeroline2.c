#include "ft_head.h"

char	*ft_zeroline2(char *file_name)
{
	char	*mass;
	int		m;
	char	buffer;
	int		fd;
	int		i;

	m = 0;
	i = 0;
	fd = open(file_name, O_RDONLY);
	m = read(fd, &buffer, 1);
	mass = (char *)malloc(3);
	if (fd != -1)
	{
		while ((buffer >= '0' && buffer <= '9') && m != -1)
			m = read(fd, &buffer, 1);
		while (m != -1 && i < 3)
		{
			mass[i++] = buffer;
			m = read(fd, &buffer, 1);
		}
		mass[i] = '\0';
		close (fd);
		return (mass);
	}
	return (0);
}
