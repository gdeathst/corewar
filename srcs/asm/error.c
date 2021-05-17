#include "asm.h"

static char	*get_param_type_str(t_arg_type type)
{
	if (type == T_REG)
		return ("register");
	if (type == T_DIR)
		return ("direct");
	if (type == T_IND)
		return ("indirect");
	return (NULL);
}

static void	print_syntax_error(int status, t_tok *token, t_line *line, int n)
{
	char	*res;

	if (status == 3)
		ft_dprintf(2, "Syntax error - unexpected end of input "
			"(Perhaps you forgot to end with a newline ?)\n");
	else if (status == 4)
		ft_dprintf(2, "Syntax error at token ");
	else if (status == 5)
		ft_dprintf(2, "Invalid instruction at token ");
	else if (status == 6 || status > 10)
		ft_dprintf(2, "Invalid parameter %d type %s for instruction %s\n", n,
			get_param_type_str(line->arg[n].type), line->op.name);
	else if (status == 7)
		ft_dprintf(2, "Invalid parameter count for instruction %s\n",
			line->op.name);
	else if (status == 8)
	{
		res = token->content + 1;
		if (token->type == DIRECT_LABEL)
			res = token->content + 2;
		ft_dprintf(2, "No such label %s while attempting to dereference token ",
			res);
	}
	print_syntax_error2(status, token);
}

static void	print_lexical_error(int status, t_tok *token)
{
	if (status == 2)
		ft_dprintf(2, "Lexical error at [%d:%d]\n", token->row, token->col);
}

void	print_error(t_exec *info, int status, void *ptr)
{
	if (status == 0)
		ft_dprintf(2, "%s\n", strerror(errno));
	else if (status == 1)
		ft_dprintf(2, "Can't read source file %s\n", info->path);
	else if (status == 2)
		print_lexical_error(status, ptr);
	else if ((status >= 3 && status <= 8) || status > 10)
		print_syntax_error(status, ptr, ptr, status - 11);
	else if (status == 9)
		ft_dprintf(2, "Champion name too long (Max length %d)\n",
			PROG_NAME_LENGTH);
	else if (status == 10)
		ft_dprintf(2, "Champion comment too long (Max length %d)\n",
			COMMENT_LENGTH);
}
