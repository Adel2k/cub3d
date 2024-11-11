# include "../include/cub3d.h"


// void	got_player_pos(t_cub3d *cub)
// {
// 	int		j;
// 	t_map	*map;

// 	map = cub->map;
// 	while (map)
// 	{
// 		j = 0;
// 		while (map->line[j])
// 		{
// 			if (map->line[j] == 'N' || map->line[j] == 'S'
// 				|| map->line[j] == 'E' || map->line[j] == 'W')
// 			{
// 				cub->player.pos_y = j + 0.5;
// 				cub->player.pos_x = map->index + 0.5;
// 				set_dir(cub, map->line[j]);
// 				map->line[j] = '0';
// 				return ;
// 			}
// 			j++;
// 		}
// 		map = map->next;
// 	}
// }

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
	cub->east = NULL;
	cub->north = NULL;
	cub->west = NULL;
	cub->south = NULL;
	cub->Fcolor = NULL;
	cub->Ccolor = NULL;
	cub->first_last_line = false;
	cub->texture = malloc(sizeof(t_texture));
	if (!cub->texture)
		error("allocation failed.");
}

// char	*path_cut(char **path, char *s, char **info, int flag)
// {
// 	int		j;
// 	char	*tmp;

// 	j = 0;
// 	while (ft_ischar(path[0][j], " \t\n\v\f\r") == 1)
// 		j++;
// 	if (ft_ischar(path[0][j], &s[0]) == 1)
// 		j++;
// 	if (s[1] != '\0' && ft_ischar(path[0][j], &s[1]) == 1)
// 		j++;
// 	while (ft_ischar(path[0][j], " \t\n\v\f\r") == 1)
// 		j++;
// 	tmp = *path;
// 	*path = ft_strdup(*path + j);
// 	free(tmp);
// 	j = ft_strlen(*path) - 1;
// 	if (flag == 1)
// 	{
// 		if (j < 3 || !(path[0][j] == 'm' && path[0][j - 1] == 'p'
// 			&& path[0][j - 2] == 'x' && path[0][j - 3] == '.'))
// 			free_and_error(info, 1, "Invalid texture name (.xpm at the end)");
// 	}
// 	return (*path);
// }

// void	path_init(t_cub3d *vars, char	**s, int i, int j)
// {
// 	if (s[i][j] == 'N' && s[i][j + 1] == 'O' && check(s[i][j + 2]) == 1
// 		&& !vars->north)
// 		vars->north = path_cut(&s[i], "NO", s, 1);
// 	else if (s[i][j] == 'S' && s[i][j + 1] == 'O' && check(s[i][j + 2]) == 1
// 		&& !vars->south)
// 		vars->south = path_cut(&s[i], "SO", s, 1);
// 	else if (s[i][j] == 'E' && s[i][j + 1] == 'A' && check(s[i][j + 2]) == 1
// 		&& !vars->east)
// 		vars->east = path_cut(&s[i], "EA", s, 1);
// 	else if (s[i][j] == 'W' && s[i][j + 1] == 'E' && check(s[i][j + 2]) == 1
// 		&& !vars->west)
// 		vars->west = path_cut(&s[i], "WE", s, 1);
// 	else if (s[i][j] == 'F' && check(s[i][j + 1]) == 1 && !vars->Fcolor)
// 		vars->Fcolor = path_cut(&s[i], "F", s, 0);
// 	else if (s[i][j] == 'C' && check(s[i][j + 1]) == 1 && !vars->Ccolor)
// 		vars->Ccolor = path_cut(&s[i], "C", s, 0);
	// else
	// 	free_and_error(s, 1, "Something went wrong with path");
// }
