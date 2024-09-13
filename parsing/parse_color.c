/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:26:33 by oussama           #+#    #+#             */
/*   Updated: 2023/02/28 04:01:08 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_parse_color(char *str)
{
	int	i;

	i = 0;
	if (str[i])
	{
		if (ft_check_vergule(str) == 0
			&& ft_check_caracter(str) == 0
			&& ft_check_number(str) == 0)
			return (0);
		else
			return (1);
	}
	return (0);
}

void	get_rgb1(t_color *color, char **tableau)
{
	int	i;

	i = -1;
	color->r = ft_atoi(tableau[0]);
	color->g = ft_atoi(tableau[1]);
	color->b = ft_atoi(tableau[2]);
	while (tableau[++i])
		free(tableau[i]);
	free (tableau);
}

void	get_rgb(t_map *ptr, t_color *color, char *str)
{
	char	**tableau;
	int		i;
	int		len;
	int		j;

	i = 0;
	len = 0;
	tableau = malloc(sizeof(char *) * (ft_strlen(str) + 1));
	if (ft_parse_color(str) == 0)
	{
		while (str[i])
		{
			if (str[i] == ',')
				i++;
			j = i;
			while (str[i] != ',' && str[i])
				i++;
			tableau[len] = word_dup(str, j, i);
			len++;
		}
		tableau[len] = NULL;
	}
	else
		ft_error_msg(ptr);
	get_rgb1(color, tableau);
}

void	ft_norm_c(t_map *ptr, int i, int j)
{
	char	*c;
	char	**str;

	c = ft_strdup("C");
	str = ft_split_map(ptr, i, j);
	if (ft_strcmp(str[0], c) == 0 && ptr->flag_c == 0)
	{	
		get_rgb(ptr, ptr->c_color, str[1]);
		ft_free_split(str, c);
		ptr->count++;
		ptr->flag_c = 1;
		return ;
	}
	else if (ptr->flag_c == 1)
		ft_error_msg(ptr);
}

void	ft_norm_f(t_map *ptr, int i, int j)
{
	char	*f;
	char	**str;

	f = ft_strdup("F");
	str = ft_split_map(ptr, i, j);
	if (ft_strcmp(str[0], f) == 0 && ptr->flag_f == 0)
	{
		get_rgb(ptr, ptr->f_color, str[1]);
		ft_free_split(str, f);
		ptr->count++;
		ptr->flag_f = 1;
		return ;
	}
	else if (ptr->flag_f == 1)
		ft_error_msg(ptr);
}
