/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_txt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:55:24 by oqatim            #+#    #+#             */
/*   Updated: 2023/02/28 15:45:18 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	get_map_textureb(t_map *ptr, char c)
{
	if (c == 'e')
	{
		if (open(ptr->e_texture, O_RDONLY) == -1)
			ft_error_msgb(ptr);
	}
	if (c == 'n')
	{
		if (open(ptr->n_texture, O_RDONLY) == -1)
			ft_error_msgb(ptr);
	}
	if (c == 'w')
	{
		if (open(ptr->w_texture, O_RDONLY) == -1)
			ft_error_msgb(ptr);
	}
	if (c == 's')
	{
		if (open(ptr->s_texture, O_RDONLY) == -1)
			ft_error_msgb(ptr);
	}		
}

void	ft_norm_eab(t_map *ptr, int i, int j)
{
	char	**str;

	str = ft_split_mapb(ptr, i, j);
	if (ft_strcmpb(str[0], "EA") == 0 && ptr->flag_ea == 0)
	{
		ptr->e_texture = ft_strdupb(str[1]);
		get_map_textureb(ptr, 'e');
		ft_free_splitb(str, NULL);
		ptr->count++;
		ptr->flag_ea = 1;
		return ;
	}
	else if (ptr->flag_ea == 1)
		ft_error_msgb(ptr);
}

void	ft_norm_web(t_map *ptr, int i, int j)
{
	char	**str;

	str = ft_split_mapb(ptr, i, j);
	if (ft_strcmpb(str[0], "WE") == 0 && ptr->flag_we == 0)
	{	
		ptr->w_texture = ft_strdupb(str[1]);
		get_map_textureb(ptr, 'w');
		ft_free_splitb(str, NULL);
		ptr->count++;
		ptr->flag_we = 1;
		return ;
	}
	else if (ptr->flag_we == 1)
		ft_error_msgb(ptr);
}

void	ft_norm_sob(t_map *ptr, int i, int j)
{
	char	**str;

	str = ft_split_mapb(ptr, i, j);
	if (ft_strcmpb(str[0], "SO") == 0 && ptr->flag_so == 0)
	{	
		ptr->s_texture = ft_strdupb(str[1]);
		get_map_textureb(ptr, 's');
		ft_free_splitb(str, NULL);
		ptr->count++;
		ptr->flag_so = 1;
		return ;
	}
	else if (ptr->flag_so == 1)
		ft_error_msgb(ptr);
}

void	ft_norm_nob(t_map *ptr, int i, int j)
{
	char	**str;

	str = ft_split_mapb(ptr, i, j);
	if (ft_strcmpb(str[0], "NO") == 0 && ptr->flag_no == 0)
	{	
		ptr->n_texture = ft_strdupb(str[1]);
		get_map_textureb(ptr, 'n');
		ft_free_splitb(str, NULL);
		ptr->count++;
		ptr->flag_no = 1;
		return ;
	}
	else if (ptr->flag_no == 1)
		ft_error_msgb(ptr);
}
