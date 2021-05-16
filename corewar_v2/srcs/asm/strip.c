#include "asm.h"

static void	strip_two_endlines(t_exec *info)
{
	t_tok	*tptr;
	t_tok	*next;

	tptr = info->token;
	while (tptr->type == ENDLINE)
	{
		info->token = info->token->next;
		free(tptr->content);
		free(tptr);
	}
	next = tptr->next;
	while (next->type && next->next)
	{
		if (next->type == ENDLINE && next->next->type == ENDLINE)
		{
			tptr->next = next->next;
			free(next->content);
			free(next);
		}
		else
			tptr = tptr->next;
		next = tptr->next;
	}
}

static void	strip_whitespace(t_exec *info)
{
	t_tok	*tptr;
	t_tok	*next;

	tptr = info->token;
	while (tptr->type == WHITESPACE)
	{
		info->token = info->token->next;
		free(tptr->content);
		free(tptr);
		tptr = info->token;
	}
	next = tptr->next;
	while (next)
	{
		if (next->type == WHITESPACE)
		{
			tptr->next = next->next;
			free(next->content);
			free(next);
		}
		else
			tptr = tptr->next;
		next = tptr->next;
	}
}

static void	strip_comments(t_exec *info)
{
	t_tok	*tptr;
	t_tok	*next;

	tptr = info->token;
	while (tptr->type == COMMENT)
	{
		info->token = info->token->next;
		free(tptr->content);
		free(tptr);
	}
	next = tptr->next;
	while (next)
	{
		if (next->type == COMMENT)
		{
			tptr->next = next->next;
			free(next->content);
			free(next);
		}
		else
			tptr = tptr->next;
		next = tptr->next;
	}
}

void	strip_tokens(t_exec *info)
{
	strip_comments(info);
	strip_whitespace(info);
	strip_two_endlines(info);
}
