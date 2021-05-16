#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;

	i = -1;
	j = ft_strlen(s1);
	while (s2[++i] && i < n)
		s1[i + j] = s2[i];
	s1[i + j] = '\0';
	return (s1);
}