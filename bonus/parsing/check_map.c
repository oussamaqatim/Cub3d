/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:20:49 by iomayr            #+#    #+#             */
/*   Updated: 2023/02/28 17:42:19 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	error_mapb(char *msg, t_map *var)
{
	(void)var;
	printf("Oups Error : %s\n", msg);
	exit(1);
}

void	handle_space_inside_mapb(t_map *var, int y, int x)
{
	if (ft_strlenb(var->var[y + 1]) >= x)
		if ((var->var[y + 1][x] == '0') || (var->var[y + 1][x] == 'N') \
			|| (var->var[y + 1][x]) == 'S' || (var->var[y + 1][x] == 'E') \
				|| (var->var[y + 1][x]) == 'W')
			error_mapb("Around space Inside Map", var);
	if (ft_strlenb(var->var[y - 1]) >= x)
		if ((var->var[y - 1][x] == '0') || (var->var[y - 1][x] == 'N') \
			|| (var->var[y - 1][x]) == 'S' || (var->var[y - 1][x] == 'E') \
				|| (var->var[y - 1][x]) == 'W')
			error_mapb("Around space Inside Map", var);
	if (x > 0)
		if ((var->var[y][x - 1] != ' ' && var->var[y][x - 1] != '1'))
			error_mapb("Around space Inside Map", var);
	if (x != ft_strlenb(var->var[y]) - 1)
		if ((var->var[y][x + 1] != ' ' && var->var[y][x + 1] != '1'))
			error_mapb("Around space Inside Map", var);
}

void	check_line_sizeb(t_map *var, int y)
{
	int	len;

	len = ft_strlenb(var->var[y - 1]);
	if (len > ft_strlenb(var->var[y + 1]))
		len = ft_strlenb(var->var[y + 1]);
	if (len < ft_strlenb(var->var[y]))
	{
		while (var->var[y][len] && var->var[y][len] != '\n')
		{
			if (var->var[y][len] != ' ' && var->var[y][len] != '1')
				error_mapb("Map Not Arrounded by Walls", var);
			len++;
		}
	}
}

void	check_charb(t_map *var, int y, int x)
{
	if (var->var[y][x] == ' ')
		handle_space_inside_mapb(var, y, x);
	if (var->var[y][x] == 'N' || var->var[y][x] == 'S' \
		|| var->var[y][x] == 'E' || var->var[y][x] == 'W')
	{
		var->count_player++;
		get_angle_valueb(var->var[y][x], var);
		get_player_postionb(var, x, y);
	}
	if (var->count_player > 1)
		error_mapb("More than One Player", var);
	if (var->var[y][x] != ' ' && var->var[y][x] != '1' && var->var[y][x] != '0' \
		&& var->var[y][x] != 'N' && var->var[y][x] != 'S' \
			&& var->var[y][x] != 'E' && var->var[y][x] != 'W')
		error_mapb("Invalid character Inside Map", var);
}

void	check_mapb_bb(t_map *var)
{
	int	y;
	int	x;

	y = 1;
	check_linesb(var);
	check_wallsb(var);
	while (y < var->count_line - 1)
	{
		x = 0;
		check_line_sizeb(var, y);
		while (var->var[y][x] != '\n' && var->var[y][x])
		{
			check_charb(var, y, x);
			x++;
		}
		y++;
	}
	if (var->count_player == 0)
		error_mapb("there is No Player", var);
}
