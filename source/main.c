/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: By: aeminian <aeminian@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:56:54 by adel              #+#    #+#             */
/*   Updated: 2024/11/12 10:56:55 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3d.h"

int	main(int ac ,char **av)
{
	if (ac == 2)
	{
		if (!(check_filename(av[1])))
		{
			return (0);
		}
	}
	write(2, "Error:Wrong number of arguments\n", 33);
	return (1);
}