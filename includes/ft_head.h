#ifndef FT_HEAD_H
# define FT_HEAD_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
void	ft_putstr(char *str);
int		*mass_xy(int x, int y, int *massxy);
void	ft_free(int **cash, int x);
void	ft_free_char(char **cash, int x);
int		**matrix_from_array(char **arr, char mass, int *massxy);
int		min(int a, int b, int c);
int		big_sq(int	**matrix, int *massxy, int *maxij);
char	**changed_arr(char **arr, char mass, int *massxy, int **matrix);
void	ft_output(int x, int y, char **arr, char *mass);
char	**ft_filetoarray(char *file_name, int *maslen);
int		*ft_maslen(char *file_name);
int		ft_zeroline1(char *file_name);
char	*ft_zeroline2(char *file_name);
int		check(char *file_name, int *k);
int		check1(char *s);
#endif