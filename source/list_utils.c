/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: By: aeminian <aeminian@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:56:51 by adel              #+#    #+#             */
/*   Updated: 2024/11/12 10:56:52 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	node->len = ft_strlen(line);
	node->index = 0;
	node->line = line;
	node->next = NULL;
	if (*cub->map == NULL)
		*cub->map = node;
	else
	{
		last_node = lstlast((*cub->map));
		node->index = ++last_node->index;
		last_node->next = node;
	}
}

int	count_nodes(t_map **map)
{
	t_map	*current;
	int		i;

	if (!map)
		return (0);
	current = *map;
	i = 0;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}
