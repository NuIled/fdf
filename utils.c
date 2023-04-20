/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:19:25 by aoutifra          #+#    #+#             */
/*   Updated: 2023/04/20 13:31:13 by aoutifra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int y, int x, int color)
{
	int	*dst;

	dst = data->addr + (x * SCHIGHT + y);
	*(unsigned int *)dst = color;
}

void	iso(float *y, float *x, int z, t_data *data)
{
	float	c;

	c = *x;
	if (data->iso)
	{
		if (z >= 10)
			z = 2;
		else if (z < 0)
			z = -3;
		*x = ((*x - *y) * cos (ANGLEX * M_PI / 180) * data->minzom) * 2;
		*y = (c + *y - z) * sin (ANGLEY * M_PI / 180) * data->minzom;
	}
	else
	{
		*x *= data->minzom;
		*y *= data->minzom;
	}
}

int	ft_isvalid(int x, int y, int x1, int y1)
{
	if ((x1 < SCHIGHT && x1 > 0) && (y1 < SCHIGHT && y1 > 0)
		&& (x < SCWITH && x >= 0) && (y < SCWITH && y >= 0))
		return (1);
	return (0);
}

void	drawnew(t_data *data)
{
	mlx_destroy_image(data->mlxx, data->img);
	data->img = mlx_new_image(data->mlxx, SCWITH, SCHIGHT);
	data->addr = (int *)mlx_get_data_addr(data->img,
			&data->bits_per_pixel, &data->line_length,
			&data->endian);
	draw(data);
	mlx_put_image_to_window(data->mlxx, data->mlx_win, data->img, 0, 0);
}

int	callback(int key_code, t_data *data)
{
	if (key_code == 34)
		data->iso = 1;
	if (key_code == 45)
		data->iso = 0;
	if (key_code == 124)
		data->sv += 10;
	if (key_code == 123)
		data->sv -= 10;
	if (key_code == 125)
		data->sc += 10;
	if (key_code == 126)
		data->sc -= 10;
	if (key_code == 69 && (data->minzom + data->vars.maxzoom)
		> data->vars.mizoom)
		data->minzom += data->vars.maxzoom;
	if (key_code == 78 && (data->minzom - data->vars.maxzoom)
		> data->vars.mizoom)
		data->minzom -= data->vars.maxzoom;
	if (key_code == 53)
		exit(0);
	drawnew(data);
	return (0);
}
