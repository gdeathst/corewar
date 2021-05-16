/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:46:35 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 12:46:37 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *buf;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(buf = ft_strnew((ft_strlen(s1) + ft_strlen(s2)))))
		return (NULL);
	buf = ft_strcpy((char *)buf, s1);
	return (buf = ft_strcat(buf, s2));
}
