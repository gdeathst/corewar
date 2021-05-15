/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:47:47 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 12:47:48 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t l;

	l = ft_strlen(little);
	if (l == 0)
		return ((char *)big);
	while (*(big++))
		if (ft_strncmp(big - 1, little, l) == 0)
			return (char *)big - 1;
	return (NULL);
}
