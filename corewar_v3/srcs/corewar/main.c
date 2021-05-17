#include "corewar.h"

int	main(int ac, char **av)
{
	t_game_params	*params;
	t_car_list_elem	*carriages;

	if (ac < 2)
		print_usage(av[0]);
	params = init_game_params();
	get_args(ac, av, params);
	validate_players(params);
	params->arena = arena_init();
	carriages = place_players(params->players, params->arena);
	params->carriages_list = carriages;
	if (params->v_flag_on)
		visualise(params);
	announce_players(params->players);
	play_game(params);
	delete_carriage_list(carriages);
	free_params(&params);
	return (0);
}
