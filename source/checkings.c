# include "../include/cub3d.h"

int	check_walls(t_cub3d *cub, char *line, int j)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(line);
	while (j == 0 && line[++i])
	{
		if (line[i] != '1' && !is_space(line[i]))
			return (0);
	}
	i = 0;
	while (j == 1 && line[++i])
	{
			if (line[0] == '1' && line[len - 2] == '1')
			{
				if ((line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W'))
				{
					if (cub->player.flag == false && !find_player(cub, i))
						return (1);
					else 
						error("just one player you can have");
				}
				else
					continue;
			}
			else
				error("the map should be srounded by walls");
	}
	return (1);
}

int	check_filename(char *filename)
{
	int		len;
	int		fd;
	t_cub3d	*cub;

	cub = malloc(sizeof(t_cub3d));
	if (!cub)
		error("allocation failed");
	init_cub(cub);
	len = ft_strlen(filename) - 1;
	if (filename == NULL)
		return (1);
	if (ft_strlen(filename) > 4)
	{
		if (ft_strcmp(ft_substr(filename, len - 3, 4), ".cub") == 0)
		{
			fd = open(filename, O_RDONLY);
			parsing(cub, fd);
			start_game(*cub);
			t_map	*current = (*cub->map);
			printf("%s-------------%s\n", "WE", cub->texture->west);
			printf("%s-------------%s\n", "SO", cub->texture->south);
			printf("%s-------------%s\n", "EA", cub->texture->east);
			printf("%s-------------%s\n", "no", cub->texture->north);
			printf("%s-------------%d\n", "c", cub->C_color);
			printf("%s-------------%d\n", "WE", cub->F_color);
			while (current != NULL)
			{
				printf(">>>>>>>>>>>>%s", current->line);
				current = current->next;
			}
			printf("\n%d\n", cub->height);
			
			return 0;
		}
	}
	error("passed file should be with <.cub>");
	return(1);
}

int	is_space(char c)
{
	if (c == 32 || ( c >= 9 && c <= 13 ))
		return (1);
	return (0);
}

int	find_player(t_cub3d *cub, int i)
{
	cub->player.flag = true;
	cub->player.dir_x = 0;
	cub->player.dir_y = 0;
	cub->player.plane_x = 0;
	cub->player.plane_y = 0;
	if ((*cub->map)->line[i] == 'N')
	{
		cub->player.dir_x = -1;
		cub->player.plane_y = 0.66;
		return (1);
	}
	if ((*cub->map)->line[i] == 'W')
	{
		cub->player.dir_x = -1;
		cub->player.plane_y = -0.66;
		return (1);
	}
	if ((*cub->map)->line[i] == 'E')
	{
		cub->player.dir_y = 1;
		cub->player.plane_x = 0.66;
		return (1);
	}
	if ((*cub->map)->line[i] == 'S')
	{
		cub->player.dir_y = 1;
		cub->player.plane_x = -0.66;
		return (1);
	}
	return (0);
}
