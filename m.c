#include "stdio.h"
#include "stdlib.h"
#include "mlx.h"
#include "unistd.h"
#include "get_next_line.h"
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int ac ,char **av)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int i = 0;
	int j = 0;
	int b= 0;
	char *s;
	s =ft_strdup("");
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1100, 1100, "Hello world!");
	img.img = mlx_new_image(mlx, 1100, 1100);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	int fd = open(av[1],O_RDONLY);
	while (++i < 11)
		s = ft_strjoin(s,get_next_line(fd));
	printf("\n%i\n",img.endian);
	i = 0;
	// while(i <= 300) 
	// 	{
	// 		j = 0;
	// 		while(s[b] != '\n' && j < 300) 
	// 		{
	// 			if(s[b] == '0')
					// {
					for (int j = 0; j < 500; j++)
						for (int i = 0; i < 500; i++)
							my_mlx_pixel_put(&img, j, i, 0x00FF0000);
					
						// my_mlx_pixel_put(&img, j-1, i+1, 0x00FF0000);
						// my_mlx_pixel_put(&img, j, i+1, 0x00FF0000);
		// 			}
		// 		j++;
		// 		if ((j / 10) == 0)
		// 			b++;
		// 	}
		// 	i+=10;
		// 	b++;
		// }
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
