#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *))
{
	t_list	*newlist;
	t_list	*crawler;

	if (lst == NULL)
		return (NULL);
	newlist = f(lst);
	crawler = newlist;
	while (lst->next)
	{
		lst = lst->next;
		crawler->next = f(lst);
		crawler = crawler->next;
	}
	return (newlist);
}
