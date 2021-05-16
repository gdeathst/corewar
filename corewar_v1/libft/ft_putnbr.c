/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:45:25 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 12:45:26 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long int res;

	res = n;
	if (res < 0)
	{
		res *= (-1);
		ft_putchar('-');
	}
	if (res > 9)
	{
		ft_putnbr(res / 10);
	}
	ft_putchar(res % 10 + '0');
}
