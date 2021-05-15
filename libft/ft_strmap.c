/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:46:58 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 12:47:00 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*buf;
	int		i;

	i = -1;
	if (s == NULL)
		return (NULL);
	if (!(buf = (char*)malloc(ft_strlen(s) + 1)))
		return (NULL);
	while (s[++i])
		buf[i] = f(s[i]);
	buf[i] = '\0';
	return (buf);
}
