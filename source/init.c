# include "../include/cub3d.h"

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
	cub->player.flag = false;
	// cub->player = malloc(sizeof(t_player));
	// if (!cub->player)
	// 	error("allocation failed.");
	*cub->map = NULL;
	cub->Fcolor = NULL;
	cub->Ccolor = NULL;
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
	while ((*cub->map)->prev)
		(*cub->map) = (*cub->map)->prev;
}