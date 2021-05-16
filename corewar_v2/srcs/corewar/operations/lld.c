/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 23:22:25 by bgilwood          #+#    #+#             */
/*   Updated: 2021/05/16 12:56:34 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_lld(t_carriage *carriage, t_game_params *params, int arg_code)
{
	int		args[2];

	args[0] = get_argument(params->arena, carriage, arg_code >> 6 & 3, 1);
	args[1] = get_address_argument(params->arena, carriage, REG_CODE, 0);
	if (!(args[1] > 0 && args[1] <= REG_NUMBER))
		return ;
	save_registry(carriage, args[1], args[0]);
	if (args[0])
		carriage->carry = 0;
	else
		carriage->carry = 1;
}
