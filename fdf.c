/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:42:34 by kikas             #+#    #+#             */
/*   Updated: 2023/04/20 13:32:01 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scalemap(t_pt *pt, float *x1, float *y1, t_data *data)
{
	pt->x += (SCHIGHT / 2) + data->sc;
	*x1 += (SCHIGHT / 2) + data->sc;
	pt->y += (SCHIGHT / 3) + data->sv;
	*y1 += (SCHIGHT / 3) + data->sv;
}

void	drawer(t_data *data, t_pt pt, float y1, float x1)
{
	int		color;
	float	max;
	float	dx;
	float	dy;

	color = data->map[(int)pt.x][(int)pt.y].c;
	iso(&pt.x, & pt.y, data->map[(int)pt.x][(int)pt.y].z, data);
	iso(&x1, &y1, data->map[(int)x1][(int)y1].z, data);
	scalemap(&pt, &x1, &y1, data);
	dy = y1 - pt.y;
	dx = x1 - pt.x;
	max = fmax(fabs(dx), fabs(dy));
	dx /= max;
	dy /= max;
	while ((int)max--)
	{
		if (ft_isvalid(pt.x, pt.y, x1, y1))
			my_mlx_pixel_put(data, pt.y, pt.x, color);
		pt.x += dx;
		pt.y += dy;
	}
}

void	draw(t_data *data)
{
	t_pt	pt;

	pt.x = 0;
	while ((int)pt.x < data->hight)
	{
		pt.y = 0;
		while ((int)pt.y < data->width)
		{
			if (pt.y + 1 <= (data->width - 1))
				drawer(data, pt, pt.y + 1, pt.x);
			if (pt.x < (data->hight - 1) && (data->map[(int)pt.x + 1] != NULL))
				drawer(data, pt, pt.y, pt.x + 1);
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

int	main(int ac, char **av)
{
	t_data	*data;

	data = (t_data *)ft_calloc(sizeof(t_data), 1);
	if (ac != 2)
		perror("error");
	init(data, av);
	getdimention(data);
	data->mlxx = mlx_init();
	data->img = mlx_new_image(data->mlxx, SCWITH, SCHIGHT);
	data->mlx_win = mlx_new_window(data->mlxx, SCWITH, SCHIGHT, "fdf");
	data->addr = (int *)mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length,
			&data->endian);
	draw(data);
	mlx_hook(data->mlx_win, 2, 0, callback, data);
	mlx_put_image_to_window(data->mlxx, data->mlx_win, data->img, 0, 0);
	mlx_loop(data->mlxx);
}
