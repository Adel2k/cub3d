# include "../include/cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	my_mlx_color_taker(t_img *data, int j, int i)
{
	char			*dst;

	if (j >= 0 && j < data->wd && i >= 0 && i < data->ht)
	{
		dst = data->addr + (i * data->line_length
				+ j * (data->bits_per_pixel / 8));
		return (*(unsigned int *)dst);
	}
	return (0);
}
