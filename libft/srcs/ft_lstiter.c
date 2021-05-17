#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	f(lst);
	lst = lst->next;
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}
