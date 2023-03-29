/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikas <kikas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 04:39:27 by aoutifra          #+#    #+#             */
/*   Updated: 2023/03/21 10:02:22 by kikas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_calloc(size_t count, size_t n)
{
	void	*s;

	s = malloc(count * n);
	if (s == 0)
		return (NULL);
	ft_bzero (s, n * count);
	return (s);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;

	unsigned char *(d);
	unsigned char *(s);
	i = 0;
	d = (unsigned char *)(dest);
	s = (unsigned char *)(src);
	if (*d == '\0' && *s == '\0')
		return (NULL);
	if (d > s)
	{
		while (n > 0)
		{
			--n;
			d[n] = s[n];
		}
	}
	while (n > i)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (s_len <= start)
		start = s_len;
	if (s_len - start < len)
		len = s_len - start;
	sub = ft_calloc(len + 1, sizeof(char));
	if (sub && len)
		ft_memmove(sub, s + start, len);
	return (sub);
}

static int	my_spliter(char **ret, char const *s, char c)
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

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**ret;

	if (!s)
		return (0);
	while (*s && *s == c)
		s++;
	if (!*s)
		return (ft_calloc(1, sizeof(char *)));
	ret = ft_calloc(my_spliter(0, s, c) + 1, sizeof(char *));
	if (my_spliter(ret, s, c) < 0)
	{
		i = 0;
		while (ret[i])
			free(ret[i++]);
		free(ret);
		return (NULL);
	}
	return (ret);
}
