/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:52:50 by marirodr          #+#    #+#             */
/*   Updated: 2023/12/04 13:27:34 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRUCTS_H
# define CUB_STRUCTS_H

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_img
{
	mlx_texture_t	*no_text;
	mlx_texture_t	*so_text;
	mlx_texture_t	*we_text;
	mlx_texture_t	*ea_text;
	mlx_image_t		*no_img;
	mlx_image_t		*so_img;
	mlx_image_t		*we_img;
	mlx_image_t		*ea_img;
}	t_img;

typedef struct s_scene
{
	char		**file;
	char		**map;
	char		**aux_map;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		*f_color;
	char		*c_color;
	int			floor; //color en hexadecimal
	int			ceiling; //color en hexadecimal
	int			counter;
	int			len_x;
	int			len_y;
	mlx_image_t	*img;
	mlx_image_t	*mini;
	float		tile;
	float		mini_x;
	float		mini_y;
}	t_scene;

typedef struct s_player
{
	t_coord		*pos_map;
	mlx_image_t	*player_img; //->para igualar a s_game->mlx 
	mlx_t		*mlx; //->para igualar a s_game->mlx
	int			color;
}	t_player;

typedef struct s_game
{
	mlx_t		*mlx;
	t_scene		*scene;
	t_img		*imgs;
	mlx_image_t	*canvas; //esta mierda es solo para testear
	t_player	*player;
}	t_game;

typedef enum e_errors
{
	ARG = 1,
	EXT_CUB, //extensión .cub
	FD, // al abrir archivo
	FORMAT, //formato del archivo
	WALL,
	CHAR,
	EMPTY,
	PLAYER, //más de uno
	EXT_PNG, //extensión .png
	COLOR, //formato rgb
	WINDOW, //fallo al abrir la ventana
	IMAGE, //fallo al abrir la ventana
}		t_errors;

# define DEBUG_COLOR "\033[0;96m"
# define GOOD "\033[0;32m"
# define WRONG "\033[0;31m"
# define END "\033[0m"

# define WIDTH 1080
# define HEIGHT 720

# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF
# define BLUE 0xADD8E6
# define PINK 0xFFC0CBFF
# define RED 0xFF0000FF
# define GREEN 0x007F007F

#endif