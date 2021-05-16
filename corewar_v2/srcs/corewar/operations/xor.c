/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 22:33:00 by bgilwood          #+#    #+#             */
/*   Updated: 2021/05/16 17:34:07 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char	help_xor(int a, int b)
{
	if (b)
		return (a ^ 0);
	return (a ^ 1);
}

void	op_xor(t_carriage *carriage, t_game_params *params, int arg_code)
{
	int	args[3];
	int	type[3];
	int	i;

	i = 0;
	while (i < 3)
	{
		type[i] = arg_code >> (8 - (i + 1) * 2) & 3);
		if (type[i] == REG_CODE)
			args[i] = get_address_argument(params->arena, carriage, type[i], 0);
		else
			args[i] = get_argument(params->arena, carriage, type[i], 0);
		i++;
	}
	if ((type[0] == REG_CODE && !(args[0] > 0 && args[0] <= REG_NUMBER))
		|| (type[1] == REG_CODE && !(args[1] > 0 && args[1] <= REG_NUMBER))
		|| (type[2] == REG_CODE && !(args[2] > 0 && args[2] <= REG_NUMBER)))
		return ;
	if (type[0] == REG_CODE)
		args[0] = get_registry(carriage, args[0]);
	if (type[1] == REG_CODE)
		args[1] = get_registry(carriage, args[1]);
	save_registry(carriage, args[2], args[0] ^ args[1]);
	carriage->carry = help_xor(args[0], args[1]);
}
