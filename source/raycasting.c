/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: By: aeminian <aeminian@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:57:01 by adel              #+#    #+#             */
/*   Updated: 2024/11/12 10:57:02 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3d.h"

void	draw_floor(t_cub3d *cub)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cub->mlx.height / 2)
	{
		j = -1;
		while (++j < cub->mlx.width)
			my_mlx_pixel_put(&cub->img, j, i, cub->C_color);
	}
	while (++i < cub->mlx.height - 1)
	{
		j = -1;
		while (++j < cub->mlx.width)
			my_mlx_pixel_put(&cub->img, j, i, cub->F_color);
	}
}

void	raycasting(t_cub3d *cub)
{
	int		w;

	draw_floor(cub);
	w = -1;
	anim(cub);
	while (++w <= cub->mlx.width)
	{

		ray_pos(cub, w);
		step_dir(cub);
		cub->ray.hit = 0;
		dda_algorithm(cub);
	// printf(">>2>>>> %d\n", w);
		draw_texture(cub, w, calc_texture_x(cub));
	// printf(">>>>>> %d\n", calc_texture_x(cub));

	}
	anim(cub);
	if (cub->hiding_map == 1)
		// draw_minimap(cub);
	mlx_put_image_to_window(cub->mlx.ptr, cub->mlx.win, cub->img.img, 0, 0);
}
