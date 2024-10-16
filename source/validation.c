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
	t_color		C;
	
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
		C.red = (atoi(args[1]));
		C.green = (atoi(args[2]));
		C.blue = (atoi(args[3]));
		if (C.blue < 0 || C.blue > 255 || C.red < 0 \
			|| C.red > 255	|| C.green < 0 || C.green > 255)
			error("the cell color should be in 0-255 range");
		cub->C_color = rgb(C.red, C.green, C.blue);
	}
	else if (cub->texture_flag < 6 && cub->texture_flag >= 4)
		error("There is not any cell or floor color");
	return (1);
}

void	parsing_map(char *line, t_cub3d *cub)
{
	int i;

	i = 0;
	while ((line[++i]))
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != '\0' \
			&& line[i] != '\n' && !is_space(line[i]))
			error("The map should only contain 0 and 1");
	}
	if (*cub->map == NULL && check_walls(line, 0))
		add_node(line, cub);
	else if ((*cub->map) && check_walls(line, 1))
		add_node(line, cub);
	else
		error("Inavlid map, the map should be srounded with walls");
}

void	parsing(t_cub3d *cub, int fd)
{
	char	*line;char	**args;

	if (fd > 0)
	{
		while (1)
		{
			line = get_next_line(fd);
			if (!line)
				return ;
			line = trim(line);
			if (*line != 0)
			{
				if (cub->texture_flag == 6)
					parsing_map(line, cub);
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
	error("file doesn't exist.");
}
