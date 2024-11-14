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

void	add_node(char **line, t_map **stack)
{
	size_t	i;
	t_map	*tmp;

	i = 0;
	tmp = *stack;
	(*stack)->next = ft_lstnew(ft_strlen(line[i]), line[i], i - 6);
	if (!(*stack)->next)
	{
		ft_lstclear(&tmp->next);
		free_and_error(line, 1, "Malloc error");
	}
	(*stack)->next->prev = (*stack);
	*stack = (*stack)->next;
	(*stack)->next = NULL;
	(*stack) = tmp->next;
	(*stack)->prev = NULL;
	free(tmp);
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
