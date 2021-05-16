/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:45:11 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 12:45:13 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char const *s, int fd)
{
	int	i;

	i = -1;
	if (s != NULL)
	{
		while (s[++i])
			ft_putchar_fd(s[i], fd);
		write(fd, "\n", 1);
	}
}
