/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:04:49 by aoutifra          #+#    #+#             */
/*   Updated: 2023/03/30 15:47:43 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getline(char *s, int i)
{
	int		j;
	char	*d;

	j = 0;
	d = malloc (i + 1);
	if (!d)
		return (NULL);
	while (s[j] && j < i)
	{
		d[j] = s[j];
		j++;
	}
	d[j] = 0;
	return (d);
}

char	*ft_saver(char *s, int start)
{
	char	*remain;
	size_t	i;
	int		x;

	i = 0;
	x = start;
	remain = malloc(ft_strlen(s)-start +1);
	while (i < ft_strlen(s)-start)
	{
		remain[i] = s[x];
		i++;
		x++;
	}
	remain[i] = 0;
	return (free(s), remain);
}

char	*readline(int fd, char *str)
{
	char	dst[BUFFER_SIZE + 1];
	int		readed;

	readed = 1;
	while (ft_strchr(str, '\n') == 0 && readed >= 0)
	{
		readed = read(fd, dst, BUFFER_SIZE);
		if (readed == -1)
			return (free(str), NULL);
		if (!readed && !str)
			return (free(str), NULL);
		if (readed == 0)
			break ;
		dst[readed] = '\0';
		str = ft_strjoin(str, dst);
	}
	return (str);
}

char	*ft_clear(char **stat)
{
	free(*stat);
	*stat = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stat;
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (ft_clear(&stat));
	stat = readline(fd, stat);
	if (!stat)
		return (NULL);
	if (stat[0] == 0)
		return (ft_clear(&stat));
	while (stat[i] != '\0' && stat[i] != '\n')
		i++;
	if (stat[i] == '\n')
		i++;
	line = ft_getline(stat, i);
	stat = ft_saver(stat, i);
	return (line);
}
