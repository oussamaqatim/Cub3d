/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:46:03 by oqatim            #+#    #+#             */
/*   Updated: 2023/02/28 17:46:58 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	ft_checkb_double_vb(char *str)
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

int	ft_checkb_after_vb(char *str)
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

int	ft_checkb_verguleb(char *str)
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
	if (ft_checkb_double_vb(str))
		return (1);
	if (ft_checkb_after_vb(str))
		return (1);
	return (0);
}
