# include "../include/cub3d.h"


void	got_player_pos(t_cub3d *cub)
{
	int		j;
	t_map	*map;

	map = cub->map;
	while (map)
	{
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

void	set_dir(t_cub3d *cub, char c)
{
	cub->player.dir_x = 0;
	cub->player.dir_y = 0;
	cub->player.plane_x = 0;
	cub->player.plane_y = 0;
	if (c == 'N')
	{
		cub->player.dir_x = -1;
		cub->player.plane_y = 0.66;
	}
	else if (c == 'S')
	{
		cub->player.dir_x = 1;
		cub->player.plane_y = -0.66;
	}
	else if (c == 'E')
	{
		cub->player.dir_y = 1;
		cub->player.plane_x = 0.66;
	}
	else if (c == 'W')
	{
		cub->player.dir_y = -1;
		cub->player.plane_x = -0.66;
	}
}

void	init_cub(t_cub3d *cub)
{
	cub->C_color = 0;
	cub->F_color = 0;
	cub->texture_flag = 0;
	cub->hiding_map = 1;
	cub->mlx.width = 1000;
	cub->mlx.width = 720;
	cub->map = malloc(sizeof(t_map *));
	if (!cub->map)
		error("allocation failed.");
	cub->player = malloc(sizeof(t_player));
	if (!cub->player)
		error("allocation failed.");
	cub->player->flag = false;
	*cub->map = NULL;
	cub->first_last_line = false;
	cub->texture = malloc(sizeof(t_texture));
	if (!cub->texture)
		error("allocation failed.");
}
