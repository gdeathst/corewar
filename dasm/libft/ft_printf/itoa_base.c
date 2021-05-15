/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 19:26:46 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 19:26:47 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			*ft_vstrrev(char *s)
{
	char *end;
	char *start;
	char c;

	start = s;
	end = s + ft_strlen(s) - 1;
	while (s < end)
	{
		c = *s;
		*s++ = *end;
		*end-- = c;
	}
	return (start);
}

static int			ft_wordnum(long long int n, int base)
{
	int i;

	i = 0;
	(n <= 0 && base == 10) ? (i++) : (0);
	while (n != 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

char				*ft_itoabase(long long int n, int base, char *l)
{
	char			*buf;
	long long int	lol;
	int				i;

	i = 0;
	if (n + 1 == -9223372036854775807)
		return ("9223372036854775808");
	if (!(buf = ft_strnew((size_t)ft_wordnum(n, base))))
		return (NULL);
	(n < 0 && base == 10) ? n *= -1 : 0;
	if ((n == 0) ? buf[0] = '0' : 0)
		i++;
	while (n != 0)
	{
		lol = n % (unsigned long long int)base;
		(lol < 0) ? lol *= -1 : 0;
		(lol > 9) ? lol += 7 : 0;
		buf[i++] = lol + '0';
		n /= base;
	}
	buf[i] = '\0';
	l = ft_vstrrev(buf);
	ft_strdel(&buf);
	return (l);
}

char				*ft_unitoabase(unsigned long long int n, \
	int base, char *lick)
{
	char			*buf;
	long long int	lol;
	int				i;
	int				wordnum;

	i = 0;
	wordnum = ft_wordnum(n, base);
	if (!(buf = ft_strnew((size_t)wordnum)))
		return (NULL);
	if ((n == 0) ? buf[0] = '0' : 0)
		i++;
	while (n != 0)
	{
		lol = n % (unsigned long long int)base;
		(lol < 0) ? lol *= -1 : 0;
		(lol > 9) ? lol += 7 : 0;
		buf[i++] = lol + '0';
		n /= base;
	}
	buf[i] = '\0';
	ft_strrev(buf);
	lick = buf;
	ft_strdel(&buf);
	return (lick);
}
