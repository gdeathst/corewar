/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 19:26:50 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 19:26:52 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	HERE IS COPY OF STANDART LIBFT FUNCTIONS :
**	ft_tolower | ft_strlen | ft_isdigit | ft_strchr
*/

/*
** V for vendetta, K for kostul'
*/

char		*ft_kstrchr(const char *s, int c)
{
	char *k;

	k = "K";
	while (1)
	{
		if (*s == (char)c)
			return ((char *)s);
		if (!*s)
			break ;
		s++;
	}
	return (k);
}
