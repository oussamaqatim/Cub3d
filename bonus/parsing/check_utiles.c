/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:31:32 by iomayr            #+#    #+#             */
/*   Updated: 2023/02/28 16:39:58 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	get_player_postionb(t_map *var, int x, int y)
{
	var->x = (double)x * T_S + T_S / 2.0;
	var->y = (double)y * T_S + T_S / 2.0;
}

void	check_last_lineb(t_map *var, int x)
{
	int	y;

	y = var->count_line - 1;
	if (ft_strlenb(var->var[y - 1]) >= x)
		if (var->var[y - 1][x] != ' ' && var->var[y - 1][x] != '1' \
			&& var->var[y - 1][x] != '\0')
			error_mapb("Around space In Last Line", var);
	if (x > 0)
		if ((var->var[y][x - 1] != ' ' && var->var[y][x - 1] != '1'))
			error_mapb("eAround space in Last Line", var);
	if (x != ft_strlenb(var->var[y]) - 1)
		if ((var->var[y][x + 1] != ' ' && var->var[y][x + 1] != '1'))
			error_mapb("Around space in Last Line", var);
}

void	check_wallsb(t_map *var)
{
	int	y;
	int	x;

	y = var->count_line;
	while (--y >= 0)
	{
		x = ft_strlenb(var->var[y]) - 1;
		if (var->var[y][0] != ' ' && var->var[y][0] != '1')
			error_mapb("Left Side of Wall", var);
		else if (var->var[y][x] != ' ' && var->var[y][x] != '1')
			error_mapb("Right Side of Wall", var);
	}
}

void	handle_space_in_linesb(t_map *var, int x, char *str)
{
	if (ft_strcmpb(str, "first") == 0)
	{
		if (ft_strlenb(var->var[1]) >= x)
			if (var->var[1][x] != ' ' && var->var[1][x] != '1' \
				&& var->var[1][x] != '\0')
				error_mapb("Around space In first Line", var);
		if (x > 0)
			if ((var->var[0][x - 1] != ' ' && var->var[0][x - 1] != '1'))
				error_mapb("Around space in First Line", var);
		if (x != ft_strlenb(var->var[0]) - 1)
			if ((var->var[0][x + 1] != ' ' && var->var[0][x + 1] != '1'))
				error_mapb("Around space in First Line", var);
	}
	else if (ft_strcmpb(str, "last") == 0)
		check_last_lineb(var, x);
}

void	check_linesb(t_map *var)
{
	int	x;
	int	y;

	x = 0;
	y = var->count_line - 1;
	while (var->var[0][x] && var->var[0][x] != '\n')
	{
		if (var->var[0][x] == ' ')
			handle_space_in_linesb(var, x, "first");
		if (var->var[0][x] != ' ' && var->var[0][x] != '1')
			error_mapb("First Line", var);
		x++;
	}
	x = 0;
	while (var->var[y][x] && var->var[y][x] != '\n')
	{
		if (var->var[y][x] == ' ')
			handle_space_in_linesb(var, x, "last");
		if (var->var[y][x] != ' ' && var->var[y][x] != '1')
			error_mapb("Last Line", var);
		x++;
	}
}
