/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:47:39 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 12:47:41 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char			**buf;
	unsigned int	i;
	size_t			k;
	size_t			t;

	i = 0;
	t = 0;
	if (s == NULL)
		return (NULL);
	if (!(buf = (char **)ft_memalloc(sizeof(char*) * (ft_cntwrd(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if ((s[i] != c))
		{
			k = 0;
			while (s[i + k] != c && s[i + k])
				k++;
			if (!(buf[t++] = ft_strsub(s, i, k)))
				return (NULL);
			i += k - 1;
		}
		i++;
	}
	return (buf);
}
