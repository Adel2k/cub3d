# include "../include/cub3d.h"

void	validating_texture(char *line)
{
	char		**args;
	t_texture	*texture;


	texture = malloc(sizeof(texture));
	args = ft_split(line);
	int i = -1;
	printf("aaaaa\n");
	while (args[1][++i])
	{
		printf("------------%c\n", args[1][i]);

	}
	
	if (!line)
		return ;
	if (!ft_strcmp("NO", args[0]))
	{
		texture->north = ft_strdup(args[1]);

	}


}

int	parsing(char *filename)
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
			validating_texture(line);

			// printf("%s", line);
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