#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char *buf;
	char *d;

	if (s == NULL || !(buf = ft_strnew(ft_strlen(s))))
		return (NULL);
	d = buf;
	while (*s)
		*buf++ = f(*s++);
	*buf = '\0';
	return (d);
}
