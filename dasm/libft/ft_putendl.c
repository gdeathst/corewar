#include "libft.h"
#include <unistd.h>

void			ft_putendl(char const *s)
{
	if (!s)
		return ;
	ft_putstr(s);
	write(1, "\n", 1);
}
