#include "libft.h"

void	ft_arrdel(char ***arr)
{
	size_t	i;

	if (!arr || !*arr)
		return ;
	i = 0;
	while (*(*arr + i))
	{
		free(*(*arr + i));
		*(*arr + i) = NULL;
		i++;
	}
	free(*arr);
	*arr = NULL;
}
