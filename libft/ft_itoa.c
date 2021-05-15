/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:43:07 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 12:43:09 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strrvs(char *s)
{
	char	buf;
	char	*t;
	size_t	i;
	size_t	k;

	t = s;
	i = 0;
	k = ft_strlen(s) - 1;
	if (t[i] == '-')
	{
		i++;
		k += 1;
	}
	while (i <= k / 2)
	{
		buf = t[i];
		t[i] = t[k - i];
		t[k - i] = buf;
		i++;
	}
	return (s);
}

static char		*ft_fill(char *s, int n)
{
	long int	res;
	char		*buf;

	buf = s;
	res = n;
	if (res < 0)
	{
		res *= (-1);
		*buf = '-';
		buf++;
	}
	if (res > 9)
		ft_fill(buf + 1, res / 10);
	*buf = res % 10 + '0';
	return (s);
}

char			*ft_itoa(int n)
{
	char	*buf;

	if (!(buf = ft_strnew(ft_lenitoa(n))))
		return (NULL);
	return (ft_strrvs(ft_fill(buf, n)));
}
