#include "libft.h"
#include <unistd.h>

void		ft_putstr_fd(char const *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, &*(char *)(s++), 1);
}
