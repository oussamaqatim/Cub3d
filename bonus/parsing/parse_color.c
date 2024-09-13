/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:26:33 by oussama           #+#    #+#             */
/*   Updated: 2023/02/28 15:45:18 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	ft_parse_colorb(char *str)
{
	int	i;

	i = 0;
	if (str[i])
	{
		if (ft_checkb_verguleb(str) == 0
			&& ft_checkb_caracterb(str) == 0
			&& ft_checkb_numberb(str) == 0)
			return (0);
		else
			return (1);
	}
	return (0);
}

void	get_rgbb1b(t_color *color, char **tableau)
{
	int	i;

	i = -1;
	color->r = ft_atoib(tableau[0]);
	color->g = ft_atoib(tableau[1]);
	color->b = ft_atoib(tableau[2]);
	while (tableau[++i])
		free(tableau[i]);
	free (tableau);
}

void	get_rgbb(t_map *ptr, t_color *color, char *str)
{
	char	**tableau;
	int		i;
	int		len;
	int		j;

	i = 0;
	len = 0;
	tableau = malloc(sizeof(char *) * (ft_strlenb(str) + 1));
	if (ft_parse_colorb(str) == 0)
	{
		while (str[i])
		{
			if (str[i] == ',')
				i++;
			j = i;
			while (str[i] != ',' && str[i])
				i++;
			tableau[len] = word_dupb(str, j, i);
			len++;
		}
		tableau[len] = NULL;
	}
	else
		ft_error_msgb(ptr);
	get_rgbb1b(color, tableau);
}

void	ft_norm_c(t_map *ptr, int i, int j)
{
	char	*c;
	char	**str;

	c = ft_strdupb("C");
	str = ft_split_mapb(ptr, i, j);
	if (ft_strcmpb(str[0], c) == 0 && ptr->flag_c == 0)
	{	
		get_rgbb(ptr, ptr->c_color, str[1]);
		ft_free_splitb(str, c);
		ptr->count++;
		ptr->flag_c = 1;
		return ;
	}
	else if (ptr->flag_c == 1)
		ft_error_msgb(ptr);
}

void	ft_norm_f(t_map *ptr, int i, int j)
{
	char	*f;
	char	**str;

	f = ft_strdupb("F");
	str = ft_split_mapb(ptr, i, j);
	if (ft_strcmpb(str[0], f) == 0 && ptr->flag_f == 0)
	{
		get_rgbb(ptr, ptr->f_color, str[1]);
		ft_free_splitb(str, f);
		ptr->count++;
		ptr->flag_f = 1;
		return ;
	}
	else if (ptr->flag_f == 1)
		ft_error_msgb(ptr);
}
