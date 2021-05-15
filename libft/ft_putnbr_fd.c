/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:45:20 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 12:45:22 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int res;

	res = n;
	if (res < 0)
	{
		res *= (-1);
		ft_putchar_fd('-', fd);
	}
	if (res > 9)
	{
		ft_putnbr_fd((res / 10), fd);
	}
	ft_putchar_fd((res % 10 + '0'), fd);
}
