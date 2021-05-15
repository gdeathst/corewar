#include "libft.h"

char		*ft_strcat(char *s1, const char *s2)
{
	int i;
	int n;

	n = ft_strlen(s1);
	i = -1;
	while (s2[++i])
		s1[i + n] = s2[i];
	s1[i + n] = '\0';
	return (s1);
}
