# include "../include/cub3d.h"

void	validating_map(char *line, t_cub3d *cub)
{
	
}


void	init_cub(t_cub3d *cub)
{
	cub->color = malloc(sizeof(t_color));
	if (!cub->color)
	{
		write(2, "Error: allocation failed.\n", 27);
		return ;
	}
	cub->texture = malloc(sizeof(t_texture));
	if (!cub->texture)
	{
		write(2, "Error: allocation failed.\n", 27);
		return ;
	}
	cub->color = NULL;
	cub->texture = NULL;

}
int	validating_texture(char *line, t_texture *texture)
{
	char		**args;

	args = ft_split(line, ' ');
	if (!ft_strcmp("NO", args[0]))
	{
		texture->north = ft_strdup(args[1]);
		return (0);
	}
	else if (!ft_strcmp("SO", args[0]))
	{
		texture->north = ft_strdup(args[1]);
		return (0);
	}
	else if (!ft_strcmp("WE", args[0]))
	{
		texture->north = ft_strdup(args[1]);
		return (0);
	}
	else if (!ft_strcmp("EA", args[0]))
	{
		texture->north = ft_strdup(args[1]);
		return (0);
	}
	return (1);
}

int	validating_color(char *line, t_color *F_color, t_color *C_color)
{
	char		**args;

	args = ft_split(line, ',');
	if (!ft_strcmp("F", args[0]))
	{
		F_color->red = atoi(args[1]);
		F_color->green = atoi(args[2]);
		F_color->blue = atoi(args[3]);
		if (F_color->blue < 0 || F_color->blue > 150 || F_color->red < 0 \
			|| F_color->red > 150	|| F_color->green < 0 || F_color->green > 150)
			error("the color should be in 0-255 range");
	}
	if (!ft_strcmp("C", args[0]))
	{
		C_color->red = atoi(args[1]);
		C_color->green = atoi(args[2]);
		C_color->blue = atoi(args[3]);
		if (C_color->blue < 0 || C_color->blue > 150 || C_color->red < 0 \
			|| C_color->red > 150	|| C_color->green < 0 || C_color->green > 150)
			error("the color should be in 0-255 range");
	}
	return (1);
}

int	parsing(char *filename, t_cub3d *cub)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd > 0)
	{
		while (1)
		{	
			line = get_next_line(fd);
			if (!line)
				return (0);
			line = trim(line);
			if (!validating_texture(line, cub->texture) && !validating_color(line, cub->F_color, cub->C_color))
				validating_map(line, cub);
		}
	}
	error("file doesn't exist.");
	return(1);
}

int	check_filename(char *filename)
{
	int	len;
	t_cub3d	*cub;

	cub = malloc(sizeof(t_cub3d));
	if (!cub)
	error("allocation failed");
	cub = NULL;
	init_cub(cub);
	len = ft_strlen(filename) - 1;
	if (filename == NULL)
		return (1);
	if (ft_strlen(filename) > 4)
	{
		if (ft_strcmp(ft_substr(filename, len - 3, 4), ".cub") == 0)
		{
			if (!parsing(filename, cub))
				return (0);
		}
	}
	error("passed file should be with <.cub>");
	return(1);
}
