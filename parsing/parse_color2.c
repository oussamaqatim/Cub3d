/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:31:05 by oqatim            #+#    #+#             */
/*   Updated: 2023/02/28 17:58:16 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_map(t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map->file_map, O_RDONLY);
	if (fd == -1)
	{
		printf("Map error\n");
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		map->lenght++;
	}
	free (line);
}

int	ft_check_caracter(char *str)
{
	int	i;

	i = 0;
	if (str[i])
	{
		while (str[i] != '\n' && str[i] != '\0')
		{
			if ((str[i] >= 48 && str[i] <= 57) || str[i] == ',')
				i++;
			else
				return (1);
		}
	}	
	return (0);
}

int	ft_check_str(char *str)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{	
		if (str[i] == ',')
			i++;
		j = i;
		while (str[i] != ',' && str[i])
			i++;
		ptr = word_dup(str, j, i);
		if (ft_isdigit(ptr) == 0)
		{
			if (str[i] == ',')
				i++;
			else
				break ;
		}
		else
			return (1);
	}
	return (0);
}

int	ft_check_number(char *str)
{
	if (str[0])
	{
		if (ft_check_str(str))
			return (1);
	}
	return (0);
}
