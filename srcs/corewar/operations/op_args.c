#include "corewar.h"

void	get_argument2(int arg_type, t_carriage *carriage, int dir_size)
{
	if (arg_type == DIR_CODE)
		carriage->bytes_next_op += dir_size;
	else
	{
		if (arg_type == IND_CODE)
			carriage->bytes_next_op += IND_SIZE;
		else
			carriage->bytes_next_op += 1;
	}
}

int	get_argument(char *arena, t_carriage *carriage, int arg_type, int l_op)
{
	int		temp;
	int		num;
	int		position;
	int		dir_size;

	if (g_op_tab[carriage->code_op - 1].idx)
		dir_size = IND_SIZE;
	else
		dir_size = DIR_SIZE;
	position = carriage->cur_position + carriage->bytes_next_op;
	if (arg_type == DIR_CODE)
		num = read_number(arena, position, dir_size);
	if (arg_type == IND_CODE)
	{
		temp = read_number(arena, position, IND_SIZE);
		if (!l_op)
			temp = temp % IDX_MOD;
		num = read_number(arena, get_new_coord(carriage->cur_position + temp),
				DIR_SIZE);
	}
	if (arg_type == REG_CODE)
		num = get_registry(carriage, arena_read_byte(arena, position));
	get_argument2(arg_type, carriage, dir_size);
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
		if (!l_op)
			num = num % IDX_MOD;
	}
	if (arg_type == REG_CODE)
		num = arena_read_byte(arena, position);
	if (arg_type == IND_CODE)
		carriage->bytes_next_op += IND_SIZE;
	else
		carriage->bytes_next_op += 1;
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
