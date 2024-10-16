# include "../include/cub3d.h"

void	init_cub(t_cub3d *cub)
{
	cub->C_color = 0;
	cub->F_color = 0;
	cub->texture_flag = 0;
	cub->map = malloc(sizeof(t_map *));
	if (!cub->map)
		error("allocation failed.");
	*cub->map = NULL;
	cub->first_last_line = false;
	cub->texture = malloc(sizeof(t_texture));
	if (!cub->texture)
		error("allocation failed.");
}
