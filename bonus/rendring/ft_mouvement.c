/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouvement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:29:40 by oqatim            #+#    #+#             */
/*   Updated: 2023/02/28 17:49:23 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	ft_exit_b(t_map *za)
{
	(void) za;
	printf("Good Bye !\n");
	exit(1);
	return (0);
}

int	key_press_b(int key, t_map *za)
{
	if (key == W)
		za->walk = 1;
	if (key == S)
		za->walk = -1;
	if (key == D)
		za->jnab = 1;
	if (key == A)
		za->jnab = -1;
	if (key == 124)
		za->turn_left_right = 1;
	if (key == 123)
		za->turn_left_right = -1;
	if (key == 53)
	{
		printf("Good Bye !\n");
		exit(1);
	}
	return (0);
}

int	key_release_b(int key, t_map *za)
{
	if (key == W || key == S)
		za->walk = 0;
	if (key == D || key == A)
		za->jnab = 0;
	if (key == 124 || key == 123)
		za->turn_left_right = 0;
	return (0);
}

void	check_wall_b(t_map	*var, int status)
{
	double	new_x;
	double	new_y ;
	int		move;

	new_x = var->x;
	new_y = var->y;
	if (status == 1)
	{
		move = var->walk * var->move_speed;
		new_x += (cos(var->rotation_angle) * move);
		new_y += (sin(var->rotation_angle) * move);
	}
	else if (status == 2)
	{
		move = var->jnab * var->move_speed;
		new_y += cos(var->rotation_angle) * move;
		new_x -= sin(var->rotation_angle) * move;
	}
	if (var->var[(int)new_y / T_S][(int)new_x / T_S] == '1')
		return ;
	if (var->var[(int)new_y / T_S][(int)var->x / T_S] == '1'
		&& var->var[(int)var->y / T_S][(int)new_x / T_S] == '1')
		return ;
	var->x = new_x;
	var->y = new_y;
}

void	move_player_b(t_map *za)
{
	za->rotation_angle += za->turn_left_right * za->rotation_speed;
	if (za->walk)
		check_wall_b(za, 1);
	else if (za->jnab)
		check_wall_b(za, 2);
}
