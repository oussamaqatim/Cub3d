/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendring_utilis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 00:04:20 by oqatim            #+#    #+#             */
/*   Updated: 2023/02/28 17:50:57 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	init_mouse_b(int x, int y, t_map *map)
{
	static int	i;

	if (i > 2000)
		i -= 1000;
	if (x < 0 || y < 0
		|| x > map->width || y > map->height)
		return (0);
	if (i != x && i > x)
		map->rotation_angle -= M_PI / 60;
	else
		map->rotation_angle += M_PI / 60;
	i = x + 1;
	return (0);
}

void	put_pixelb(int color, t_map *cub, int x, int y)
{
	if (y < 1080 && x < 1080 && y >= 0 && x >= 0)
	cub->full_img->addr[(int)y * 1080 + (int)x] = color;
}

void	draw_all_b(t_map *var)
{
	mlx_clear_window(var->init, var->win);
	rendering_3d_b(var);
}

int	create_rgb_b(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	draw_ceil_floor_b(t_map *var)
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
				my_img_pix_put2_b(var, v, t, var->c_coleur);
			else
				my_img_pix_put2_b(var, v, t, var->f_coleur);
			v++;
		}
		t++;
	}
}
