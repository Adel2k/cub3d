# include "../include/cub3d.h"

static size_t	word_count(const char *s)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != 32 && !(s[i] >= 9 && s[i] <= 13))
		{
			count++;
			while (s[i] && s[i] != 32 && \
			!(s[i] >= 9 && s[i] <= 13))
			{
				i++;
				if (s[i] == 0)
					break ;
			}
		}
		else if (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
			i++;
	}
	return (count);
}

static char	**split(char **memory, char *s, char **temp)
{
	int		i;
	int		j;

    printf("-----%s\n", s);
	i = 0;
	temp = memory;
	while (s[i])
	{
		if (s[i] != 32 && !(s[i] >= 9 && s[i] <= 13))
		{
			j = i;
			while ((s[i] != 32 && !(s[i] >= 9 && s[i] <= 13)) \
			&& s[i] != '\0')
				i++;
			if (s[i] == 32 || (s[i] >= 9 && s[i] <= 13) \
			|| s[i] == 0)
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

char	**ft_split(char *s)
{
	char	**memory;
	char	*temp;
	int		i;

	temp = NULL;
	i = 0;
	if (!s)
		return (NULL);
	printf("s ==== %s\n", s);
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
	{
		i++;
		if (s[i] == 0)
			return (NULL);
	}

	memory = (char **)malloc(sizeof(char *) * (word_count(s) + 1));
	if (!memory)
		return (NULL);
	return (split(memory, s, &temp));
}
