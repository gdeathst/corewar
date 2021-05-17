#include "corewar.h"

void	op_add(t_carriage *carriage, t_game_params *params, int arg_code)
{
	int	args[3];

	args[0] = get_address_argument(params->arena, carriage, REG_CODE, 0);
	args[1] = get_address_argument(params->arena, carriage, REG_CODE, 0);
	args[2] = get_address_argument(params->arena, carriage, REG_CODE, 0);
	if (!(args[0] > 0 && args[0] <= REG_NUMBER)
		|| !(args[1] > 0 && args[1] <= REG_NUMBER)
		|| !(args[2] > 0 && args[2] <= REG_NUMBER))
		return ;
	args[0] = get_registry(carriage, args[0]);
	args[1] = get_registry(carriage, args[1]);
	save_registry(carriage, args[2], args[0] + args[1]);
	carriage->carry = args[0];
	if (!args[1])
		carriage->carry++;
	(void)arg_code;
}
