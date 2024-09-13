/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utilis3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:41:27 by oqatim            #+#    #+#             */
/*   Updated: 2023/02/28 15:11:26 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_isdigit(char *s)
{
	int	i;
	int	r;

	i = ft_atoi(s);
	if (i < 0 || i > 255)
		return (free(s), 1);
	while (i >= 10)
	{
		r = i % 10;
		if (r >= 0 && r <= 9)
			i = i / 10;
		else
			return (free(s), 1);
	}
	if (i >= 0 && i <= 9)
		return (free(s), 0);
	else
		return (free(s), 1);
}

char	*word_dup(char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * ((finish - start) + 1));
	if (!word)
		exit(1);
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

int	get_lenght_map(char *ln, int i, char c)
{
	if (ln == NULL)
		return (0);
	while (ln[i] && ln[i] != c)
		i++;
	return (i);
}

char	**ft_split_map(t_map *map, int i, int j)
{
	char	**tableau;
	char	*str;
	int		len;
	int		x;

	tableau = (char **)malloc(sizeof(char *) * 3);
	len = get_lenght_map(map->map[i], j, ' ');
	x = 0;
	str = malloc(sizeof(char) * (len + 1));
	while (map->map[i][j] != ' ' && map->map[i][j] != '\n')
		str[x++] = map->map[i][j++];
	str[x] = '\0';
	while (map->map[i][j] == ' ')
		j++;
	tableau[1] = NULL;
	if (map->map[i][j] != '\n' || map->map[i][j] != '\0')
		tableau[1] = word_dup(map->map[i], j, ft_strlen(map->map[i]) - 1);
	tableau[0] = ft_strdup(str);
	tableau[2] = NULL;
	free(str);
	return (tableau);
}
