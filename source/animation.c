/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel <adel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:56:14 by adel              #+#    #+#             */
/*   Updated: 2024/11/12 11:02:05 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3d.h"

void	anim(t_cub3d *cub)
{
	static int	i;
	static int	count;

	if (count % 5 == 0)
	{
		print_gun(cub, i);
		i++;
		if (i == 5)
			i = 0;
	}
	count++;
	if (count >= 150000)
		count = 0;
}

void	print_gun(t_cub3d *cub, int i)
{
	int	x;
	int	y;
	int	px;
	int	py;

	px = 0;
	x = cub->img.wd / 2 - cub->gun[i].wd / 2 - 1;
	while (++x < cub->img.wd / 2 + cub->gun[i].wd / 2)
	{
		y = cub->img.ht - cub->gun[i].ht - 1;
		py = 0;
		while (++y < cub->img.ht)
		{
			my_mlx_pixel_put(&cub->img, x, y,
				my_mlx_color_taker(&cub->gun[i], px, py));
			py++;
		}
		px++;
	}
}
