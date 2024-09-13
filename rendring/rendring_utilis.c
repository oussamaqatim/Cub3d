/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 00:04:20 by oqatim            #+#    #+#             */
/*   Updated: 2023/02/28 01:42:48 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_pixel(int color, t_map *cub, int x, int y)
{
	if (y < 1080 && x < 1080 && y >= 0 && x >= 0)
	cub->full_img->addr[(int)y * 1080 + (int)x] = color;
}

void	calcul_for_3d(t_map *var)
{
	double	distance_projectin_plan;
	double	correct_distance;

	correct_distance = var->ray->distance * cos(var->ray->ray_angle \
		- var->rotation_angle);
	distance_projectin_plan = (var->width / 2) / tan(var->ray->fov / 2);
	var->ray->wall_height = (T_S / correct_distance) * distance_projectin_plan;
	var->ray->wall_top = (var->height / 2) - (var->ray->wall_height / 2);
	if (var->ray->wall_top < 0)
		var->ray->wall_top = 0;
	var->ray->wall_bottom = var->ray->wall_height + var->ray->wall_top;
	if (var->ray->wall_bottom > var->height)
		var->ray->wall_bottom = var->height;
}

void	draw_all(t_map *var)
{
	mlx_clear_window(var->init, var->win);
	rendering_3d(var);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	draw_ceil_floor(t_map *var)
{
	int	t;
	int	v;

	t = 0;
	while (t < var->height)
	{
		v = 0;
		while (v < var->width)
		{
			if (t <= var->height / 2)
				my_img_pix_put2(var, v, t, var->c_coleur);
			else
				my_img_pix_put2(var, v, t, var->f_coleur);
			v++;
		}
		t++;
	}
}
