#include "libft.h"

char	*ft_strrev(char *str)
{
	char	tmp;
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i++] = str[j];
		str[j--] = tmp;
	}
	return (str);
}
