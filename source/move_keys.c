/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: By: aeminian <aeminian@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:57:04 by adel              #+#    #+#             */
/*   Updated: 2024/11/12 10:57:05 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3d.h"

int	key_press(int key, t_cub3d *cub)
{
	if (key == ESC)
		ft_free_cub(cub, 2, "");
	else if (key == LARROW)
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


void	move_right_left(t_cub3d *cub, int key, double move)
{
	double	prev_x;
	double	prev_y;

	prev_x = cub->player->dir_x;
	prev_y = cub->player->dir_y;
	get_dir(cub);
	if (key == D)
		move_w(cub, move);
	else if (key == A)
		move_s(cub, move);
	cub->player->dir_x = prev_x;
	cub->player->dir_y = prev_y;
}

void	move_s(t_cub3d *cub, double move)
{
	if (cub->maze[(int)(cub->player->pos_x - cub->player->dir_x * move)]
		[(int)(cub->player->pos_y)] == '0'
		|| cub->maze[(int)(cub->player->pos_x
		- cub->player->dir_x * move)][(int)(cub->player->pos_y)] == 'O')
		cub->player->pos_x -= cub->player->dir_x * move;
	if (cub->maze[(int)(cub->player->pos_x)][(int)(cub->player->pos_y
		- cub->player->dir_y * move)] == '0'
		|| cub->maze[(int)(cub->player->pos_x)][(int)(cub->player->pos_y
		- cub->player->dir_y * move)] == 'O')
		cub->player->pos_y -= cub->player->dir_y * move;
}

void	move_w(t_cub3d *cub, double move)
{
	if (cub->maze[(int)(cub->player->pos_x + cub->player->dir_x * move)]
		[(int)(cub->player->pos_y)] == '0'
		|| cub->maze[(int)(cub->player->pos_x
		+ cub->player->dir_x * move)][(int)(cub->player->pos_y)] == 'O')
		cub->player->pos_x += cub->player->dir_x * move;
	if (cub->maze[(int)(cub->player->pos_x)][(int)(cub->player->pos_y
		+ cub->player->dir_y * move)] == '0'
		|| cub->maze[(int)(cub->player->pos_x)][(int)(cub->player->pos_y
		+ cub->player->dir_y * move)] == 'O')
		cub->player->pos_y += cub->player->dir_y * move;
}
