#include "corewar.h"

void	print_error_msg(char *str, char *filename)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("ERROR: ", 2);
	if (filename)
	{
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(str, 2);
	ft_putstr_fd(RESET_COLOR, 2);
}

void	error(char *str, char *filename)
{
	print_error_msg(str, filename);
	write(2, "\n", 1);
	exit(1);
}
