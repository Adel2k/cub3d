# include "../include/cub3d.h"

t_map	*lstlast(t_map *node)
{
	if (!node)
		return (NULL);
	while(node->next != NULL)
		node = node->next;
	return (node);
}

void	add_node(char *line, t_cub3d *cub)
{
	t_map	*node;
	t_map	*last_node;

	node = malloc(sizeof(t_map));
	node->index = 1;
	node->line = line;
	node->next = NULL;
	if (*cub->map == NULL)
		*cub->map = node;
	else
	{
		last_node = lstlast((*cub->map));
		last_node->next = node;
	}

}
