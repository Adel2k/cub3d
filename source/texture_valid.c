# include "../include/cub3d.h"

void	set_wall_textures(t_cub3d *cub)
{
	cub->wall = malloc(sizeof(t_img) * 4);
	if (!cub->wall)
		ft_free_cub(cub, 1, "Malloc error");
	cub->wall[0].img = mlx_xpm_file_to_image(cub->mlx.ptr,
			cub->west, &cub->wall[0].wd, &cub->wall[0].ht);
	cub->wall[1].img = mlx_xpm_file_to_image(cub->mlx.ptr,
			cub->south, &cub->wall[1].wd, &cub->wall[1].ht);
	cub->wall[2].img = mlx_xpm_file_to_image(cub->mlx.ptr,
			cub->north, &cub->wall[2].wd, &cub->wall[2].ht);
	cub->wall[3].img = mlx_xpm_file_to_image(cub->mlx.ptr,
			cub->east, &cub->wall[3].wd, &cub->wall[3].ht);
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
