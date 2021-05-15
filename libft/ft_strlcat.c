/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:46:39 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 12:46:41 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (dst[i] && (i < size))
		i++;
	if (i == size)
		return (size + ft_strlen(src));
	while (src[k] && (i < size - 1))
		dst[i++] = src[k++];
	dst[i] = '\0';
	return (i + ft_strlen(src) - k);
}
