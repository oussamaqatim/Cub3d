/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 05:21:07 by oqatim            #+#    #+#             */
/*   Updated: 2023/02/28 17:44:42 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	initia_rayb1b(t_map *map)
{
	map->ray->x_vert_step = 0;
	map->ray->y_vert_step = 0;
	map->ray->vert_distance = 0;
	map->ray->vert_wall_found = 0;
	map->ray->was_hit_vert = 0;
	map->ray->wall_height = 0;
	map->ray->distance = 0;
	map->ray->offset_x = 0;
	map->ray->offset_y = 0;
	map->ray->p_color = 0;
	map->ray->wall_top = 0;
	map->ray->wall_bottom = 0;
}

void	initia_rayb(t_map *map)
{
	map->ray->ray_angle = 0;
	map->ray->y_wall_hit = 0;
	map->ray->x_wall_hit = 0;
	map->ray->xintercept = 0;
	map->ray->yintercept = 0;
	map->ray->xstep = 0;
	map->ray->ystep = 0;
	map->ray->horz_distance = 0;
	map->ray->horz_wall_hit_x = 0;
	map->ray->horz_wall_hit_y = 0;
	map->ray->horz_wall_found = 0;
	map->ray->vert_wall_hit_x = 0;
	map->ray->vert_wall_hit_y = 0;
	map->ray->x_vert_intercept = 0;
	map->ray->y_vert_intercept = 0;
	initia_rayb1b(map);
}

void	init_mapb1b(t_map *map)
{
	map->flag_no = 0;
	map->flag_so = 0;
	map->flag_we = 0;
	map->flag_ea = 0;
	map->flag_f = 0;
	map->flag_c = 0;
	map->f_color->r = 0;
	map->f_color->g = 0;
	map->f_color->b = 0;
	map->c_color->r = 0;
	map->c_color->g = 0;
	map->c_color->b = 0;
	map->n_texture = NULL;
	map->s_texture = NULL;
	map->e_texture = NULL;
	map->w_texture = NULL;
}

void	ft_alloc_structb(t_map *map)
{
	map->f_color = malloc(sizeof(t_color));
	if (!map->f_color)
		exit(1);
	map->c_color = malloc(sizeof(t_color));
	if (!map->c_color)
		exit(1);
	map->img_n = malloc(sizeof(t_img));
	if (!map->img_n)
		exit(1);
	map->img_s = malloc(sizeof(t_img));
	if (!map->img_s)
		exit(1);
	map->img_w = malloc(sizeof(t_img));
	if (!map->img_w)
		exit(1);
	map->img_e = malloc(sizeof(t_img));
	if (!map->img_e)
		exit(1);
	map->full_img = malloc(sizeof(t_img));
	if (!map->full_img)
		exit(1);
	map->ray = malloc(sizeof(t_raycasting));
	if (!map->ray)
		exit(1);
}

void	init_mapb(t_map *map, char *file)
{
	ft_alloc_structb(map);
	map->file_map = file;
	map->lenght = 0;
	map->width = 0;
	map->count_player = 0;
	map->count = 0;
	map->flag_r = 0;
	map->facing_up = 0;
	map->facing_down = 0;
	map->facing_right = 0;
	map->facing_left = 0;
	init_mapb1b(map);
	initia_rayb(map);
	map->rotation_angle = M_PI / 2;
	map->rotation_speed = 3 * (M_PI / 180);
	map->move_speed = 3;
	map->ray->fov = 60 * (M_PI / 180);
}
