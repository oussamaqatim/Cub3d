/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_intercept.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:28:02 by oqatim            #+#    #+#             */
/*   Updated: 2023/02/27 20:28:46 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calcul_steps_v(t_map *var)
{
	var->ray->x_vert_step = T_S;
	if (var->facing_left == 1)
		var->ray->x_vert_step *= -1;
	var->ray->y_vert_step = var->ray->x_vert_step * tan(var->ray->ray_angle);
	if (var->facing_up && var->ray->y_vert_step > 0)
		var->ray->y_vert_step *= -1;
	if (var->facing_down && var->ray->y_vert_step < 0)
		var->ray->y_vert_step *= -1;
}

void	calcul_intercept_steps_v(t_map *var, double *next_x, double *next_y)
{
	var->ray->x_vert_intercept = floor(var->x / T_S) * T_S;
	if (var->facing_right == 1)
		var->ray->x_vert_intercept += T_S;
	var->ray->y_vert_intercept = var->y + \
		(var->ray->x_vert_intercept - var->x) \
			* tan(var->ray->ray_angle);
	*next_x = var->ray->x_vert_intercept;
	*next_y = var->ray->y_vert_intercept;
	calcul_steps_v(var);
}

void	get_intersection_vert(t_map *var)
{
	double	next_x;
	double	next_y;
	int		check;

	check = 0;
	var->ray->vert_wall_found = false;
	calcul_intercept_steps_v(var, &next_x, &next_y);
	if (var->facing_left)
		check = 1;
	while (next_x - check >= 0 && next_x - check <= var->max_len \
		* T_S && next_y >= 0 && next_y <= T_S * var->count_line)
	{
		if (check_if_wall(var, next_x - check, next_y))
		{
			var->ray->vert_wall_found = true;
			var->ray->vert_wall_hit_x = next_x;
			var->ray->vert_wall_hit_y = next_y;
			break ;
		}
		else
		{
			next_x += var->ray->x_vert_step;
			next_y += var->ray->y_vert_step;
		}
	}
}
