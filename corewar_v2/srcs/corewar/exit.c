#include "corewar.h"

void	delete_all(t_game_params *params, t_car_list_elem *carriages)
{
	delete_carriage_list(carriages);
	free_params(&params);
}

void	dump_mem_and_exit(t_game_params *params, t_car_list_elem *carriages)
{
	dump_memory(params);
	delete_all(params, carriages);
	exit(0);
}

void	game_over(t_game_params *params, t_car_list_elem *carriages)
{
	if (params->v_flag_on)
		return ;
	announce_winner(params);
	delete_all(params, carriages);
	exit(0);
}
