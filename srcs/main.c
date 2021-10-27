#include "ft_head.h"

int	main(int argc, char **argv)
{
	int		*maslen;
	char	**array;
	int		i;
	int		fd;
	char	buffer;

	if (argc >= 2)
	{
		i = 1;
		while (i != argc)
		{
			maslen = ft_maslen(argv[i]);
			array = ft_filetoarray(argv[i], maslen);
			if ((check(argv[i], maslen) == -1) || \
			(check1(ft_zeroline2(argv[i])) == -1))
				write(1, "map error\n", 11);
			else
				ft_output(ft_zeroline1(argv[i]), maslen[1], array, \
				ft_zeroline2(argv[i]));
			i++;
		}
	}
	else
	{
		fd = open("1.txt", O_TRUNC | O_CREAT | O_WRONLY, 0644);
		while (read(0, &buffer, 1))
		{
			write(fd, &buffer, 1);
		}
		close (fd);
		maslen = ft_maslen("1.txt");
		array = ft_filetoarray("1.txt", maslen);
		ft_output(ft_zeroline1("1.txt"), maslen[1], array, \
		ft_zeroline2("1.txt"));
	}
	free(maslen);
	return (0);
}
