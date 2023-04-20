/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:42:34 by kikas             #+#    #+#             */
/*   Updated: 2023/04/20 11:07:39 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scalemap(float *x, float *y, float *x1, float *y1, t_data *data)
{
	*x += (SCHIGHT / 2) + data->sc;
	*x1 += (SCHIGHT / 2) + data->sc;
	*y += (SCHIGHT / 3) + data->sv;
	*y1 += (SCHIGHT / 3) + data->sv;
}

void	drawer(t_data *data, t_pt pt, float x1, float y1)
{
	int		color;
	float	max;
	float	dx;
	float	dy;
	color = data->map[(int)pt.x][(int)pt.y].c;
	iso(&pt.x, & pt.y, data->map[(int)pt.x][(int)pt.y].z, data);
	iso(&x1, &y1, data->map[(int)x1][(int)y1].z, data);
	scalemap(&pt.x, &pt.y, &x1, &y1, data);
	dy = y1 -  pt.y;
	dx = x1 -  pt.x;
	max = fmax(fabs(dx), fabs(dy));
	dx /= max;
	dy /= max;
	while ((int)max--)
	{
		if (ft_isvalid(pt.x,pt.y, x1, y1))
			my_mlx_pixel_put(data, pt.x,pt.y, color);
		pt.x += dx;
		pt.y += dy;
	}
}

void	draw(t_data *data)
{
	t_pt pt;

	pt.x = 0;
	while ((int)pt.x < data->hight)
	{
		pt.y = 0;
		while((int)pt.y < data->width)
		{
			if(pt.y + 1 <= (data->width - 1))
				drawer(data, pt,pt.x, pt.y + 1);
			if(pt.x < (data->hight - 1) && (data->map[(int)pt.x + 1] != NULL))
				drawer(data, pt, pt.x + 1, pt.y);
		pt.y++;
		}
	pt.x++;
	}
}

void	getdimention(t_data *data)
{
	data->vars.mizoom = 1;
	data->sc = 0;
	data->sv = 0;
	data->iso = 1;
	if (data->width < 22)
	{
		data->minzom = 5;
		data->vars.maxzoom = 5;
	}
	if (data->width > 20)
	{
		data->minzom = 1;
		data->vars.maxzoom = 0.5;
	}
}

void	init(t_data *data, char **av)
{
	int i;
	int j;

	j = 0;
	i = -1;
	ft_readfile(av[1], data);
	data->map = (t_map **)ft_calloc((data->hight + 1), sizeof(t_map *));
	while (++i < data->hight)
		data->map[i] = (t_map *)ft_calloc(sizeof(t_map), (data->width + 1));
	data->map[i] = NULL;
	getmap(av[1], data);
}

int main (int ac, char **av)
{
   
	t_data *data;
	data = (t_data *)ft_calloc(sizeof(t_data),1);
	if (ac != 2)
		perror("error");
	init(data, av);
	getdimention(data);
	data->mlxx = mlx_init();
	data->img = mlx_new_image(data->mlxx, SCWITH, SCHIGHT);
	data->mlx_win = mlx_new_window(data->mlxx,SCWITH,SCHIGHT ,"Hello world!");
	data->addr = (int *)mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,
								&data->endian);
	draw(data);
	mlx_hook(data->mlx_win, 2, 0, callback, data);
	mlx_put_image_to_window(data->mlxx, data->mlx_win, data->img, 0, 0);
	mlx_loop(data->mlxx);
}
