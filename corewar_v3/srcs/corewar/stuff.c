#include "corewar.h"

int32_t	return_res_sign(int32_t sign)
{
	if (sign)
		return (-1);
	return (1);
}

int32_t	bin_to_num(uint8_t *val, size_t len)
{
	int32_t	sign;
	int32_t	res;
	size_t	i;
	uint8_t	*tmp;

	i = 0;
	res = 0;
	tmp = (uint8_t *)ft_memalloc(sizeof(uint8_t) * len);
	if (!(tmp))
		error("Malloc failure.", NULL);
	tmp = ft_memcpy(tmp, val, len);
	sign = 0;
	if (tmp[0] & 0x80)
		sign = 1;
	while (i < len)
	{
		if (sign)
			tmp[len - i - 1] = ~tmp[len - i - 1];
		res += tmp[len - i - 1] << (8 * i);
		i++;
	}
	res += sign;
	free(tmp);
	return (res * return_res_sign(sign));
}

void	print_usage(char *name)
{
	ft_printf("Usage: %s [-s] [-v] [[-dump nbr_cycles] "
		"[[-n number] champion1.cor] ...\n", name);
	ft_printf("    -s               : Silence output from \"live\" and \"aff\""
		"\n");
	ft_printf("    -dump nbr_cycles : At the end of nbr_cycles of executions, "
		"dump the memory on the standard output and quit the game\n");
	ft_printf("    -n number        : Sets the number of the next player\n");
	ft_printf("    -v               : Starts visualizer\n");
	exit(1);
}

int	rows_count(char **arr)
{
	int		i;

	i = 0;
	while (arr && *(arr + i))
		i++;
	return (i);
}
