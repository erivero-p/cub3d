#include "../../inc/cub3D.h"

static void ft_print_fileformat(char *str)
{
	ft_printf("%sError\nIncorrect file format%s\n", RED, END);
	if (*str)
		ft_printf("%s%s%s\n", RED, str, END);
	printf("Please input a file as described below:\n");
	printf("Floor, ceiling, north, south, east, and west "
		"textures should appear at the beginning of the file, "
		"separated by one or more newlines, and in any desired order.\n");
	printf("The map should be the last element in the file.\n");
}

void	ft_parse_errors(int	err, char *str)
{
	if (err == ARG)
		ft_printf("%sError\nWrong input%s\n", RED, END);
	if (err == EXT_CUB)
		ft_printf("%sError\nThe map file doesn't have \
			a valid extension. It must be .cub%s\n", RED, END);
	if (err == EXT_PNG)
		ft_printf("%sError\nThe texture file doesn't have \
			a valid extension. It must be .png%s\n", RED, END);
	if (err == FD)
		ft_printf("%sError\nProblem while opening file%s\n", RED, END);
	if (err == FORMAT)
		ft_print_fileformat(str);
	if (err == WALL)
		ft_printf("%sError\nThe map must be surrounded by walls%s\n", RED, END);
	if (err == CHAR)
		ft_printf("%sError\nThe map contains invalid characters%s\n", RED, END);
	if (err == EMPTY)
		ft_printf("%sError\nInvalid file, empty map%s\n", RED, END);
	if (err == PLAYER)
		ft_printf("%sError\nThe map must have one player position%s\n", RED, END);
}

void	ft_mlx_errors(int err, char *str)
{
	if (err == WINDOW)
		ft_printf("%sError while opening the window\n%s%s\n", RED, str, END);
	if (err == IMAGE)
		ft_printf("%sError while rendering an image\n%s%s\n", RED, str, END);
}

int	ft_error(int err, char *str)
{
	if (err == 42) // para mensaje personalizado
		ft_printf("%sError\n%s%s\n", RED, str, END);
	ft_parse_errors(err, str);
	ft_mlx_errors(err, str);
	return (-1);
}
