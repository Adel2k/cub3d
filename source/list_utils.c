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

void add_node(char *line, t_map **stack, int index)
{
	t_map *new_node;
	t_map *tmp;

	new_node = ft_lstnew(ft_strlen(line), line, index - 6);
	if (!new_node)
	{
		ft_lstclear(stack);
		// free_and_error(line, 1, "Malloc error");
		return;
	}
	if (*stack == NULL) // If the list is empty
		*stack = new_node;
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
		new_node->prev = tmp;
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

t_map	*ft_lstnew(int len, char *row, int index)
{
	t_map	*res;

	res = malloc(sizeof(t_map));
	if (!res)
		return (NULL);
	res->len = len;
	res->line = row;
	res->index = index;
	res->prev = NULL;
	res->next = NULL;
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
		if ((*lst)->line != NULL)
			free((*lst)->line);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
