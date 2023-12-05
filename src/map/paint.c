/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:44:07 by marirodr          #+#    #+#             */
/*   Updated: 2023/12/05 14:29:56 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

/*con esta función pintamos el cielo y el suelo, habria que cambiar los colores
a los que nos pasan por el mapa. puede que en un futuro, a la hora de hacer un 
resize de la ventana haya que cambiar el WEIGHT y HEIGTH y pasarlos por para-
metro para que pueda redibujarse bien.*/

void	ft_paint_background(t_game *game, int h, int w)
{
	int	y;
	int	x;

	y = 0;
	while (y < (h / 2))
	{

		x = 0;
		while (x < w)
		{
			mlx_put_pixel(game->canvas, x, y, game->scene->ceiling); //aqui tendria que ir c_color en hexadecimal
			x++;
		}
		y++;
	}
	while (y < (h))
	{
		x = 0;
		while (x < w)
		{
			mlx_put_pixel(game->canvas, x, y, game->scene->floor);  //aqui tendria que ir f_color en hexadecimal
			x++;
		}
		y++;
	}
}

/*pintamos el minimapa en la ventana, establleiendo previamente las dimensiones
del tile (celda) que va a ocupar en la ventana cada caracter representado.
tal y como yo lo he hecho es: pinto un solo pixel del tile -esquina superior
izquierda para tener como la referencia.
y con esa referencia tenemos que rellenar el tile, que en nuestro caso va a
ser de 15x15. es decir nuestro primer tile es el 0,0 y sus pixeles son 15x15.
por tanto en la funcion ft_fill_tile le paso el valor en coordenadas del mapa
en la que nos encontramos por las dimensiones totales de los tiles, para asi
en un bucle ir pintando tile a tile el minimapa.*/

void	ft_paint_minimap(t_game *info, t_scene *scene)
{
	int	color;
	int	x;
	int	y;

	info->scene->mini = mlx_new_image(info->mlx, info->scene->mini_x, info->scene->mini_y); //limites de la imagen
	if (!info->scene->mini)
		ft_error(IMAGE, NULL);
	if (mlx_image_to_window(info->mlx, info->scene->mini, 30, 30) < 0) // en que coordenadas carga la imagen
		ft_error(IMAGE, NULL);
	y = 0;
	while (scene->map[y])
	{
		x = 0;
		while (scene->map[y][x])
		{
			color = ft_get_color(scene->map, y, x);
			ft_fill_tile(info, x * scene->tile, y * scene->tile, color);
			//mlx_put_pixel(info->scene->mini, x * scene->tile, y * scene->tile, PINK); //esta linea sobra en verdad solo la tengo de referencia
			x++;
		}
		y++;
	}
}


int	ft_get_color(char **map, int y, int x)
{
	int	color;

	if (map[y][x] == '1')
		color = BLACK;
	else if (map[y][x] == '0')
		color = WHITE;
	else if (ft_strchr("NSEW", map[y][x])) //esto lo tengo que unir al 0 en verdad, pero se queda ahora para saber que espauneamos donde toca
		color = GREEN;
	else
		color = GREEN; //este color es de pruebas en verdad no cuenta, mas bien que solo hace falta si no pintamos un background al minimapa
	return (color);
}

/*esta fucntion pinta los pixeles del mapa de iquierda a derecha de arriba
a abajo. pasamos tanto la posicion a pintar del mapa (y, x) por las dimensiones
del tile y establecemos como los maximos las dimensiones totales de mapa por
las dimensiones del tile. rellena celda a celda.
de 0 a 15 -> 15 a 30 -> 30 a 45 ->etc.
el eje horizontal si se va resetando pero el vertical tira palante como las
gatas*/

void	ft_fill_tile(t_game *game, int x, int y, int color)
{
	int	tmp;

	tmp = x;
	while (y < game->scene->mini_y)
	{
		x = tmp;
		while (x < game->scene->mini_x) //(game->scene->tile * game->scene->len_y)
		{
			mlx_put_pixel(game->scene->mini, x, y, color);
			x++;
		}
		y++;
	}
}

	//printf("ft_fill_tile: len_y: %i / len_x: %i\n", game->scene->len_y, game->scene->len_x);
	//printf("ft_fill_tile: y: %i / x: %i / scene->tile: %f\n", y, x, game->scene->tile);
	// printf("game->scene->tile * game->scene->len_x: %f\n", game->scene->tile * game->scene->len_x);
	// printf("game->scene->mini_x: %f / game->scene->mini_y: %f\n", game->scene->mini_x, game->scene->mini_y);

void	ft_render_player(t_game *game, t_scene *scene)
{
	t_coord	inital;
	int		y;
	int		x;

	inital = ft_get_player_pos(game);
	y = 0;
	scene->player = mlx_new_image(game->mlx, scene->tile, scene->tile);
	if (!scene->player)
		ft_error(IMAGE, NULL);
	if (mlx_image_to_window(game->mlx, scene->player, (inital.x * scene->tile) + 30, (inital.y * scene->tile) + 30) == -1)
		ft_error(IMAGE, NULL);
	while (y < scene->tile)
	{
		x = 0;
		while (x < scene->tile)
		{
			mlx_put_pixel(scene->player, x, y, RED);
			x++;
		}
		y++;
	}
}
