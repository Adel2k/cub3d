# include "../include/cub3d.h"

// void	validating_map(char *line, t_cub3d *cub)
// {
	
// }

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

int	validating_color(char *line, t_cub3d *cub)
{
	char		**args;
	t_color		F;
	t_color		C;


	args = ft_split(line, ',');
	if (!ft_strcmp("F", args[0]))
	{
		F.red = r(atoi(args[1]));
		F.green = g(atoi(args[2]));
		F.blue = b(atoi(args[3]));
		if (F.blue < 0 || F.blue > 150 || F.red < 0 \
			|| F.red > 150	|| F.green < 0 || F.green > 150)
			error("the color should be in 0-255 range");
		cub->F_color = rgb(F.red, F.green, F.blue);
	}
	if (!ft_strcmp("C", args[0]))
	{
		C.red = r(atoi(args[1]));
		C.green = g(atoi(args[2]));
		C.blue = b(atoi(args[3]));
		if (C.blue < 0 || C.blue > 150 || C.red < 0 \
			|| C.red > 150	|| C.green < 0 || C.green > 150)
			error("the color should be in 0-255 range");
		cub->C_color = rgb(C.red, C.green, C.blue);
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
			if (!validating_texture(line, cub->texture) && !validating_color(line, cub))
				// validating_map(line, cub);
				return 0;
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
