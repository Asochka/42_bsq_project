#include "ft_head.h"

char	**ft_filetoarray(char *file_name, int *maslen)
{
	int		i;
	int		j;
	int		fd;
	char	buffer;
	char	**array;

	i = 0;
	buffer = 0;
	array = (char **)malloc(ft_zeroline1(file_name) * sizeof(char *));
	if (!array)
		return (0);
	else
	{
		fd = open(file_name, O_RDONLY);
		if (fd != -1)
		{
			while (buffer != '\n')
				read(fd, &buffer, 1);
			while (i < ft_zeroline1(file_name))
			{
				j = 0;
				array[i] = (char *) malloc ((maslen[1] + 1) * sizeof(char));
				read(fd, &buffer, 1);
				while (j < maslen[1])
				{
					array[i][j++] = buffer;
					read(fd, &buffer, 1);
				}
				array[i++][j] = '\0';
			}
		}
	}
	close (fd);
	return (array);
}
