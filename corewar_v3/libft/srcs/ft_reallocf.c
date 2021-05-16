#include "libft.h"

void	*ft_reallocf(void *ptr, size_t size)
{
	void	*nptr;

	nptr = realloc(ptr, size);
	if (!nptr && size)
		free(ptr);
	return (nptr);
}
