/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:44:53 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/28 17:47:19 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	ft_init_map_struct(t_game *info)
{
	info->map = malloc(sizeof(t_map));
	info->map->no_path = NULL;
	info->map->so_path = NULL;
	info->map->we_path = NULL;
	info->map->ea_path = NULL;
	info->map->f_color = NULL;
	info->map->c_color = NULL;
	info->map->file = NULL;
	info->map->map = NULL;
	info->map->len_x = -1;
	info->map->len_y = -1;
}
