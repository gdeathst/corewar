#include "asm.h"

void	terminate(t_exec *info, int status, void *ptr)
{
	print_error(info, status, ptr);
	destroy_struct(info);
	exit(EXIT_FAILURE);
}
