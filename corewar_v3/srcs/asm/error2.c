#include "asm.h"

static char	*get_token_type_str(t_type type)
{
	if (type == COMMAND_NAME)
		return ("COMMAND_NAME");
	if (type == COMMAND_COMMENT)
		return ("COMMAND_COMMENT");
	if (type == STRING)
		return ("STRING");
	if (type == LABEL)
		return ("LABEL");
	if (type == INSTRUCTION)
		return ("INSTRUCTION");
	if (type == REGISTER)
		return ("REGISTER");
	if (type == DIRECT)
		return ("DIRECT");
	if (type == DIRECT_LABEL)
		return ("DIRECT_LABEL");
	if (type == INDIRECT)
		return ("INDIRECT");
	if (type == INDIRECT_LABEL)
		return ("INDIRECT_LABEL");
	if (type == ENDLINE)
		return ("ENDLINE");
	if (type == SEPARATOR)
		return ("SEPARATOR");
	return ("END");
}

void	print_syntax_error2(int status, t_tok *token)
{
	if (status == 4 || status == 5 || status == 8)
	{
		if (token->type != ENDLINE)
			ft_dprintf(2, "[TOKEN][%03d:%03d] %s \"%s\"\n", token->row,
				token->col, get_token_type_str(token->type), token->content);
		else
			ft_dprintf(2, "[TOKEN][%03d:%03d] %s\n", token->row, token->col,
				get_token_type_str(token->type));
	}
}
