# include "../include/cub3d.h"

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