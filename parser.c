/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:41:12 by aoutifra          #+#    #+#             */
/*   Updated: 2023/04/19 16:55:39 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_readfile(char *file, t_data *data)
{
	char* s;
	int i;
	int fd;
	i = 0;
	fd = open(file, 0, 0777);
	s = get_next_line(fd);
	data->width = wordcount(0,s,' ');
	while (s)
	{
		i++;
		if (wordcount(0,s,' ') != data->width)
			perror("map d zeb");
		free (s);
		s = get_next_line(fd);
	}
	data->hight = i;
	free (s);
	close(fd); 
}

int hexconv(char *s)
{
	int i;
	int result;
	i = 2;
	result = 0;
	if (s[0] == '0')
		return(0xFF00F0);
	if(ft_strlen(s) < 8)
		return (0x00FA402);
	while (s[i])
	{
		if (s[i] >='a' && s[i] <= 'z')
			result = result * 16 + (s[i] - 'a' + 10);
		if (s[i] >='A' && s[i] <= 'Z')
			result = result * 16 + (s[i] - 'A' + 10);
		if (s[i] >='0' && s[i] <= '9')
			result = result * 16 + (s[i] - '0');
		i++;
	}
	return(result);
}

void getmap(char  *file,t_data *data)
{
	int i;
	int j;
	int fd;
	char *s;
	char **map;
	i = 0;
	fd = open(file, O_RDONLY, 0777);

	while (i < data->hight)
	{
		j = 0;
		s = get_next_line(fd);
		map = ft_split(s, ' ');
		while (j < data->width && map[j])
		{
			data->map[i][j].z = ft_atoi(map[j]);
			data->map[i][j].c = hexconv(map[j]);
			free(map[j]);
			j++;
		}
		i++;
		free(s);
	}
	free(map);
	close(fd);
}
