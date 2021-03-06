#include "corewar.h"

void	op_ld(t_carriage *carriage, t_game_params *params, int arg_code)
{
	int	args[2];

	args[0] = get_argument(params->arena, carriage, arg_code >> 6 & 3, 0);
	args[1] = get_address_argument(params->arena, carriage, REG_CODE, 0);
	if (!(args[1] > 0 && args[1] <= REG_NUMBER))
		return ;
	save_registry(carriage, args[1], args[0]);
	if (args[0])
		carriage->carry = 0;
	else
		carriage->carry = 1;
}
