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

int	is_space(char c)
{
	if (c == 32 || ( c >= 9 && c <= 13 ))
		return (1);
	return (0);
}
void	error(char *msg)
{
	write(2, "Error:", 7);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

char	*trim(char *line)
{
	int		start;
	int		end;
	char	*new;
	int		i;

	if (!line)
		return (NULL);
	start = 0;
	end = ft_strlen(line);
	while (is_space(line[start]))
		start++;
	while (is_space(line[end]))
		end--;
	new = malloc(end - start + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (start < end)
		new[i++] = line[start++];
	new[i] = 0;
	return (new);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_p;
	unsigned char	*src_p;

	src_p = (unsigned char *)src;
	dest_p = (unsigned char *)dest;
	if (dest == 0 && src == 0)
		return (NULL);
	while (n != 0)
	{
		*dest_p++ = *src_p++;
		n--;
	}
	return (dest);
}

char	*ft_strdup(char *s)
{
	char		*str;
	int			size;
	char		*result;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	result = (char *)ft_memcpy((void *)str, s, size);
	result[size] = '\0';
	return (result);
}

void	malloc_check(char *str)
{
	if (!str)
	{
		write(2, "Error:allocation failed.\n", 26);
		exit(EXIT_FAILURE);
	}
}