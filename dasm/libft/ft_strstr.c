#include "libft.h"

char		*ft_strstr(const char *big, const char *little)
{
	size_t l_len;

	if (*little == '\0')
		return ((char *)big);
	l_len = ft_strlen((char *)little);
	while (*big)
		if (ft_strncmp(big++, little, l_len) == 0)
			return ((char *)(big - 1));
	return (NULL);
}
