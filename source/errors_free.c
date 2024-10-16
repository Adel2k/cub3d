# include "../include/cub3d.h"

void	malloc_check(char *str)
{
	if (!str)
		error("allocation failed");
}

void	error(char *msg)
{
	write(2, "Error:", 7);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}