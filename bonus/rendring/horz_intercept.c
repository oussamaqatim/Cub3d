/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horz_intercept.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:25:19 by oqatim            #+#    #+#             */
/*   Updated: 2023/02/28 15:45:18 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	calcul_steps_h_b(t_map *var)
{
	var->ray->ystep = T_S;
	if (var->facing_up == 1)
		var->ray->ystep *= -1;
	var->ray->xstep = var->ray->ystep / tan(var->ray->ray_angle);
	if (var->facing_left && var->ray->xstep > 0)
		var->ray->xstep *= -1;
	if (var->facing_right && var->ray->xstep < 0)
		var->ray->xstep *= -1;
}

void	calcul_intercept_steps_h_b(t_map *var, double *next_x, double *next_y)
{
	var->ray->yintercept = floor(var->y / T_S) * T_S;
	if (var->facing_down == 1)
		var->ray->yintercept += T_S;
	var->ray->xintercept = var->x + \
		(var->ray->yintercept - var->y) / tan(var->ray->ray_angle);
	*next_x = var->ray->xintercept;
	*next_y = var->ray->yintercept;
	calcul_steps_h_b(var);
}

void	get_intersection_b_horz_b(t_map *var)
{
	double	next_x;
	double	next_y;
	int		check;

	check = 0;
	var->ray->horz_wall_found = false;
	calcul_intercept_steps_h_b(var, &next_x, &next_y);
	if (var->facing_up == 1)
		check = 1;
	while (next_x >= 0 && next_x <= var->max_len * T_S
		&& next_y - check >= 0 && next_y - check <= T_S * var->count_line)
	{
		if (check_if_wall_b(var, next_x, next_y - check))
		{
			var->ray->horz_wall_found = true;
			var->ray->horz_wall_hit_x = next_x;
			var->ray->horz_wall_hit_y = next_y;
			break ;
		}
		else
		{
			next_x += var->ray->xstep;
			next_y += var->ray->ystep;
		}
	}
}
