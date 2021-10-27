#include "ft_head.h"

int	min(int a, int b, int c)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

int	big_sq(int	**matrix, int *massxy, int *maxij)
{
	int	**cash;
	int	i;
	int	j;
	int	result;

	result = 0;
	i = 0;
	j = 0;
	cash = (int **)malloc(sizeof(int) * massxy[0]);
	if (cash == 0)
		return (0);
	while (i < massxy[0])
	{
		j = 0;
		cash[i] = (int *)malloc(sizeof(int) * massxy[1]);
		while (j < massxy[1])
		{
			if (i == 0 || j == 0)
				cash[i][j] = matrix[i][j];
			else if (matrix[i][j] == 0)
				cash[i][j] = matrix[i][j];
			else
				cash[i][j] = 1 + min(cash[i][j - 1], \
				cash[i - 1][j], cash[i - 1][j - 1]);
			if (cash[i][j] > result)
			{
				result = cash[i][j];
				maxij[0] = i;
				maxij[1] = j;
			}
			j++;
		}
		i++;
	}
	return (result);
}

char	**changed_arr(char **arr, char mass, int *massxy, int **matrix)
{
	int		side;
	int		maxij[2];
	int		i;
	int		j;
	char	**f_arr;

	f_arr = (char **)malloc(sizeof(char *) * massxy[0]);
	maxij[0] = -1;
	maxij[1] = -1;
	side = big_sq(matrix, massxy, maxij);
	i = 0;
	while (i < massxy[0])
	{
		f_arr[i] = (char *)malloc(sizeof(char) * (massxy[1] + 1));
		j = 0;
		while (j < massxy[1])
		{
			if (i > (maxij[0] - side) && i <= maxij[0] && \
			j > (maxij[1] - side) && j <= maxij[1])
				f_arr[i][j] = mass;
			else
				f_arr[i][j] = arr[i][j];
			j++;
		}
		f_arr[i][j] = '\0';
		i++;
	}
	return (f_arr);
}
