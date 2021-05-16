/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 22:49:52 by bgilwood          #+#    #+#             */
/*   Updated: 2021/05/16 16:41:29 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_zjmp(t_carriage *carriage, t_game_params *params, int arg_code)
{
	int	arg;

	arg = get_argument(params->arena, carriage, DIR_CODE, 0);
	if (carriage->carry)
	{
		move_carriage(carriage, arg % IDX_MOD);
		carriage->bytes_next_op = 0;
	}
	(void)arg_code;
}
