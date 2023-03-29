/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikas <kikas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:42:34 by kikas             #+#    #+#             */
/*   Updated: 2023/03/21 09:58:41 by kikas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_readfile(char *file, t_fdf *data)
{
    char* s;
    int i;
    i = 0;
    int fd = open(file,O_RDONLY,777);

    s = get_next_line(fd);
    data->width = wordcount(0,s,' ');
    while (get_next_line(fd))
        i++;
    data->hight = i;
    free(s);
    close(fd);
}

void getmap(char  *file,t_fdf *data,t_map **map)
{
    char *s;
    char **num;
    int fd = open(file,O_RDONLY,777);
    int i;
    int j;
    i = 0;
    j = 0;
    while (j < data->hight)
    {
        s = get_next_line(fd);
        num = ft_split(s,' ');
        i = 0 ;
        while (num[i])
            {
                map[j][i].z = atoi(num[i]);
                map[j][i].x = i;
                map[j][i].y = j;
                
                free(num[i]);
                i++;
            }
            free(num);
        j++;
    }
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (x * data->line_length + y * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void drawer (t_data img, int x ,int y ,int x1 ,int y1,int color)
{
    // while (x != x1)
    // {
        x += 20;
        x1 += 20;
        y += 20;
        y1 += 20;
        while (y != y1 && x != x1)
        {
          my_mlx_pixel_put(&img, x, y + 1, color); 
          my_mlx_pixel_put(&img, x + 1, y, color);
          y++;
          x++;
        }
    // }
}

int main (int ac, char **av)
{
    void	*mlx;
	void	*mlx_win;
    int i;
    int j;
    t_fdf *data;
    t_map **map;
	t_data	img;

    i = 0;
    if (ac != 2)
        perror("error");
    data = (t_fdf*)malloc (sizeof(t_fdf));
    ft_readfile(av[1], data);
    map = (t_map **)malloc(data->hight * sizeof(t_map));
    while (i <= data->width)
        map[i++] = malloc(sizeof(t_map)* data->width);
    getmap(av[1],data,map);
	mlx = mlx_init();
    
    mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world!");
	img.img = mlx_new_image(mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    i = 0;
    j = 0;
    while (i++ < data->hight)
        while(j++ < data->width)
            drawer(img,j,i,j+1,i+1,0x0FFFFFFF);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}