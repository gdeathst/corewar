#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	len;

	len = ft_strlen(s1);
	while (*s2 && n--)
		s1[len++] = *s2++;
	s1[len] = '\0';
	return (s1);
}
