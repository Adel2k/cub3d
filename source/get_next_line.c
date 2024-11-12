/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: By: aeminian <aeminian@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:03:40 by aeminian          #+#    #+#             */
/*   Updated: 2024/10/16 18:20:22 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#include "../include/cub3d.h"


static void	free_ptr(char **str)
{
	free(*str);
	*str = NULL;
}

static char	*get_line(char **buffer, char **line)
{
	char	*res;
	int		i;

	i = 0;
	res = NULL;
	while (*(*buffer + i) != '\n' && *(*buffer + i) != '\0')
		i++;
	if (*(*buffer + i) == '\n')
	{
		i++;
		*line = ft_substr(*buffer, 0, i);
		res = ft_strdup(*buffer + i);
	}
	else
		*line = ft_strdup(*buffer);
	free_ptr(buffer);
	return (res);
}

static int	read_line(int fd, char **buff, char **buffer, char **line)
{
	int		byte;
	char	*temp;

	byte = 1;
	while (!ft_strchr(*buffer, '\n') && byte)
	{
		byte = read(fd, *buff, BUFFER_SIZE);
		if (byte == -1)
		{
			free_ptr(buffer);
			free_ptr(buff);
			return (-1);
		}
		(*buff)[byte] = '\0';
		temp = *buffer;
		*buffer = ft_strjoin(temp, *buff);
		free(temp);
	}
	free_ptr(buff);
	*buffer = get_line(buffer, line);
	if (!(**line))
		free_ptr(line);
	return (byte);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	if (read_line(fd, &buff, &buffer, &line) == -1 || !line)
		return (NULL);
	return (line);
}