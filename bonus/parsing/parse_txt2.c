/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_txt2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:58:30 by oqatim            #+#    #+#             */
/*   Updated: 2023/02/28 15:45:18 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	ft_checkb(t_map *ptr, int i, int j)
{
	if (ptr->map[i][j] != '\n' && ptr->map[i][j] != '\t'
		&& ptr->map[i][j] != ' ')
		return (1);
	return (0);
}

int	ft_checkb_colorb(t_map *ptr, int i, int j)
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

int	ft_checkb_1_mapb(t_map *ptr, int i, int j)
{
	if (ptr->map[i][j] == 'N' && ptr->map[i][j + 1] == 'O')
	{
		ft_norm_nob(ptr, i, j);
		return (1);
	}
	else if (ptr->map[i][j] == 'S' && ptr->map[i][j + 1] == 'O')
	{
		ft_norm_sob(ptr, i, j);
		return (1);
	}	
	else if (ptr->map[i][j] == 'W' && ptr->map[i][j + 1] == 'E')
	{
		ft_norm_web(ptr, i, j);
		return (1);
	}	
	else if (ptr->map[i][j] == 'E' && ptr->map[i][j + 1] == 'A')
	{
		ft_norm_eab(ptr, i, j);
		return (1);
	}
	else if (ft_checkb_colorb(ptr, i, j))
		return (1);
	return (0);
}
