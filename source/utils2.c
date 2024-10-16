# include "../include/cub3d.h"

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
