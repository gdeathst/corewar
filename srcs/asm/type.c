#include "asm.h"

t_type	ft_check_direct(const char *s);

t_type	ft_check_inderect(const char *s);

static bool	is_register(char *s)
{
	if (ft_strlen(s) > 3 || *s++ != REG_CHAR || !ft_isdigit(*s++))
		return (false);
	while (ft_isdigit(*s))
		s++;
	if (!*s)
		return (true);
	return (false);
}

t_type	get_token_type(char *s)
{
	if (!s)
		return (END);
	if (!ft_strcmp(s, NAME_CMD_STRING))
		return (COMMAND_NAME);
	if (!ft_strcmp(s, COMMENT_CMD_STRING))
		return (COMMAND_COMMENT);
	if (*s == STRING_CHAR)
		return (STRING);
	if (is_register(s))
		return (REGISTER);
	if (*s == DIRECT_CHAR)
		return (ft_check_direct(s));
	if (ft_isdigit(*s) || *s == '-' || *s == LABEL_CHAR)
		return (ft_check_inderect(s));
	if (*s == '\n')
		return (ENDLINE);
	if (*s == SEPARATOR_CHAR)
		return (SEPARATOR);
	if (*s == COMMENT_CHAR || *s == COMMENT_CHAR_2)
		return (COMMENT);
	if (ft_isspace(*s))
		return (WHITESPACE);
	if (s[ft_strlen(s) - 1] == LABEL_CHAR)
		return (LABEL);
	return (INSTRUCTION);
}

t_type	ft_check_inderect(const char *s)
{
	if (*s == LABEL_CHAR)
		return (INDIRECT_LABEL);
	else
		return (INDIRECT);
}

t_type	ft_check_direct(const char *s)
{
	if (*(s + 1) == LABEL_CHAR)
		return (DIRECT_LABEL);
	else
		return (DIRECT);
}
