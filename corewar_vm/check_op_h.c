/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op_h.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:25:09 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 12:25:10 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int	for_check_op_h(void)
{
	if (T_REG != 1)
	{
		ft_printf(RED"Error:"RC"\n\t\t"BLU"Incorrect T_REG\n"RC);
		return (0);
	}
	if (T_DIR != 2)
	{
		ft_printf(RED"Error:"RC"\n\t\t"BLU"Incorrect T_DIR_\n"RC);
		return (0);
	}
	if (T_IND != 4)
	{
		ft_printf(RED"Error:"RC"\n\t\t"BLU"Incorrect T_IND\n"RC);
		return (0);
	}
	return (1);
}

int	check_op_h(void)
{
	if (MAX_PLAYERS > 4 || MAX_PLAYERS <= 0)
	{
		ft_printf(RED"Error:"RC"\n\t\t"BLU"Incorrect MAX_PLAERS\n"RC);
		return (0);
	}
	if (MEM_SIZE != 4096)
	{
		ft_printf(RED"Error:"RC"\n\t\t"BLU"Incorrect MEM_SIZE\n"RC);
		return (0);
	}
	if (IDX_MOD != 512)
	{
		ft_printf(RED"Error:"RC"\n\t\t"BLU"Incorrect IDX_MOD\n"RC);
		return (0);
	}
	if (CHAMP_MAX_SIZE != 682)
	{
		ft_printf(RED"Error:"RC"\n\t\t"BLU"Incorrect CHAMP_MAX_SIZE\n"RC);
		return (0);
	}
	return (for_check_op_h());
}
