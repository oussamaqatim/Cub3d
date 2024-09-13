/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utilis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:29:52 by oqatim            #+#    #+#             */
/*   Updated: 2023/02/28 16:43:21 by oqatim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

char	*get_next_linebb(int fd)
{
	char	buff[2];
	char	*line;
	int		n;
	void	*d_ptr;

	if (fd < 0)
		return (NULL);
	buff[0] = 0;
	buff[1] = 0;
	line = ft_strdupb("");
	n = 1;
	while (n > 0)
	{
		n = read(fd, buff, 1);
		if (n <= 0)
			continue ;
		d_ptr = line;
		line = ft_strjoinb(line, buff);
		free(d_ptr);
		if (buff[0] == '\n')
			return (line);
	}
	if (line && !*line)
		return (free(line), NULL);
	return (line);
}

char	*ft_strdupb(char *str)
{
	char	*ptr;
	int		len;
	int		i;

	i = -1;
	len = get_lenghtb(str, '\0');
	ptr = malloc(sizeof(char) * (len + 1));
	while (str[++i] != '\0')
		ptr[i] = str[i];
	ptr[i] = '\0';
	return (ptr);
}

int	get_lenghtb(char *ln, char c)
{
	int	i;

	i = 0;
	if (ln == NULL)
		return (0);
	while (ln[i] && ln[i] != c)
		i++;
	return (i);
}

char	*ft_strjoinb(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdupb(s2));
	p = malloc(sizeof(char) * (ft_strlenb(s1) + ft_strlenb(s2) + 1));
	if (!p)
		return (NULL);
	while (s1[i] != '\0')
		p[j++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		p[j++] = s2[i++];
	}
	p[j] = '\0';
	return (p);
}

int	ft_strlenb(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
