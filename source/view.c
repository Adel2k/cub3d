/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: By: aeminian <aeminian@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:57:29 by adel              #+#    #+#             */
/*   Updated: 2024/11/12 10:57:30 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3d.h"

void	rotate_view(t_cub3d *cub, double prevdir_x,
	double prevplane_x, double rotate)
{
	cub->player->dir_x = cub->player->dir_x * cos(rotate)
		- cub->player->dir_y * sin(rotate);
	cub->player->dir_y = prevdir_x * sin(rotate)
		+ cub->player->dir_y * cos(rotate);
	cub->player->plane_x = cub->player->plane_x * cos(rotate)
		- cub->player->plane_y * sin(rotate);
	cub->player->plane_y = prevplane_x * sin(rotate)
		+ cub->player->plane_y * cos(rotate);
}

void	change_view(t_cub3d *cub, int side, double rotate)
{
	double	prevplane_x;
	double	prevdir_x;

	prevdir_x = cub->player->dir_x;
	prevplane_x = cub->player->plane_x;
	if (side == RARROW)
		rotate_view(cub, prevdir_x, prevplane_x, -rotate);
	else
		rotate_view(cub, prevdir_x, prevplane_x, rotate);
}

void	get_dir(t_cub3d *cub)
{
	if (cub->player->dir_x <= 0 && cub->player->dir_y >= 0)
	{
		cub->player->dir_x = 1 - pow(cub->player->dir_x, 2);
		cub->player->dir_y = 1 - pow(cub->player->dir_y, 2);
	}
	else if (cub->player->dir_x >= 0 && cub->player->dir_y >= 0)
	{
		cub->player->dir_x = 1 - pow(cub->player->dir_x, 2);
		cub->player->dir_y = -(1 - pow(cub->player->dir_y, 2));
	}
	else if (cub->player->dir_x >= 0 && cub->player->dir_y <= 0)
	{
		cub->player->dir_x = -(1 - pow(cub->player->dir_x, 2));
		cub->player->dir_y = -(1 - pow(cub->player->dir_y, 2));
	}
	else
	{
		cub->player->dir_x = -(1 - pow(cub->player->dir_x, 2));
		cub->player->dir_y = 1 - pow(cub->player->dir_y, 2);
	}
}
