#include "libft.h"

void	ft_padchar(char c, size_t len)
{
	while (len--)
		ft_putchar(c);
}
