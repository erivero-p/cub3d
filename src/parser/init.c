/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marirodr <marirodr@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:44:53 by marirodr          #+#    #+#             */
/*   Updated: 2023/11/30 11:41:48 by marirodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	ft_init_map_struct(t_game *info)
{
	info->scene = malloc(sizeof(t_scene));
	info->scene->no_path = NULL;
	info->scene->so_path = NULL;
	info->scene->we_path = NULL;
	info->scene->ea_path = NULL;
	info->scene->f_color = NULL;
	info->scene->c_color = NULL;
	info->scene->file = NULL;
	info->scene->map = NULL;
	info->scene->len_x = -1;
	info->scene->len_y = -1;
	info->scene->tile = -1;
	info->scene->mini_x = -1;
	info->scene->mini_y = -1;
}
