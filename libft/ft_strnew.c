/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:47:27 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 12:47:29 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_strnew(size_t size)
{
	char	*b;
	size_t	i;

	i = 0;
	if (!(b = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size)
		b[i++] = '\0';
	b[i++] = '\0';
	return (b);
}
