/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: By: aeminian <aeminian@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:57:20 by adel              #+#    #+#             */
/*   Updated: 2024/11/12 10:57:21 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3d.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_min(int num1, int num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}

char	*ft_substr(char *s, int start, int len)
{
	int				i;
	char			*dest;
	int				s_len;

	if (!s)
		return (NULL);
	i = 0;
	s_len = ft_min(ft_strlen(s), len);
	dest = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!dest)
		return (NULL);
	while (start < ft_strlen(s) && i < len
		&& s[i + start] != '\0')
	{
		dest[i] = s[i + start];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (1);
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void ft_putchar(char *c)
{
	int i = -1;
	while (c[++i])
	{
		write(1, &c[i], 1);
	}
}
char	*trim(char *line)
{
	int		start;
	int		end;
	char	*new;
	char	*tmp;
	int		i;

	if (!line)
		return (NULL);
	start = 0;
	end = ft_strlen(line) - 1;
	while (line[start] && is_space(line[start]))
		start++;
	while (line[end] && is_space(line[end]))
	{
		end--;
		if (end < start)
			return (strdup(""));
	}
	new = malloc(end - start + 2);
	if (!new)
		return (NULL);
	i = 0;
	tmp = new;
	while (start <= end)
		new[i++] = line[start++];
	new[i] = '\0';
	printf("tmp->%s\n", tmp);

	return (tmp);
}
