/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: By: aeminian <aeminian@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:56:19 by adel              #+#    #+#             */
/*   Updated: 2024/11/12 10:56:20 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (line[0] == '1' && (line[len - 1] == '1'))
		{
			if ((line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W'))
			{
				if (!cub->map)
					exit(1) ;
				if (cub->player.flag == false && set_dir(cub, line[i]))
					return (1);
				else
					error("just one player you can have");
			}
			else
				continue;
		}
		else
		{
			printf("%c\n", line[i]);
			error("the map should be srounded by walls");
		}
	}
	return (1);
}

void	check_door(t_cub3d cub)
{
	int		j;
	t_map	*map;

	map = cub.map;
	map = map->next;
	while (map->next)
	{
		j = 1;
		if (j < map->len - 1)
		{
			while (map->line[j + 1])
			{
				if (map->line[j] == 'D'
					&& !(map->line[j - 1] == '1' && map->line[j + 1] == '1')
					&& !(map->prev->line[j] == '1' && map->next->line[j] == '1'))
					ft_free_cub(&cub, 1, "Door in wrong place");
				j++;
			}
		}
		map = map->next;
	}
}

int	check_filename(char *filename)
{
	int		len;
	int		fd;
	t_cub3d	*cub;

	if (!filename)
		return (1);
	cub = malloc(sizeof(t_cub3d));
	if (!cub)
		error("allocation failed");
	// init_cub(cub);
	len = ft_strlen(filename) - 1;
	if (len > 4)
	{
		if (ft_strcmp(ft_substr(filename, len - 3, 4), ".cub") == 0)
		{
			fd = open(filename, O_RDONLY);
			parsing(cub, fd);
	printf("poinrt %p\n", cub->map->line);
			int	count = 1;
			t_map *a = cub->map;
			while (a)
			{
				count++;
				a = a->next;
			}
		cub->maze = malloc(sizeof(char *) * (count + 1));
		check_door(*cub);

		get_player_pos(cub);
		get_maze(cub);
	// 	printf("aaaa\n");
	
			// t_map	*current = cub->map;
			// printf("%s-------------%s\n", "WE", cub->texture->west);
			// printf("%s-------------%s\n", "SO", cub->texture->south);
			// printf("%s-------------%s\n", "EA", cub->texture->east);
			// printf("%s-------------%s\n", "no", cub->texture->north);
			// printf("%s-------------%d\n", "c", cub->C_color);
			// printf("%s-------------%d\n", "WE", cub->F_color);
			// while (current != NULL)
			// {
			// 	printf(">>>>>>>>>>>>>>>>%s\n", current->line);
			// 	current = current->next;
			// }
			// // printf("\n%d\n", cub->height);
			// start_game(*cub);
			
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

int	set_dir(t_cub3d *cub, char c)
{
	cub->player.dir_x = 0;
	cub->player.dir_y = 0;
	cub->player.plane_x = 0;
	cub->player.plane_y = 0;
	if (c == 'N')
	{
		cub->player.dir_x = -1;
		cub->player.plane_y = 0.66;
		cub->player.flag = true;
		return (1);
	}
	else if (c == 'S')
	{
		cub->player.dir_x = 1;
		cub->player.plane_y = -0.66;
		cub->player.flag = true;
		return (1);
	}
	else if (c == 'E')
	{
		cub->player.dir_y = 1;
		cub->player.plane_x = 0.66;
		cub->player.flag = true;
		return (1);

	}
	else if (c == 'W')
	{
		cub->player.dir_y = -1;
		cub->player.plane_x = -0.66;
		cub->player.flag = true;
		return (1);
	}
	return (0);
}
