# include "../include/cub3d.h"

void	start_game(t_cub3d cub)
{
	cub.mlx.ptr = mlx_init();
	cub.mlx.win = mlx_new_window(cub.mlx.ptr, cub.mlx.width,
			cub.mlx.height, "GAME");
	// if (!cub.mlx.win)
	// 	ft_free_cub(&cub, 1, "Can't open window");
	init_img_info(&cub);
	raycasting(&cub);
	mlx_hook(cub.mlx.win, 2, 0, &key_press, &cub);
	mlx_hook(cub.mlx.win, 6, 0, &mouse_move, &cub);
	mlx_loop_hook(cub.mlx.ptr, &re_draw, &cub);
	// mlx_hook(cub.mlx.win, 17, 0, &press, &cub);
	mlx_loop(cub.mlx.ptr);
}