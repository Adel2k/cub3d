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
void add_node(char *line, t_map **map, int index)
{
    t_map *new_node;
    t_map *last;

    if (!line || !map || !*map) // Validate input
        exit(1);

    new_node = ft_lstnew(ft_strlen(line), line, index); // Create a new node
    if (!new_node)
    {
        free_and_error(NULL, 1, "Malloc error");
        return;
    }

    // Append to the end of the map
    last = *map;
    while (last && last->next)
        last = last->next;

    last->next = new_node; // Add the new node
    new_node->prev = last; // Update the previous pointer
	printf("Added node: %s at index %d\n", (*map)->line, (*map)->index);
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
t_map	*ft_lstnew(int len, char *line, int index)
{
	t_map	*res;

	res = malloc(sizeof(t_map));
	if (!res)
		return (NULL);

	res->len = len;
	res->index = index;
	res->prev = NULL;
	res->next = NULL;

	// Duplicate the line to ensure the node owns its data
	res->line = ft_strdup(line);
	if (!res->line)
	{
		free(res);
		return NULL;
	}

	return (res);
}


void	ft_lstclear(t_map **lst)
{
	t_map	*tmp;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		// if ((*lst)->line != NULL)
		// 	free((*lst)->line);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
