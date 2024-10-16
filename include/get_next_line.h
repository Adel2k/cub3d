/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel <adel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:59:36 by aeminian          #+#    #+#             */
/*   Updated: 2024/10/16 18:22:04 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

char		*get_next_line(int fd);
char		*ft_strchr(const char *str, int argument);
size_t		ft_strlcpy(char *dest, const char *src, size_t destsize);
char		*ft_strjoin(char *s1, char *s2);

#endif
