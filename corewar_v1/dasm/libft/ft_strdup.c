#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*dup;
	char	*buf;

	if (!(dup = (char *)malloc(sizeof(*dup) * (ft_strlen(str) + 1))))
		return (NULL);
	buf = dup;
	while (*str)
		*dup++ = *(char *)str++;
	*dup = '\0';
	return (buf);
}
