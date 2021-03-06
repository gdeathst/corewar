#include "libft.h"

static size_t	get_wcount(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static size_t	get_wlen(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**del(char **tab, size_t i)
{
	while (i--)
		free(tab[i]);
	free(tab);
	return (NULL);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;

	tab = (char **)malloc(sizeof(char *) * (get_wcount(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			tab[i] = (char *)malloc(sizeof(char) * (get_wlen(s, c) + 1));
			if (!(tab[i]))
				return (del(tab, i));
			j = 0;
			while (*s && *s != c)
				tab[i][j++] = *s++;
			tab[i++][j] = '\0';
		}
	}
	tab[i] = NULL;
	return (tab);
}
