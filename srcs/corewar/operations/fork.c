#include "corewar.h"

void	op_fork(t_carriage *carriage, t_game_params *params, int arg_code)
{
	int			arg;
	t_carriage	*copy;

	arg = get_argument(params->arena, carriage, DIR_CODE, 0);
	copy = duplicate_carriage(carriage, params->carriages_num + 1,
			carriage->cur_position + (arg % IDX_MOD));
	insert_existing_carriage(&(params->carriages_list), copy);
	params->carriages_num++;
	(void)arg_code;
}
