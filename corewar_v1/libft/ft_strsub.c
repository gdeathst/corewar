/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:47:51 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 12:47:52 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*buf;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if ((buf = ft_strnew(len)) == NULL)
		return (NULL);
	while (len--)
	{
		buf[i] = s[start + i];
		i++;
	}
	return (buf);
}
