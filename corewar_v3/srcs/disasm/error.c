#include "disasm.h"

void	error(char *str)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("ERROR: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(RESET_COLOR, 2);
	write(2, "\n", 1);
	exit(1);
}
