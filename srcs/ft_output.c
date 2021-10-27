#include "ft_head.h"

void	ft_output(int x, int y, char **arr, char *mass)
{
	char	**f_arr;
	int		**matrix;
	int		i;
	int		*massxy;

	i = 0;
	massxy = (int *)malloc(sizeof(int) * 2);
	massxy = mass_xy(x, y, massxy);
	matrix = matrix_from_array(arr, mass[0], massxy);
	f_arr = changed_arr(arr, mass[2], massxy, matrix);
	while (i < x)
	{
		ft_putstr(f_arr[i]);
		i++;
	}
	ft_free(matrix, x);
	ft_free_char(arr, x);
	ft_free_char(f_arr, x);
	free(massxy);
}
