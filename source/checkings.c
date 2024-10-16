# include "../include/cub3d.h"

int	check_walls(char *line, int j)
{
	int	i;

	i = 0;
	while (line[++i])
	{
		if (j == 0)
		{
			if (line[i] != '1' && !is_space(line[i]))
				return (0);
		}
	}
	if (j == 1)
	{
		if (line[0] != '1' || line[i - 2] != '1')
			return (0);
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
