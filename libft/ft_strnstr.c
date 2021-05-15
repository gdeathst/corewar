/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:47:31 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 12:47:33 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t l;

	l = ft_strlen(little);
	if (l == 0)
		return ((char *)big);
	len++;
	while (*big++ && len-- != 0 && l <= len)
		if (ft_strncmp(big - 1, little, l) == 0)
			return (char *)big - 1;
	return (NULL);
}
