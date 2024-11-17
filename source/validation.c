/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: By: aeminian <aeminian@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:57:26 by adel              #+#    #+#             */
/*   Updated: 2024/11/12 10:57:27 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3d.h"
# include "../include/get_next_line.h"

int	validating_texture(t_cub3d *cub, char **args)
{
	if (!ft_strcmp("NO", args[0]) && ++cub->texture_flag)
	{
		cub->texture->north = ft_strdup(args[1]);
		return (0);
	}
	else if (!ft_strcmp("SO", args[0]) && ++cub->texture_flag)
	{
		cub->texture->south = ft_strdup(args[1]);
		return (0);
	}
	else if (!ft_strcmp("WE", args[0]) && ++cub->texture_flag)
	{
		cub->texture->west = ft_strdup(args[1]);
		return (0);
	}
	else if (!ft_strcmp("EA", args[0]) && ++cub->texture_flag)
	{
		cub->texture->east = ft_strdup(args[1]);
		return (0);
	}
	else if (cub->texture_flag <= 4)
		error("Wrong input for textures");
	return (1);
}

int	validating_color(t_cub3d *cub, char **args)
{
	t_color		F;
	
	if (!ft_strcmp("F", args[0]) && ++cub->texture_flag)
	{
		F.red = atoi(args[1]);
		F.green = (atoi(args[2]));
		F.blue = (atoi(args[3]));
		if (F.blue < 0 || F.blue > 255 || F.red < 0 \
			|| F.red > 255	|| F.green < 0 || F.green > 255)
			error("the floor color should be in 0-255 range");
		cub->F_color = rgb(F.red, F.green, F.blue);
	}
	else if (!ft_strcmp("C", args[0]) && cub->texture_flag++)
	{
		F.red = (atoi(args[1]));
		F.green = (atoi(args[2]));
		F.blue = (atoi(args[3]));
		if (F.blue < 0 || F.blue > 255 || F.red < 0 \
			|| F.red > 255	|| F.green < 0 || F.green > 255)
			error("the cell color should be in 0-255 range");
		cub->C_color = rgb(F.red, F.green, F.blue);
	}
	else if (cub->texture_flag < 6 && cub->texture_flag >= 4)
		error("There is not any cell or floor color");
	return (1);
}

void	parsing_map(char *line, t_cub3d *cub, int index)
{
	int i;

	i = 0;
	while ((line[++i]))
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != '\0' \
			&& line[i] != '\n' && line[i] != 'N' && line[i] != 'S' \
			&& line[i] != 'W' && line[i] != 'E' && !is_space(line[i]))
			error("The map should only contain 0 and 1");
	}
	if (cub->map == NULL && check_walls(cub, line, 0))
		add_node(&line, &cub->map);
	else if (cub->map && check_walls(cub, line, 1))
		add_node(line, &cub->map, index);
	else
		error("Inavlid map, the map should be srounded with walls");
}

void	reading_map(t_cub3d *cub, int fd)
{
	char	**args;
	char	*line;
	int		index;

	index = 6;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line = trim(line);
		if (*line != 0)
		{
			if (cub->texture_flag == 6)
			{
				parsing_map(line, cub, index);
				index++;
			}
			args = ft_split(line, ' ');
			if (cub->texture_flag < 4 && !validating_texture(cub, args))
				continue ;
			args = ft_split(line, ',');
			if (cub->texture_flag < 6 && cub->texture_flag >= 4 \
				&& !validating_color(cub, args))
				continue ;
		}
	}
}

void	parsing(t_cub3d *cub, int fd)
{
	// t_map *current = cub->map;

	// while (current != NULL)
	// {
	// 	printf("%s\n", cur)
	// 	current = current -> next;
	// }
	if (fd > 0)
	{
		init_cub(cub);
		reading_map(cub, fd);
		if (cub->map != NULL)
		{
			if (!check_walls(cub, (lstlast(cub->map))->line, 0))
				error("Inavlid map, the map should be srounded with walls");
			if (cub->player.flag == false)
				error("There should be a player in map");
			cub->height = count_nodes(&cub->map);
		}
	}
	else
		error("file doesn't exist.");
}
