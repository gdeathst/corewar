/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:43:31 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 12:43:33 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *i;

	if (lst == NULL)
		return (NULL);
	new = f(lst);
	i = new;
	while (lst->next)
	{
		lst = lst->next;
		i->next = f(lst);
		i = i->next;
	}
	return (new);
}
