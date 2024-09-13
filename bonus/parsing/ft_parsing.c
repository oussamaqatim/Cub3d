/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 00:38:17 by oqatim            #+#    #+#             */
/*   Updated: 2023/02/28 15:45:18 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	ft_checkb_after_mapb(t_map *ptr, int *index)
{
	int	i;
	int	j;

	i = *index;
	while (i < ptr->lenght)
	{
		j = 0;
		while (ptr->map[i][j] != '\0')
		{
			if (ptr->map[i][j] == '1' || ptr->map[i][j] == '0')
			{
				*index = i;
				return ;
			}
			else if (ptr->map[i][j] != '\0' && ptr->map[i][j] != '\n'
				&& ptr->map[i][j] != ' ' && ptr->map[i][j] != '\t')
				ft_error_msgb(ptr);
			j++;
		}
		i++;
	}
}

void	ft_parse_1_mapb(t_map *ptr, int *index)
{
	int	i;
	int	j;

	i = *index;
	while (i < ptr->lenght && ptr->count != 6)
	{
		j = 0;
		while (ptr->map[i][j] != '\0')
		{
			if (ft_checkb_1_mapb(ptr, i, j) == 1)
				break ;
			else if (ft_checkb(ptr, i, j) == 1)
				ft_error_msgb(ptr);
			j++;
		}
		i++;
	}
	if (ptr->count != 6)
		ft_error_msgb(ptr);
	ft_checkb_after_mapb(ptr, &i);
	*index = i;
}

void	ft_parse_2_mapb(t_map *ptr, int *index)
{
	int	i;
	int	j;

	i = *index;
	while (i < ptr->lenght)
	{
		j = 0;
		while (ptr->map[i][j] != '\0')
		{
			if (ptr->map[i][j] == '1' || ptr->map[i][j] == '0')
			{
				ft_take_varb(ptr, &i);
				check_mapb_bb(ptr);
				ptr->flag_r = 1;
				*index = i - 1;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_checkb_after_map2b(t_map *ptr, int *index)
{
	int	j;
	int	i;

	i = *index;
	while (i < ptr->lenght)
	{
		j = 0;
		while (ptr->map[i][j] != '\0')
		{
			if (ptr->map[i][j] != '\n' && ptr->map[i][j] != '\t'
				&& ptr->map[i][j] != ' ')
				ft_error_msgb(ptr);
			j++;
		}
		i++;
	}
}

void	ft_parsing(t_map *ptr)
{
	int	i;

	i = 0;
	while (i < ptr->lenght && ptr->flag_r == 0)
	{
		ft_parse_1_mapb(ptr, &i);
		ft_parse_2_mapb(ptr, &i);
		i++;
	}
	if (ptr->var == NULL)
		ft_error_msgb(ptr);
	ft_checkb_after_map2b(ptr, &i);
}
