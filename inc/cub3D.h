/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:52:50 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/29 13:13:26 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "cub_structs.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

/*							PARSE							*/

//parse.c
void	ft_init(t_game *info);
int		ft_parse(t_game *info, int fd, char *file);
int		ft_arg_check(int ac, char **av);

//map_read.c
int		ft_parse_file(t_scene *scene);
//int		ft_parse_file(t_game *info);

//scene_check.c
int		ft_scene_check(t_scene *scene);

//char_check.c
int		ft_char_check(char c);
int		ft_char_mapcheck(char **map);
//ft_wall_checker.c
int		ft_wall_check(char **map);

//format.c
int		ft_check_ext(char *str, char *ext);

/*							UTILS							*/
//error_handling.c							
int		ft_error(int err, char *str);

//clean_handling.c
void	ft_clean_map(t_game	*info);


//init.c
void   ft_init_map_struct(t_game *info);

//error_handling.c
int     ft_error(int err, char *str);

//debug.c
void	ft_print_map(t_scene *scene);
void 	ft_print_matrix(char **matrix, int test);


/*							SETTINGS							*/
//window.c
int	    ft_check_monitor(mlx_t *mlx);
void	ft_resize(void *param);

//controls.c
void	ft_controls(mlx_key_data_t keydata, void *param);

/*							MAP							*/
//map.c
void	ft_init_map(t_game *info);
int     ft_get_map_x(t_game *info);
void	ft_paint_minimap(void *param);

#endif