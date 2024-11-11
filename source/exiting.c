# include "../include/cub3d.h"


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