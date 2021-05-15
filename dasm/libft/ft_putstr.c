#include "libft.h"
#include <unistd.h>

void			ft_putstr(char const *s)
{
	if (!s)
		return ;
	while (*s)
		write(1, &*(char *)(s++), 1);
}
