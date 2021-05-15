/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:43:39 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 12:43:41 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*buf;
	size_t			i;

	i = 0;
	if (!(buf = (void *)malloc(sizeof(buf) * size)))
		return (NULL);
	while (++i <= size)
		buf[i - 1] = 0;
	return (buf);
}
