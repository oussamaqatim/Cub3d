/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:58:52 by oqatim            #+#    #+#             */
/*   Updated: 2023/02/28 17:59:22 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_double_v(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',' && str[i + 1] == ',')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_after_v(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			if ((str[i + 1] != '\0' && str[i + 1] != '\n'))
				i++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_vergule(char *str)
{
	int	i;
	int	v;

	i = 0;
	v = 0;
	while (str[i])
	{
		if (str[i] == ',')
			v++;
		i++;
	}
	if (v != 2)
		return (1);
	if (ft_check_double_v(str))
		return (1);
	if (ft_check_after_v(str))
		return (1);
	return (0);
}
