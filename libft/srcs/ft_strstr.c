#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (!needle[++j])
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
