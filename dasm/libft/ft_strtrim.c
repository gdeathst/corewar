#include "libft.h"

static	int			littlespace(char c)
{
	return ((c == '\t' || c == ' ' || c == '\n') ? 1 : 0);
}

char				*ft_strtrim(char const *s)
{
	char	*buf;
	char	*d;
	int		len;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (littlespace(s[i]) == 1)
		i++;
	if (i == len)
		return ((buf = ft_strnew(0)) ? buf : NULL);
	while (littlespace(s[(len-- - 1)]) == 1)
		;
	if (!(buf = (char *)ft_strnew(len - i + 1)))
		return (NULL);
	d = buf;
	while (i - 1 != len)
		*(char *)buf++ = s[i++];
	*buf = '\0';
	return ((char *)d);
}
