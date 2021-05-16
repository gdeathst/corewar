#include "libft.h"

static int	get_dcount(int n)
{
	int	count;

	count = 1;
	n /= 10;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	ft_itoa2(char *str, int n)
{
	int		i;

	i = 0;
	str[i++] = n % 10 + '0';
	n /= 10;
	while (n)
	{
		str[i++] = n % 10 + '0';
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		len;
	int		i;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	sign = n;
	if (sign < 0)
		n = -n;
	if (sign < 0)
		len = get_dcount(n) + 1;
	else
		len = get_dcount(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	i = ft_itoa2(str, n);
	if (sign < 0)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
