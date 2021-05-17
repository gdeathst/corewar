#include "disasm.h"

static size_t	read_arg_val(uint8_t *code, t_instruction *instr)
{
	size_t	j;
	size_t	code_idx;
	size_t	arg_size;

	j = 0;
	code_idx = 0;
	arg_size = 0;
	while (j < (size_t)instr->op.params)
	{
		if (instr->arg_type[j] == T_DIR)
		{
			arg_size = 4;
			if (instr->op.idx)
				arg_size = 2;
		}
		else if (instr->arg_type[j] == T_REG)
			arg_size = 1;
		else
			arg_size = IND_SIZE;
		instr->arg_val[j] = bin_to_num(code + code_idx, arg_size);
		code_idx += arg_size;
		j++;
	}
	return (code_idx);
}

int	res_to_return(t_instruction *instr)
{
	if (instr->op.params == 1)
		return (0);
	return (1);
}

static size_t	read_arg_types(uint8_t *code, t_instruction *instr)
{
	size_t	j;
	uint8_t	arg_code;

	j = 0;
	if (instr->op.params == 1)
		instr->arg_type[0] = T_DIR;
	else
	{
		while (j < (size_t)instr->op.params)
		{
			arg_code = code[0] << (j * 2);
			arg_code >>= 6;
			if (arg_code == DIR_CODE)
				instr->arg_type[j] = DIR_CODE;
			else if (arg_code == REG_CODE)
				instr->arg_type[j] = REG_CODE;
			else if (arg_code == IND_CODE)
				instr->arg_type[j] = IND_CODE;
			else
				error("Incorrect argument type.");
			j++;
		}
	}
	return (res_to_return(instr));
}

void	disassemble(t_bin *bin)
{
	size_t			i;
	t_instruction	*instr;

	i = 0;
	while (i < bin->prog_size)
	{
		instr = init_instruction();
		push_back(&bin->instr, instr);
		instr->op = *(g_op_tab + *(bin->code + i++) - 1);
		i += read_arg_types(bin->code + i, instr);
		i += read_arg_val(bin->code + i, instr);
	}
}
