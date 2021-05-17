#include "corewar.h"

void	op_live(t_carriage *carriage, t_game_params *params, int arg_code)
{
	int	player;

	player = -get_argument(params->arena, carriage, DIR_CODE, 0);
	live_carriage(carriage, params->cycles_since_start);
	params->live_count_in_period++;
	if (player > params->players_num || player < 1)
		return ;
	params->last_alive = player;
	announce_player_alive(params, player);
	(void)arg_code;
}
