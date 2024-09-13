/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_raycasting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:30:18 by oqatim            #+#    #+#             */
/*   Updated: 2023/02/28 15:21:31 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	check_if_wall(t_map *var, int next_x, int next_y)
{
	int	y;
	int	x;

	x = (int)floor(next_x / T_S);
	y = (int)floor(next_y / T_S);
	if (y >= var->count_line)
		return (0);
	if (var->var[y] && x >= ft_strlen(var->var[y]))
		return (0);
	if (var->var[y][x] != '1')
		return (0);
	return (1);
}

void	my_img_pix_put2(t_map *var, int x, int y, int color)
{
	char	*pixel;

	pixel = var->full_img->addr + (y * var->full_img->line_len + \
		x * (var->full_img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	init_rest_of_txts(t_map *var)
{
	var->e_txt = mlx_xpm_file_to_image(var->init, \
		var->e_texture, &var->width_txt, \
			&var->height_txt);
	if (!var->e_txt)
		ft_error_msg(var);
	var->img_e->addr_i = (int *)mlx_get_data_addr(\
		var->e_txt, &var->img_e->bpp, \
		&var->img_e->line_len, &var->img_e->endian);
	var->w_txt = mlx_xpm_file_to_image(var->init, \
		var->w_texture, &var->width_txt, \
			&var->height_txt);
	if (!var->w_txt)
		ft_error_msg(var);
	var->img_w->addr_i = (int *)mlx_get_data_addr(var->w_txt, \
		&var->img_w->bpp, &var->img_w->line_len, \
			&var->img_w->endian);
}

void	init_txt_img(t_map *var)
{
	var->n_txt = mlx_xpm_file_to_image(var->init, var->n_texture, \
		&var->width_txt, &var->height_txt);
	if (!var->n_txt)
		ft_error_msg(var);
	var->img_n->addr_i = (int *)mlx_get_data_addr(var->n_txt, \
		&var->img_n->bpp, &var->img_n->line_len, \
			&var->img_n->endian);
	var->s_txt = mlx_xpm_file_to_image(var->init, var->s_texture, \
		&var->width_txt, &var->height_txt);
	if (!var->s_txt)
		ft_error_msg(var);
	var->img_s->addr_i = (int *)mlx_get_data_addr(var->s_txt, \
		&var->img_s->bpp, &var->img_s->line_len, \
			&var->img_s->endian);
	init_rest_of_txts(var);
}
