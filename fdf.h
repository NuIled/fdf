/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:39:30 by kikas             #+#    #+#             */
/*   Updated: 2023/04/20 13:17:20 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "stdio.h"
# include "stdlib.h"
# include "stdbool.h"
# include "get_next_line.h"
# include "mlx.h"
# include "math.h"
# define SCHIGHT 1000
# define SCWITH 1000
# define ANGLEX 30
# define ANGLEY 60

typedef struct map
{
	int	z;
	int	c;
}t_map;

typedef struct s_point
{
	float	x;
	float	y;
}t_pt;

typedef struct t_variabels
{
	float	maxzoom;
	float	mizoom;
}	t_vars;

typedef struct s_data
{
	t_map	**map;
	t_vars	vars;
	float	minzom;
	void	*img;
	bool	iso;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		sc;
	int		sv;
	int		hight;
	int		width;
	void	*mlxx;
	void	*mlx_win;
}t_data;

int		hexconv(char *s);
void	my_mlx_pixel_put(t_data *data, int y, int x, int color);
int		ft_isvalid(int x, int y, int x1, int y1);
void	draw(t_data *data);
int		callback(int key_code, t_data *data);
void	iso(float *x, float *y, int z, t_data *data);
void	drawnew(t_data *data);
int		wordcount(char **ret, char const *s, char c);
char	**ft_split(char const *s, char c);
void	ft_bzero(void *s, size_t n);
void	init(t_data *data, char **av);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t n);
void	getmap(char *file, t_data *data);
void	ft_readfile(char *file, t_data *data);

#endif