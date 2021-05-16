#include "libft.h"

void	ft_putwcstr_fd(const wchar_t *s, int fd)
{
	while (*s)
		ft_putwchar_fd(*s++, fd);
}
