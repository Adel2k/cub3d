/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: By: aeminian <aeminian@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:57:17 by adel              #+#    #+#             */
/*   Updated: 2024/11/12 10:57:18 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3d.h"

void	open_close_door(t_cub3d *cub)
{
	int	x;
	int	y;

	x = (int)cub->player.pos_x;
	y = (int)cub->player.pos_y;
	if (cub->player.dir_x < -0.05)
		x = (int)cub->player.pos_x - 1;
	else if (cub->player.dir_x > 0.05)
		x = (int)cub->player.pos_x + 1;
	if (cub->player.dir_y < -0.05)
		y = (int)cub->player.pos_y - 1;
	else if (cub->player.dir_y > 0.05)
		y = (int)cub->player.pos_y + 1;
	if (cub->maze[x][y] == 'D')
		cub->maze[x][y] = 'O';
	else if (cub->maze[x][y] == 'O')
		cub->maze[x][y] = 'D';
	
}


void	get_player_pos(t_cub3d *cub)
{
	int		j;
	t_map	*map;

	if (!cub && !cub->map)
		exit(1) ;
	map = cub->map;
	if (!map->line)
		return ;
	while (map)
	{
	printf("%p\n", cub->map->line);
		j = 0;
		while (map->line[j])
		{
			if (map->line[j] == 'N' || map->line[j] == 'S'
				|| map->line[j] == 'E' || map->line[j] == 'W')
			{
				cub->player.pos_y = j + 0.5;
				cub->player.pos_x = map->index + 0.5;
				set_dir(cub, map->line[j]);
				map->line[j] = '0';
				return ;
			}
			j++;
		}
		map = map->next;
	}
}

void	create_image(t_cub3d *cub)
{
	cub->img.img = mlx_new_image(cub->mlx.ptr,
			cub->mlx.width, cub->mlx.height);
	if (!cub->img.img)
		ft_free_cub(cub, 1, "Can't create image");
	cub->img.addr = mlx_get_data_addr(cub->img.img,
			&cub->img.bits_per_pixel, &cub->img.line_length,
			&cub->img.endian);
	if (!cub->img.addr)
		ft_free_cub(cub, 1, "ADDR error");
	cub->img.wd = cub->mlx.width;
	cub->img.ht = cub->mlx.height;
}

void	get_door(t_img *door, t_cub3d *cub, char *path)
{
	door->img = mlx_xpm_file_to_image(cub->mlx.ptr,
			path, &door->wd, &door->ht);
	if (!door->img)
		ft_free_cub(cub, 1, "Bad Images");
	door->addr = mlx_get_data_addr(door->img,
			&door->bits_per_pixel, &door->line_length,
			&door->endian);
	if (!door->addr)
		ft_free_cub(cub, 1, "ADDR error");
}

void	set_wall_textures(t_cub3d *cub)
{
	cub->wall = malloc(sizeof(t_img) * 4);
	if (!cub->wall)
		ft_free_cub(cub, 1, "Malloc error");
	cub->wall[0].img = mlx_xpm_file_to_image(cub->mlx.ptr,
			cub->texture->west, &cub->wall[0].wd, &cub->wall[0].ht);
	cub->wall[1].img = mlx_xpm_file_to_image(cub->mlx.ptr,
			cub->texture->south, &cub->wall[1].wd, &cub->wall[1].ht);
	cub->wall[2].img = mlx_xpm_file_to_image(cub->mlx.ptr,
			cub->texture->north, &cub->wall[2].wd, &cub->wall[2].ht);
	cub->wall[3].img = mlx_xpm_file_to_image(cub->mlx.ptr,
			cub->texture->east, &cub->wall[3].wd, &cub->wall[3].ht);
}

void	get_wall__textures(t_cub3d *cub)
{
	int	i;

	set_wall_textures(cub);
	if (!cub->wall[0].img || !cub->wall[1].img
		|| !cub->wall[2].img || !cub->wall[3].img
		|| cub->wall[0].wd != cub->wall[1].wd
		|| cub->wall[0].ht != cub->wall[1].ht
		|| cub->wall[0].wd != cub->wall[2].wd
		|| cub->wall[0].ht != cub->wall[2].ht
		|| cub->wall[0].wd != cub->wall[3].wd
		|| cub->wall[0].ht != cub->wall[3].ht)
		ft_free_cub(cub, 1, "Bad Images");
	i = -1;
	while (++i < 4)
	{
		cub->wall[i].addr = mlx_get_data_addr(cub->wall[i].img,
				&cub->wall[i].bits_per_pixel, &cub->wall[i].line_length,
				&cub->wall[i].endian);
		if (!cub->wall[i].addr)
			ft_free_cub(cub, 1, "ADDR error");
	}
}
