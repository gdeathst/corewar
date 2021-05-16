#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(s);
	while ((ft_isblank(s[len - 1]) || s[len - 1] == '\n') && len)
		len--;
	j = 0;
	while ((ft_isblank(s[j]) || s[j] == '\n') && len)
	{
		j++;
		len--;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (len--)
		str[i++] = s[j++];
	str[i] = '\0';
	return (str);
}
