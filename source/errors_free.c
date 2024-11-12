/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: By: aeminian <aeminian@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:56:29 by adel              #+#    #+#             */
/*   Updated: 2024/11/12 10:56:30 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3d.h"

void	malloc_check(char *str)
{
	if (!str)
		error("allocation failed");
}

void	error(char *msg)
{
	write(2, "Error:", 7);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

// void	ft_free_cub(t_cub3d *cub, int flag, char *s)
// {
// 	free(cub->npath);
// 	free(cub->wpath);
// 	free(cub->spath);
// 	free(cub->epath);
// 	free(cub->fcolor);
// 	free(cub->rcolor);
// 	if (cub->wall)
// 		destroy_img(cub);
// 	if (cub->map)
// 		ft_lstclear(&cub->map);
// 	if (cub->maze)
// 		free(cub->maze);
// 	free(cub->map);
// 	cub->npath = NULL;
// 	cub->wpath = NULL;
// 	cub->epath = NULL;
// 	cub->spath = NULL;
// 	cub->fcolor = NULL;
// 	cub->rcolor = NULL;
// 	if (flag == 1)
// 		exit(1 && printf("%s\n", s));
// 	else if (flag == 2)
// 		exit(0);
// }

// int	press(t_cub3d *cub)
// {
// 	ft_free_cub(cub, 2, "");
// 	return (0);
// }
