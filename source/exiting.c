/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: By: aeminian <aeminian@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:56:32 by adel              #+#    #+#             */
/*   Updated: 2024/11/12 10:56:33 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3d.h"


void	destroy_gun(t_cub3d *cub)
{
	if (cub->gun[0].img)
		mlx_destroy_image(cub->mlx.ptr, cub->gun[0].img);
	else if (cub->gun[1].img)
		mlx_destroy_image(cub->mlx.ptr, cub->gun[1].img);
	else if (cub->gun[2].img)
		mlx_destroy_image(cub->mlx.ptr, cub->gun[2].img);
	else if (cub->gun[3].img)
		mlx_destroy_image(cub->mlx.ptr, cub->gun[3].img);
	else if (cub->gun[4].img)
		mlx_destroy_image(cub->mlx.ptr, cub->gun[4].img);
}

void	destroy_img(t_cub3d *cub)
{
	if (cub->gun)
		destroy_gun(cub);
	if (cub->wall[0].img)
		mlx_destroy_image(cub->mlx.ptr, cub->wall[0].img);
	else if (cub->wall[1].img)
		mlx_destroy_image(cub->mlx.ptr, cub->wall[1].img);
	else if (cub->wall[2].img)
		mlx_destroy_image(cub->mlx.ptr, cub->wall[2].img);
	else if (cub->wall[3].img)
		mlx_destroy_image(cub->mlx.ptr, cub->wall[3].img);
	else if (cub->img.img)
		mlx_destroy_image(cub->mlx.ptr, cub->img.img);
	else if (cub->cdoor.img)
		mlx_destroy_image(cub->mlx.ptr, cub->cdoor.img);
	else if (cub->odoor.img)
		mlx_destroy_image(cub->mlx.ptr, cub->odoor.img);
	free(cub->wall);
}

void	ft_free_cub(t_cub3d *cub, int flag, char *s)
{
	free(cub->texture->north);
	free(cub->texture->east);
	free(cub->texture->west);
	free(cub->texture->south);
	if (cub->wall)
		destroy_img(cub);
	if (cub->map)
		ft_lstclear(&cub->map);
	if (cub->maze)
		free(cub->maze);
	free(cub->map);
	cub->texture->north = NULL;
	cub->texture->east = NULL;
	cub->texture->west = NULL;
	cub->texture->south = NULL;
	if (flag == 1)
		exit(1 && printf("%s\n", s));
	else if (flag == 2)
		exit(0);
}

int	press(t_cub3d *cub)
{
	ft_free_cub(cub, 2, "");
	return (0);
}