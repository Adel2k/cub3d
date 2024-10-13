# include "../include/cub3d.h"

void	init_cub(t_cub3d *cub)
{
	cub->texture = malloc(sizeof(t_texture));
	if (!cub->texture)
	{
		write(2, "Error: allocation failed.\n", 27);
		return ;
	}
	cub->texture = NULL;

}
