/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:45:16 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 12:45:18 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl(char const *s)
{
	int	i;

	i = -1;
	if (s != NULL)
		while (s[++i])
			ft_putchar(s[i]);
	write(1, "\n", 1);
}
