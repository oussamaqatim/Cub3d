/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:26:37 by oqatim            #+#    #+#             */
/*   Updated: 2023/02/28 16:49:32 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	facing_up_down_b(t_map *var)
{
	if (var->ray->ray_angle > 0 && var->ray->ray_angle < M_PI)
	{
		var->facing_down = 1;
		var->facing_up = 0;
	}
	else
	{
		var->facing_down = 0;
		var->facing_up = 1;
	}
}

void	facing_right_left_b(t_map *var)
{
	if (var->ray->ray_angle < (0.5 * M_PI) \
		|| var->ray->ray_angle > (1.5 * M_PI))
	{
		var->facing_right = 1;
		var->facing_left = 0;
	}
	else
	{
		var->facing_left = 1;
		var->facing_right = 0;
	}
}

void	get_intersection_b(t_map *var)
{
	facing_up_down_b(var);
	facing_right_left_b(var);
	get_intersection_b_horz_b(var);
	get_intersection_b_vert_b(var);
}

void	normalizingray_angle_b(t_map *var)
{
	var->ray->ray_angle = fmod(var->ray->ray_angle, 2 * M_PI);
	if (var->ray->ray_angle < 0)
		var->ray->ray_angle += 2 * M_PI;
}

void	rendering_3d_b(t_map *var)
{
	int	id;

	id = 0;
	var->ray->fov = 60 * (M_PI / 180);
	var->ray->ray_angle = var->rotation_angle - var->ray->fov / 2;
	var->full_img->img = mlx_new_image(var->init, \
		var->width, var->height);
	var->full_img->addr = mlx_get_data_addr(var->full_img->img, \
		&var->full_img->bpp, &var->full_img->line_len, \
			&var->full_img->endian);
	draw_ceil_floor_b(var);
	while (id < var->width)
	{
		normalizingray_angle_b(var);
		get_intersection_b(var);
		compare_distanceb(var);
		calcul_for_3d_b(var);
		draw_txtb(var, id);
		var->ray->ray_angle += var->ray->fov / var->width;
		id++;
	}
	mlx_put_image_to_window(var->init, var->win, \
		var->full_img->img, 0, 0);
	mlx_destroy_image(var->init, var->full_img->img);
}
