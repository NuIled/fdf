/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikas <kikas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 10:08:29 by aoutifra          #+#    #+#             */
/*   Updated: 2023/03/21 10:59:51 by kikas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*sr;

	i = 0;
	sr = (char *)(s);
	while (n > i)
	{
		sr[i] = 0;
		i++;
	}
}
int	wordcount(char **ret, char const *s, char c)
{
	int		i;
	int		count;

	count = 0;
	while (s[0])
	{
		i = 0;
		while (s[i] && (s[i] != c))
			i++;
		if (ret)
			ret[count] = ft_substr(s, 0, i);
		if (ret && ret[count] == NULL)
			return (-1);
		count++;
		while (s[i] && (s[i] == c))
			i++;
		s = s + i;
	}
	return (count);
}