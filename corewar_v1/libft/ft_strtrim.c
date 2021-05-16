/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:47:54 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 12:47:57 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	c;
	size_t	q;
	char	*buf;

	i = 0;
	c = 0;
	q = 0;
	if (s == NULL)
		return (NULL);
	c = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (i - 1 == c)
	{
		if (!(buf = ft_strnew(0)))
			return (NULL);
		return (buf);
	}
	while (s[c] == ' ' || s[c] == '\n' || s[c] == '\t')
		c--;
	q = c - i + 1;
	if (!(buf = ft_strnew(q)))
		return (NULL);
	return (ft_strncpy(buf, &s[i], q));
}
