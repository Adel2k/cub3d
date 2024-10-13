# include "../include/cub3d.h"

static size_t	word_count(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != 32 && !(s[i] >= 9 && s[i] <= 13) && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != 32 && \
			!(s[i] >= 9 && s[i] <= 13) && s[i] != c)
			{
				i++;
				if (s[i] == 0)
					break ;
			}
		}
		else if (s[i] == 32 || (s[i] >= 9 && s[i] <= 13) || s[i] == c)
			i++;
	}
	return (count);
}

static char	**split(char **memory, char *s, char c, char **temp)
{
	int		i;
	int		j;

	i = 0;
	temp = memory;
	while (s[i])
	{
		if (s[i] != 32 && !(s[i] >= 9 && s[i] <= 13) && s[i] != c)
		{
			j = i;
			while ((s[i] != 32 && !(s[i] >= 9 && s[i] <= 13)) \
			&& s[i] != '\0' && s[i] != c)
				i++;
			if (s[i] == 32 || (s[i] >= 9 && s[i] <= 13) \
			|| s[i] == 0 || s[i] == c)
			{
				*temp = ft_substr(s, j, i - j);
				temp++;
			}
		}
		else
			i++;
	}
	*temp = 0;
	return (memory);
}

char	**ft_split(char *s, char c)
{
	char	**memory;
	char	*temp;
	int		i;

	temp = NULL;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13) || *s == c)
	{
		i++;
		if (s[i] == 0)
			return (NULL);
	}

	memory = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!memory)
		return (NULL);
	return (split(memory, s, c, &temp));
}
