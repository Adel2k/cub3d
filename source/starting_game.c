/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: By: aeminian <aeminian@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:57:14 by adel              #+#    #+#             */
/*   Updated: 2024/11/12 10:57:15 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3d.h"

void	set_gun_textures(t_cub3d *cub)
{
	cub->gun = malloc(sizeof(t_img) * 5);
	// if (!cub->gun)
	// 	ft_free_cub(cub, 1, "Malloc error");
	cub->gun[0].img = mlx_xpm_file_to_image(cub->mlx.ptr,
			"./textures/00_frame.xpm", &cub->gun[0].wd,
			&cub->gun[0].ht);
	cub->gun[1].img = mlx_xpm_file_to_image(cub->mlx.ptr,
			"./textures/01_frame.xpm", &cub->gun[1].wd,
			&cub->gun[1].ht);
	cub->gun[2].img = mlx_xpm_file_to_image(cub->mlx.ptr,
			"./textures/02_frame.xpm", &cub->gun[2].wd,
			&cub->gun[2].ht);
	cub->gun[3].img = mlx_xpm_file_to_image(cub->mlx.ptr,
			"./textures/03_frame.xpm", &cub->gun[3].wd,
			&cub->gun[3].ht);
	cub->gun[4].img = mlx_xpm_file_to_image(cub->mlx.ptr,
			"./textures/04_frame.xpm", &cub->gun[4].wd,
			&cub->gun[4].ht);
}

void	get_gun_textures(t_cub3d *cub)
{
	int	i;

	set_gun_textures(cub);
	if (!cub->gun[0].img || !cub->gun[1].img
		|| !cub->gun[2].img || !cub->gun[3].img
		|| !cub->gun[4].img)
		exit(1);
	// 	ft_free_cub(cub, 1, "Bad Images");
	i = -1;
	while (++i < 5)
	{
		cub->gun[i].addr = mlx_get_data_addr(cub->gun[i].img,
				&cub->gun[i].bits_per_pixel, &cub->gun[i].line_length,
				&cub->gun[i].endian);
		if (!cub->gun[i].addr)
			exit(1);
		// 	ft_free_cub(cub, 1, "ADDR error");
	}
}

void	init_img_info(t_cub3d *cub)
{
	cub->wall = NULL;
	cub->gun = NULL;
	cub->img.img = NULL;
	cub->cdoor.img = NULL;
	cub->odoor.img = NULL;
	cub->hiding_map = 1;
	get_wall__textures(cub);
	get_gun_textures(cub);
	get_door(&cub->cdoor, cub, "./textures/CloseDoor.xpm");
	get_door(&cub->odoor, cub, "./textures/OpenDoor.xpm");
	create_image(cub);
}

int	re_draw(t_cub3d *cub)
{
	mlx_destroy_image(cub->mlx.ptr, cub->img.img);
	create_image(cub);
	raycasting(cub);
	return (0);
}
