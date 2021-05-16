/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:43:36 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 12:43:37 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*buf;

	if (!(buf = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		buf->content = NULL;
		buf->content_size = 0;
	}
	else
	{
		if (!(buf->content = ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(buf->content, content, content_size);
		buf->content_size = content_size;
	}
	buf->next = NULL;
	return (buf);
}
