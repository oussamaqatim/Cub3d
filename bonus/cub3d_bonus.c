/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:44:25 by oussama           #+#    #+#             */
/*   Updated: 2023/02/28 17:37:32 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	check_extention_b(char *file)
{
	size_t	len;

	len = ft_strlenb(file);
	if (file[len - 4] == '.')
		if (file[len - 3] == 'c')
			if (file[len - 2] == 'u')
				if (file[len - 1] == 'b')
					return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	print_map_b(void *var)
{
	draw_all_b((t_map *)var);
	move_player_b((t_map *)var);
	return (1);
}

void	set_map_size_b(t_map *var)
{
	int	next;
	int	y;

	y = 0;
	var->max_len = ft_strlenb(var->var[0]);
	while (++y < var->count_line)
	{
		next = ft_strlenb(var->map[y]);
		if (var->max_len < next)
			var->max_len = next;
	}
	var->width = 1080;
	var->height = 1080;
}

void	ft_back_bone(t_map *map)
{
	map->init = mlx_init();
	set_map_size_b(map);
	map->win = mlx_new_window(map->init, \
	map->width, map->height, "Cub3D");
	map->c_coleur = create_rgb_b(map->c_color->r, \
	map->c_color->g, map->c_color->b);
	map->f_coleur = create_rgb_b(map->f_color->r, \
	map->f_color->g, map->f_color->b);
	init_txt_img_b(map);
	mlx_hook(map->win, 17, 0, ft_exit_b, map);
	mlx_hook(map->win, 2, 0, key_press_b, map);
	mlx_hook(map->win, 3, 0, key_release_b, map);
	mlx_hook(map->win, 6, 64, init_mouse_b, map);
	mlx_loop_hook(map->init, print_map_b, map);
	mlx_loop(map->init);
}

int	main(int ac, char **av)
{
	t_map	*map;
	int		fd;
	int		i;

	i = -1;
	if (ac != 2)
	{
		printf("Invalid Arguments\n");
		exit(1);
	}
	map = malloc(sizeof(t_map));
	if (check_extention_b(av[1]) == EXIT_FAILURE)
		puts("Wrong extention.\n");
	init_mapb(map, av[1]);
	check_mapb(map);
	fd = open (map->file_map, O_RDONLY);
	map->map = (char **)malloc(sizeof(char *) * map->lenght);
	while (++i < map->lenght)
		map->map[i] = get_next_linebb(fd);
	ft_parsing(map);
	ft_back_bone(map);
	return (0);
}
