# include "../include/cub3d.h"

int	key_press(int key, t_cub3d *cub)
{
	// if (key == ESC)
	// 	ft_free_cub(cub, 2, "");
    //poxel else if i
	if (key == LARROW)
		change_view(cub, LARROW, AROTATE);
	else if (key == RARROW)
		change_view(cub, RARROW, AROTATE);
	else if (key == E)
		open_close_door(cub);
	else if (key == W)
		move_w(cub, WSPEED);
	else if (key == S)
		move_s(cub, SSPEED);
	else if (key == A || key == D)
		move_right_left(cub, key, ADSPEED);
	else if (key == M)
		cub->hiding_map *= -1;
	return (0);
}

int	mouse_move(int x, int y, t_cub3d *cub)
{
	static int	prevx;

	(void)y;
	if (x < prevx)
		change_view(cub, LARROW, MROTATE * abs(x - prevx));
	else if (x > prevx)
		change_view(cub, RARROW, MROTATE * abs(x - prevx));
	prevx = x;
	return (0);
}
