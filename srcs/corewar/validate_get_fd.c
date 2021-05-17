#include "corewar.h"

static void	check_filename(char *filename)
{
	char	**filename_parts;

	filename_parts = ft_strsplit(filename, '.');
	if (!(filename_parts))
		error("Malloc failure.", filename);
	if (!ft_strequ(filename_parts[rows_count(filename_parts) - 1], "cor"))
		error("invalid extension.", filename);
	ft_arrdel(&filename_parts);
}

void	get_fd(int *fd, t_game_params *p, int i)
{
	check_filename(p->players[i]->filename);
	*fd = open(p->players[i]->filename, O_RDONLY);
}
