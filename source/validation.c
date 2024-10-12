# include "../include/cub3d.h"

int	validating_texture(char *line, t_texture *texture)
{
	char		**args;

	args = ft_split(line);
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

int	validating_color(char *line, t_texture *texture)
{
	char		**args;

	args = ft_split(line);
	if (!ft_strcmp("F", args[0]))
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

int	parsing(char *filename)
{
	int		fd;
	char	*line;
	t_texture	*texture;

	texture = malloc(sizeof(texture));
	if (!texture)
	{
		write(2, "Error: allocation failed.\n", 27);
		return ;
	}
	fd = open(filename, O_RDONLY);
	if (fd > 0)
	{
		while (1)
		{	
			line = get_next_line(fd);
			if (!line)
				return (0);
			line = trim(line);
			if (!validating_texture(line, texture) && !validating_color(line, texture))
				validating_map(line, texture);
		}
	}
	write(2, "Error:file doesn't exist.\n", 27);
	exit(EXIT_FAILURE);
}

int	check_filename(char *filename)
{
	int	len;

	len = ft_strlen(filename) - 1;
	if (filename == NULL)
		return (1);
	if (ft_strlen(filename) > 4)
	{
		if (ft_strcmp(ft_substr(filename, len - 3, 4), ".cub") == 0)
		{
			if (!parsing(filename))
				return (0);
		}
	}
	write(2, "Error:passed file should be with <.cub>\n", 41);
	exit(EXIT_FAILURE);
}