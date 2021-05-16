#include "libft.h"

void			ft_lstadd(t_list **alst, t_list *new)
{
	t_list *buf;

	if (alst == NULL)
		return ;
	buf = *alst;
	*alst = new;
	new->next = buf;
}
