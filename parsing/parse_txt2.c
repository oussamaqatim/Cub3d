/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_txt2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:58:30 by oqatim            #+#    #+#             */
/*   Updated: 2023/02/28 15:15:38 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check(t_map *ptr, int i, int j)
{
	if (ptr->map[i][j] != '\n' && ptr->map[i][j] != '\t'
		&& ptr->map[i][j] != ' ')
		return (1);
	return (0);
}

int	ft_check_color(t_map *ptr, int i, int j)
{
	if (ptr->map[i][j] == 'F')
	{
		ft_norm_f(ptr, i, j);
		return (1);
	}
	else if (ptr->map[i][j] == 'C')
	{
		ft_norm_c(ptr, i, j);
		return (1);
	}
	return (0);
}

int	ft_check_1_map(t_map *ptr, int i, int j)
{
	if (ptr->map[i][j] == 'N' && ptr->map[i][j + 1] == 'O')
	{
		ft_norm_no(ptr, i, j);
		return (1);
	}
	else if (ptr->map[i][j] == 'S' && ptr->map[i][j + 1] == 'O')
	{
		ft_norm_so(ptr, i, j);
		return (1);
	}	
	else if (ptr->map[i][j] == 'W' && ptr->map[i][j + 1] == 'E')
	{
		ft_norm_we(ptr, i, j);
		return (1);
	}	
	else if (ptr->map[i][j] == 'E' && ptr->map[i][j + 1] == 'A')
	{
		ft_norm_ea(ptr, i, j);
		return (1);
	}
	else if (ft_check_color(ptr, i, j))
		return (1);
	return (0);
}
