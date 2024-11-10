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