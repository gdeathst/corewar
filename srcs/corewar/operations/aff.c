#include "corewar.h"

void	op_aff(t_carriage *carriage, t_game_params *params, int arg_code)
{
	int	c;

	c = get_address_argument(params->arena, carriage, arg_code >> 6 & 3, 0);
	if (!(c > 0 && c <= REG_NUMBER))
		return ;
	c = get_registry(carriage, c);
	if (!params->s_flag_on && !params->v_flag_on)
		ft_putchar(c);
}
