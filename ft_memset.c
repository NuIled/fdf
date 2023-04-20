#include "fdf.h"
void	*ft_memset(void *b, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;

	i = 0;
	d = (unsigned char *)(b);
	while (n > i)
	{
		d[i] = (unsigned char)c;
		i++;
	}
	return (d);
}