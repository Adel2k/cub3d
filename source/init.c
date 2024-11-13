/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: By: aeminian <aeminian@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:56:40 by adel              #+#    #+#             */
/*   Updated: 2024/11/12 10:56:41 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3d.h"

void	init_cub(t_cub3d *cub)
{
	cub->C_color = 0;
	cub->F_color = 0;
	cub->texture_flag = 0;
	cub->hiding_map = 1;
	cub->mlx.width = 1080;
	cub->mlx.height = 720;
	cub->maze = NULL;
	cub->wall = NULL;
	cub->map = NULL;
	cub->map = malloc(sizeof(t_map *));
	if (!cub->map)
		error("allocation failed.");
	cub->player.flag = false;
	// cub->player = malloc(sizeof(t_player));
	// if (!cub->player)
	// 	error("allocation failed.");
	
	// if (!cub->player)
		// 	error("allocation failed.");
	*cub->map = NULL;
	cub->first_last_line = false;
	cub->texture = malloc(sizeof(t_texture));
	if (!cub->texture)
		error("allocation failed.");
}

void	get_maze(t_cub3d *cub)
{
	int	i;

	i = 0;
	cub->mlx.width = 1000;
	cub->mlx.height = 720;
	while ((*cub->map)->next)
	{
		cub->maze[i] = (*cub->map)->line;
		i++;
		(*cub->map) = (*cub->map)->next;
	}
	cub->maze[i++] = (*cub->map)->line;
	cub->maze[i] = NULL;
}
