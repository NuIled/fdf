/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikas <kikas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:39:30 by kikas             #+#    #+#             */
/*   Updated: 2023/03/21 09:52:29 by kikas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "stdlib.h"
#include "get_next_line.h"
#include "mlx.h"

typedef struct map
{
    int x;
    int y;
    int z;
}t_map;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct fdf
{
    t_map *map;
    
    int hight;
    int width;
} t_fdf;

int	wordcount(char **ret, char const *s, char c);
char	**ft_split(char const *s, char c);
void	ft_bzero(void *s, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);