/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:23:59 by oqatim            #+#    #+#             */
/*   Updated: 2023/02/28 15:16:20 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calcul_xoffset(t_map *var)
{
	if (var->ray->was_hit_vert)
		var->ray->offset_x = var->ray->y_wall_hit;
	else
		var->ray->offset_x = var->ray->x_wall_hit;
	var->ray->offset_x /= T_S;
	var->ray->offset_x -= floor(var->ray->offset_x);
	var->ray->offset_x *= var->width_txt;
}

void	get_color_from_txt(t_map *var)
{
	int	pixel;

	pixel = 0;
	if (var->ray->was_hit_vert)
	{
		if (var->facing_right)
			pixel = var->img_e->addr_i \
				[((int)var->ray->offset_y + (int)var->ray->offset_x)];
		else if (var->facing_left)
			pixel = var->img_w->addr_i \
				[((int)var->ray->offset_y + (int)var->ray->offset_x)];
	}
	else
	{
		if (var->facing_down)
			pixel = var->img_s->addr_i \
				[((int)var->ray->offset_y + (int)var->ray->offset_x)];
		else if (var->facing_up)
			pixel = var->img_s->addr_i \
				[((int)var->ray->offset_y + (int)var->ray->offset_x)];
	}
	var->ray->p_color = pixel;
}

void	draw_txt(t_map *var, int id)
{
	double	y;

	y = var->ray->wall_top;
	calcul_xoffset(var);
	while (y < var->ray->wall_bottom)
	{
		var->ray->offset_y = y + (var->ray->wall_height / 2) \
			- (var->height / 2);
		if (var->ray->offset_y < 0)
			var->ray->offset_y = 0;
		var->ray->offset_y = var->ray->offset_y * \
			(var->height_txt / var->ray->wall_height);
		var->ray->offset_y = floor(var->ray->offset_y);
		var->ray->offset_y *= var->width_txt;
		get_color_from_txt(var);
		my_img_pix_put2(var, id, y, var->ray->p_color);
		y++;
	}
}
