#include "libft.h"

static void	del(void *elem, size_t size)
{
	ft_bzero(elem, size);
	free(elem);
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*list_ptr;

	list = f(lst);
	list_ptr = list;
	lst = lst->next;
	while (lst)
	{
		list_ptr->next = f(lst);
		if (!(list_ptr->next))
		{
			ft_lstdel(&list, del);
			return (NULL);
		}
		list_ptr = list_ptr->next;
		lst = lst->next;
	}
	return (list);
}
