/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:20:49 by iomayr            #+#    #+#             */
/*   Updated: 2023/02/28 17:52:43 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	error_map(char *msg, t_map *var)
{
	(void)var;
	printf("Oups Error : %s\n", msg);
	exit(1);
}

void	handle_space_inside_map(t_map *var, int y, int x)
{
	if (ft_strlen(var->var[y + 1]) >= x)
		if ((var->var[y + 1][x] == '0') || (var->var[y + 1][x] == 'N') \
			|| (var->var[y + 1][x]) == 'S' || (var->var[y + 1][x] == 'E') \
				|| (var->var[y + 1][x]) == 'W')
			error_map("Around space Inside Map", var);
	if (ft_strlen(var->var[y - 1]) >= x)
		if ((var->var[y - 1][x] == '0') || (var->var[y - 1][x] == 'N') \
			|| (var->var[y - 1][x]) == 'S' || (var->var[y - 1][x] == 'E') \
				|| (var->var[y - 1][x]) == 'W')
			error_map("Around space Inside Map", var);
	if (x > 0)
		if ((var->var[y][x - 1] != ' ' && var->var[y][x - 1] != '1'))
			error_map("Around space Inside Map", var);
	if (x != ft_strlen(var->var[y]) - 1)
		if ((var->var[y][x + 1] != ' ' && var->var[y][x + 1] != '1'))
			error_map("Around space Inside Map", var);
}

void	check_line_size(t_map *var, int y)
{
	int	len;

	len = ft_strlen(var->var[y - 1]);
	if (len > ft_strlen(var->var[y + 1]))
		len = ft_strlen(var->var[y + 1]);
	if (len < ft_strlen(var->var[y]))
	{
		while (var->var[y][len] && var->var[y][len] != '\n')
		{
			if (var->var[y][len] != ' ' && var->var[y][len] != '1')
				error_map("Map Not Arrounded by Walls", var);
			len++;
		}
	}
}

void	check_char(t_map *var, int y, int x)
{
	if (var->var[y][x] == ' ')
		handle_space_inside_map(var, y, x);
	if (var->var[y][x] == 'N' || var->var[y][x] == 'S' \
		|| var->var[y][x] == 'E' || var->var[y][x] == 'W')
	{
		var->count_player++;
		get_angle_value(var->var[y][x], var);
		get_player_postion(var, x, y);
	}
	if (var->count_player > 1)
		error_map("More than One Player", var);
	if (var->var[y][x] != ' ' && var->var[y][x] != '1' && var->var[y][x] != '0' \
		&& var->var[y][x] != 'N' && var->var[y][x] != 'S' \
			&& var->var[y][x] != 'E' && var->var[y][x] != 'W')
		error_map("Invalid character Inside Map", var);
}

void	check_map_b(t_map *var)
{
	int	y;
	int	x;

	y = 1;
	check_lines(var);
	check_walls(var);
	while (y < var->count_line - 1)
	{
		x = 0;
		check_line_size(var, y);
		while (var->var[y][x] != '\n' && var->var[y][x])
		{
			check_char(var, y, x);
			x++;
		}
		y++;
	}
	if (var->count_player == 0)
		error_map("there is No Player", var);
}
