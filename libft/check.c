/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:40:27 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 12:40:30 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_type(char c)
{
	if (c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o' || c == 'u'
		|| c == 'U' || c == 'X' || c == 'x' || c == 'c' || c == 'D' || c == 'O'
		|| c == 'b' || c == 'n' || c == 'C' || c == 'S')
		return (1);
	return (0);
}

int		check_length(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	return (0);
}

int		check_flags(char c)
{
	if (c == ' ' || c == '-' || c == '+' || c == '#' || c == '0' || c == '.'
			|| c == '*')
		return (1);
	return (0);
}

int		check_minus_in_type(char c)
{
	if (c == '-')
		return (1);
	return (0);
}

int		isdigit_withoutziro(char c)
{
	if (c >= '1' && c <= '9')
		return (1);
	return (0);
}
