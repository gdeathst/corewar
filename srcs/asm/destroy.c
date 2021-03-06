#include "asm.h"

static void	destroy_lines(t_exec *info)
{
	t_line	*tmp;
	t_line	*next;

	tmp = info->line;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

static void	destroy_tokens(t_exec *info)
{
	t_tok	*tmp;
	t_tok	*next;

	tmp = info->token;
	while (tmp)
	{
		next = tmp->next;
		if (tmp->content)
			free(tmp->content);
		free(tmp);
		tmp = next;
	}
}

void	destroy_struct(t_exec *info)
{
	free(info->filename);
	free(info->buf);
	destroy_tokens(info);
	destroy_lines(info);
}
