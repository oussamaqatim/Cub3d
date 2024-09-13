/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:49:44 by oqatim            #+#    #+#             */
/*   Updated: 2023/02/28 17:44:27 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	ft_error_msgb(t_map *ptr)
{
	printf("Error : Map\n");
	ft_free_mapb(ptr);
	exit(1);
}

void	ft_free_splitb(char **str, char *ptr)
{
	int	i;

	i = -1;
	while (str[++i])
		free (str[i]);
	free (str);
	if (ptr)
		free (ptr);
}

void	ft_free_structb(t_map *map)
{
	free (map->c_color);
	free (map->f_color);
	free (map->ray);
	free (map->full_img);
	free (map->img_s);
	free (map->img_n);
	free (map->img_w);
	free (map->img_e);
}

void	ft_free_mapb(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->lenght)
		free (map->map[i]);
	free (map->map);
	if (map->n_texture)
		free (map->n_texture);
	if (map->s_texture)
		free (map->s_texture);
	if (map->e_texture)
		free (map->e_texture);
	if (map->w_texture)
		free (map->w_texture);
	if (map->var)
	{
		i = -1;
		while (map->var[++i])
			free (map->var[i]);
		free (map->var);
	}
	ft_free_structb(map);
	free (map);
}
