/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:47:10 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 12:47:12 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t l;

	i = 0;
	l = ft_strlen(s1);
	while (s2[i] && i < n)
	{
		s1[i + l] = s2[i];
		i++;
	}
	s1[i + l] = '\0';
	return (s1);
}
