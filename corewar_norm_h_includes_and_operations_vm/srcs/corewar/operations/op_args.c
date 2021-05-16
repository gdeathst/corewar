/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:03:14 by bgilwood          #+#    #+#             */
/*   Updated: 2021/05/16 16:21:54 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	help_get_argument(int type)
{
	if (type == IND_CODE)
		return (IND_SIZE);
	return (1);
}

static int	help(char *arena, int position, int size_bytes, int l_op)
{
	int		temp;

	temp = read_number(arena, position, size_bytes);
	if (!l_op)
		return (temp % 16);
	return (temp);
}

int	get_argument(char *arena, t_carriage *carriage, int arg_type, int l_op)
{
	int		temp;
	int		num;
	int		position;
	int		dir_size;

	dir_size = DIR_SIZE;
	if (g_op_tab[carriage->code_op - 1].idx)
		dir_size = IND_SIZE;
	position = carriage->cur_position + carriage->bytes_next_op;
	if (arg_type == DIR_CODE)
		num = read_number(arena, position, dir_size);
	if (arg_type == IND_CODE)
	{
		temp = help (arena, position, IND_SIZE, l_op);
		num = read_number(arena, get_new_coord(carriage->cur_position + temp),
				DIR_SIZE);
	}
	if (arg_type == REG_CODE)
		num = get_registry(carriage, arena_read_byte(arena, position));
	if (arg_type == DIR_CODE)
		carriage->bytes_next_op += dir_size;
	else
		carriage->bytes_next_op += help_get_argument(arg_type);
	return (num);
}

int	get_address_argument(char *arena, t_carriage *carriage, int arg_type,
	int l_op)
{
	int		num;
	int		position;

	position = carriage->cur_position + carriage->bytes_next_op;
	if (arg_type == IND_CODE)
	{
		num = read_number(arena, position, IND_SIZE);
		if (!_op)
			num = num % 16;
	}
	if (arg_type == REG_CODE)
		num = arena_read_byte(arena, position);
	carriage->bytes_next_op += help_get_argument(arg_type);
	return (num);
}

int	fill_reg_arg(int *arg, char *arena, t_carriage *carriage)
{
	*arg = get_address_argument(arena, carriage, REG_CODE, 0);
	if (*arg < 1 || *arg > REG_NUMBER)
		return (0);
	*arg = get_registry(carriage, *arg);
	return (1);
}
