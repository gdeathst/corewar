#include "libft.h"
#include <stdlib.h>

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list *ret;

	if (!(ret = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		ret->content = NULL;
		ret->content_size = 0;
	}
	else
	{
		ret->content = malloc(content_size);
		if (content == NULL)
		{
			free(ret);
			return (NULL);
		}
		ft_memcpy(ret->content, content, content_size);
		ret->content_size = content_size;
	}
	ret->next = NULL;
	return (ret);
}
