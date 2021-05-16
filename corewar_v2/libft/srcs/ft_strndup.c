#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;

	s2 = (char *)malloc(sizeof(char) * (n + 1));
	if (!s2)
		return (NULL);
	ft_strncpy(s2, s1, n);
	s2[n] = '\0';
	return (s2);
}
