/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikas <kikas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 02:58:55 by aoutifra          #+#    #+#             */
/*   Updated: 2023/03/21 11:02:58 by kikas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *s, char c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = ft_strdup("");
	}
	if (s1 && s2)
	{
		res = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1));
		if (!res)
			return (NULL);
		i = -1;
		j = -1;
		while (s1[++i])
			res[i] = s1[i];
		while (s2[++j])
			res[i + j] = s2[j];
		res[i + j] = '\0';
		free(s1);
		return (res);
	}
	return (NULL);
}
