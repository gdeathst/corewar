#include "disasm.h"

void	push_back(t_instruction **head, t_instruction *new)
{
	t_instruction	*tmp;

	if (!head)
		error("Pointer is not initialized.");
	if (!*head)
	{
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_bin	*init_bin(void)
{
	t_bin	*bin;

	bin = (t_bin *)ft_memalloc(sizeof(t_bin));
	if (!(bin))
		error("Malloc failure.");
	return (bin);
}

t_instruction	*init_instruction(void)
{
	t_instruction	*instr;

	instr = (t_instruction *)ft_memalloc(sizeof(t_instruction));
	if (!(instr))
		error("Malloc failure.");
	return (instr);
}
