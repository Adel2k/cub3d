/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: By: aeminian <aeminian@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:56:07 by adel              #+#    #+#             */
/*   Updated: 2024/11/12 10:56:08 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3d.h"

void	ray_pos(t_cub3d *cub, int w)
{
	cub->ray.camera_x = 2.0 * w / (double)cub->mlx.width - 1.0;
	cub->ray.ray_x = cub->player.dir_x
		+ cub->player.plane_x * cub->ray.camera_x;
	cub->ray.ray_y = cub->player.dir_y
		+ cub->player.plane_y * cub->ray.camera_x;
	cub->player.map_x = (int)cub->player.pos_x;
	cub->player.map_y = (int)cub->player.pos_y;
	if (cub->ray.ray_x == 0)
		cub->ray.deltadist_x = 1e30;
	else
		cub->ray.deltadist_x = fabs(1 / cub->ray.ray_x);
	if (cub->ray.ray_y == 0)
		cub->ray.deltadist_y = 1e30;
	else
		cub->ray.deltadist_y = fabs(1 / cub->ray.ray_y);
	
}

void	step_dir(t_cub3d *cub)
{
	if (cub->ray.ray_x < 0)
	{
		cub->player.step_x = -1;
		cub->ray.sdist_x = (cub->player.pos_x - cub->player.map_x)
			* cub->ray.deltadist_x;
	}
	else
	{
		cub->player.step_x = 1;
		cub->ray.sdist_x = (cub->player.map_x + 1.0 - cub->player.pos_x)
			* cub->ray.deltadist_x;
	}
	if (cub->ray.ray_y < 0)
	{
		cub->player.step_y = -1;
		cub->ray.sdist_y = (cub->player.pos_y - cub->player.map_y)
			* cub->ray.deltadist_y;
	}
	else
	{
		cub->player.step_y = 1;
		cub->ray.sdist_y = (cub->player.map_y + 1.0 - cub->player.pos_y)
			* cub->ray.deltadist_y;
	}
}

void	calc_draw_ends(t_cub3d *cub, t_draw *tex)
{
	// printf(">>>>>> %d\n", tex->tex_y);
	// printf(">>>>>> %p\n", tex);

	tex->line_height = (int)(cub->mlx.height / cub->ray.perp_wall_dist);
	tex->draw_start = -tex->line_height / 2 + cub->mlx.height / 2;
	if (tex->draw_start < 0)
		tex->draw_start = 0;
	tex->draw_end = tex->line_height / 2 + cub->mlx.height / 2;
	if (tex->draw_end >= cub->mlx.height)
		tex->draw_end = cub->mlx.height - 1;
	tex->step = 1.0 * 64 / tex->line_height;
	tex->tex_pos = (tex->draw_start - cub->mlx.height / 2 + tex->line_height / 2)
		* tex->step;
	// printf(">>>>>> %d\n", tex->tex_x);
}

int	calc_texture_x(t_cub3d *cub)
{
	int		tex_x;
	double	wall_x;

	// printf("---pos---- %f\n", cub->player.pos_x);
	// printf("----perp--- %f\n", cub->ray.perp_wall_dist);
	// printf("---ray---- %f\n", cub->ray.ray_x);
	wall_x = cub->player.pos_x + cub->ray.perp_wall_dist * cub->ray.ray_x;
	if (cub->ray.side == 0)
		wall_x = cub->player.pos_y + cub->ray.perp_wall_dist * cub->ray.ray_y;
	wall_x -= floor((wall_x));
	tex_x = (int)(wall_x * (double)(64));
	if ((cub->ray.side == 0 && cub->ray.ray_x > 0)
		|| (cub->ray.side == 1 && cub->ray.ray_y < 0))
		tex_x = 64 - tex_x - 1;
	return (tex_x);
}

void	dda_algorithm(t_cub3d *cub)
{
	while (cub->ray.hit == 0)
	{
		if (cub->ray.sdist_x < cub->ray.sdist_y)
		{
			cub->ray.sdist_x += cub->ray.deltadist_x;
			cub->player.map_x += cub->player.step_x;
			cub->ray.side = 0;
		}
		else
		{
			cub->ray.sdist_y += cub->ray.deltadist_y;
			cub->player.map_y += cub->player.step_y;
			cub->ray.side = 1;
		}
		if (cub->maze[cub->player.map_x][cub->player.map_y] == '1')
			cub->ray.hit = 1;
		else if (cub->maze[cub->player.map_x][cub->player.map_y] == 'D')
			cub->ray.hit = 2;
		else if (cub->maze[cub->player.map_x][cub->player.map_y] == 'O')
			cub->ray.hit = 3;
	}
	if (cub->ray.side == 0)
		cub->ray.perp_wall_dist = (cub->ray.sdist_x - cub->ray.deltadist_x);
	else
		cub->ray.perp_wall_dist = (cub->ray.sdist_y - cub->ray.deltadist_y);
}
