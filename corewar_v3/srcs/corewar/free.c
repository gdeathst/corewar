#include "corewar.h"

void	free_parts(char **array)
{
	int	i;

	if (!array || !*array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

void	free_players(t_player ***player)
{
	int			i;

	if (!player || !*player)
		return ;
	i = 0;
	while ((*player)[i])
	{
		free((*player)[i]->name);
		free((*player)[i]->filename);
		free((*player)[i]->comment);
		free((*player)[i]->code);
		free((*player)[i]);
		i++;
	}
	free(*player);
	*player = NULL;
}

void	free_params(t_game_params **params)
{
	if (!params || !*params)
		return ;
	free_players(&(*params)->players);
	free((*params)->arena);
	ft_bzero(*params, sizeof(t_game_params));
	free(*params);
	*params = NULL;
}

void	delete_carriage(t_carriage *carriage)
{
	free(carriage);
}
