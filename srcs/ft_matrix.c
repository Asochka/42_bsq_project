#include "ft_head.h"

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int	*mass_xy(int x, int y, int *massxy)
{
	massxy[0] = x;
	massxy[1] = y;
	return (massxy);
}

void	ft_free(int **cash, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		free(cash[i]);
		i++;
	}
	free(cash);
}

void	ft_free_char(char **cash, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		free(cash[i]);
		i++;
	}
	free(cash);
}

int	**matrix_from_array(char **arr, char mass, int *massxy)
{
	int	**matrix;
	int	i;
	int	j;

	matrix = (int **)malloc(sizeof(int *) * massxy[0]);
	i = 0;
	j = 0;
	while (i < massxy[0])
	{
		j = 0;
		matrix[i] = (int *)malloc(sizeof(int) * massxy[1]);
		while (j < massxy[1])
		{
			if (arr[i][j] == mass)
				matrix[i][j] = 1;
			else
				matrix[i][j] = 0;
			j++;
		}
		i++;
	}
	return (matrix);
}
