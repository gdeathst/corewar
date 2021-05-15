#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	if (s1 == NULL && s2 == NULL)
		return (ft_strnew(0));
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	if (!(res = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	res = ft_strcat(ft_strcpy(res, s1), s2);
	return (res);
}
