/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: By: aeminian <aeminian@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:56:58 by adel              #+#    #+#             */
/*   Updated: 2024/11/12 10:56:59 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3d.h"

void	draw_square(t_cub3d *cub, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			my_mlx_pixel_put(&cub->img, y + i, x + j, color);
			j++;
		}
		i++;
	}
}

int	draw_minimap(t_cub3d *cub)
{
	int	x;
	int	y;

	y = 0;
	while (cub->maze[y])
	{
		x = 0;
		while (cub->maze[y][x])
		{
			if (cub->maze[y][x] == '1')
				draw_square(cub, y * TILE_SIZE, x * TILE_SIZE, 0xFFFFFF);
			else if (cub->maze[y][x] == '0')
				draw_square(cub, y * TILE_SIZE, x * TILE_SIZE, 0x000000);
			else if (cub->maze[y][x] == 'D')
				draw_square(cub, y * TILE_SIZE, x * TILE_SIZE, 0xFF0000);
			else if (cub->maze[y][x] == 'O')
				draw_square(cub, y * TILE_SIZE, x * TILE_SIZE, 0x008000);
			x++;
		}
		y++;
	}
	draw_square(cub, (int)(cub->player->pos_x * TILE_SIZE),
		(int)(cub->player->pos_y * TILE_SIZE), 0x0000FF);
	return (0);
}
