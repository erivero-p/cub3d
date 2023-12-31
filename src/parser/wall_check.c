#include "../../inc/cub3D.h"

int ft_is_wall(char **map, int x, int y, t_scene *scene)
{
//	ft_printf("ft_is_wall is checking: map[%i][%i]: %c\n", y, x, map[y][x]);
	if (y == 0 && map[y][x] > 32) //si estoy arriba y hay algo
		return (1);
	if (y == scene->len_y - 1 && map[y][x] > 32) //si estoy abajo y hay algo
		return (1);
	if (x == 0 && map[y][x] > 32) // si estoy a la izquierda y hay algo
		return (1);
	if (x == scene->len_x - 1 && map[y][x] > 32) // si estoy a la derecha y hay algo
		return (1);
	if (y > 0 && map[y - 1][x] <= 32) //si arriba hay un espacio
		return (1);
	if (y < scene->len_y - 1 && map[y + 1][x] <= 32) //si abajo hay un espacio
		return (1);
	if (x > 0 && map[y][x - 1] <= 32) //si a la izquierda hay un espacio
		return (1);
	if (x < scene->len_x - 1 && map[y][x + 1] <= 32) //si a la derecha hay un espacio
		return (1);
	return (0);
}

int	ft_wall_check(char **map, t_scene *scene)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] && y < scene->len_y)
	{
		x = 0;
		while (map[y][x] && x < scene->len_x)
		{
			while (map[y][x] > 0 && map[y][x] <= 32)
				x++;
			if (map[y][x] != 0 && ft_is_wall(map, x, y, scene)
				&& map[y][x] != '1')
			{
				ft_printf("%sFAILED AT: map[%i][%i] %c\n%s", \
				GOOD, y, x, map[y][x], END);
				return (-1);
			}
			x++;
		}
		y++;
	}
	return (1);
}

/* int main(void)
{
	char *map[] = {
		"1111111",
		"1000011",
		"10111",
		"1011111",
		"1011101",
		"1011101",
		"1111111",
		"\n",
		"\n",
		"\n",
		"111",
		"101",
		"111"
	};

	if (wall_checker(map))
		printf("to chachi\n");
	else
		printf("maal\n");
	return 0;
} */