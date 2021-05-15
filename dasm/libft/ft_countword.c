#include "libft.h"

int			ft_countword(char const *s, char c)
{
	int counter;

	counter = 0;
	while (*s == c && *s)
		s++;
	while (*s)
	{
		while (*s != c && *s)
			s++;
		counter++;
		while (*s == c && *s)
			s++;
	}
	return (counter);
}
