/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: By: aeminian <aeminian@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:56:26 by adel              #+#    #+#             */
/*   Updated: 2024/11/12 10:56:27 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3d.h"

// void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// unsigned int	my_mlx_color_taker(t_img *data, int j, int i)
// {
// 	char			*dst;

// 	if (j >= 0 && j < data->wd && i >= 0 && i < data->ht)
// 	{
// 		dst = data->addr + (i * data->line_length
// 				+ j * (data->bits_per_pixel / 8));
// 		return (*(unsigned int *)dst);
// 	}
// 	return (0);
// }

// t_img	*choose_texture(t_cub3d *cub)
// {
// 	if (cub->ray.hit == 2)
// 		return (&cub->cdoor);
// 	else if (cub->ray.hit == 3)
// 		return (&cub->odoor);
// 	else if (cub->ray.side == 1 && cub->ray.ray_y <= 0)
// 		return (cub->wall);
// 	else if (cub->ray.side == 0 && cub->ray.ray_x > 0)
// 		return (cub->wall + 1);
// 	else if (cub->ray.side == 0 && cub->ray.ray_x <= 0)
// 		return (cub->wall + 2);
// 	return (cub->wall + 3);
// }

// void	draw_texture(t_cub3d *cub, int x, int tex_x)
// {
// 	t_draw			tex;
// 	int				y;

// 	if (cub->ray.perp_wall_dist < 0.000001)
// 		cub->ray.perp_wall_dist = 0.000001;
// 	calc_draw_ends(cub, &tex);
// 	y = tex.draw_start - 1;
// 	while (++y < tex.draw_end)
// 	{
// 		tex.tex_y = (int)tex.tex_pos & (63);
// 		tex.tex_pos += tex.step;
// 		my_mlx_pixel_put(&cub->img, x, y,
// 			my_mlx_color_taker(choose_texture(cub), tex_x, tex.tex_y));
// 	}
// }