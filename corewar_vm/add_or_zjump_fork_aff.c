/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_or_zjump_fork_aff.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:24:56 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/15 12:39:32 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"
// unsigned char make

unsigned short	ft_regs_checks(unsigned int proc_regs)
{
	if ((unsigned short)(proc_regs == 0))
		return (1);
	else
		return (0);
}

void	ft_add_sub_and_or_xor2(unsigned char codage,
							unsigned int *arg,
							t_proc *proc,
							unsigned short op_index)
{
	if (((codage >> 6) & 0x3) == REG_CODE)
		arg[0] = proc->regs[arg[0]];
	if (((codage >> 4) & 0x3) == REG_CODE)
		arg[1] = proc->regs[arg[1]];
	if (ft_strequ(g_tab[op_index].name, "add"))
		proc->regs[arg[2]] = arg[0] + arg[1];
	else if (ft_strequ(g_tab[op_index].name, "sub"))
		proc->regs[arg[2]] = arg[0] - arg[1];
	else if (ft_strequ(g_tab[op_index].name, "and"))
		proc->regs[arg[2]] = arg[0] & arg[1];
	else if (ft_strequ(g_tab[op_index].name, "or"))
		proc->regs[arg[2]] = arg[0] | arg[1];
	else if (ft_strequ(g_tab[op_index].name, "xor"))
		proc->regs[arg[2]] = arg[0] ^ arg[1];
	proc->carry = ft_regs_checks(proc->regs[arg[2]]);
}

void	ft_add_sub_and_or_xor(unsigned char *map, t_proc *proc,
							  unsigned short op_index)
{
	unsigned int	arg[g_tab[op_index].count_arg];
	unsigned int	*heap_args;
	unsigned char	codage;

	if (for_instruct(map, proc, op_index, &codage) == 0)
		return ;
	heap_args = take_argument(map, codage, proc, op_index);
	if (!(heap_args))
		return ;
	parse_heap_to_stack_args(arg, &heap_args, g_tab[op_index].count_arg);
	ft_add_sub_and_or_xor2(codage, (unsigned int *) &arg, proc, op_index);
	shift_pc(codage, proc, op_index, NULL);
	shift_pc(codage, proc, op_index, NULL);
}

void	ft_zjump(unsigned char *map, t_proc *proc, unsigned short op_index)
{
	unsigned int	arg[g_tab[op_index].count_arg];
	unsigned int	*heap_args;

	if (for_instruct(map, proc, op_index, NULL) == 0)
		return ;
	heap_args = take_argument(map, DIR_CODE << 6, proc, op_index);
	if (!(heap_args))
		return ;
	parse_heap_to_stack_args(arg, &heap_args, g_tab[op_index].count_arg);
	if (proc->carry == 1)
	{
		if ((long)proc->pc + (short)arg[0] % IDX_MOD < 0)
			proc->pc = (unsigned int)(MEM_SIZE + ((long)proc->pc + \
			(short)arg[0] % IDX_MOD) % MEM_SIZE);
		else
			proc->pc = (unsigned int)(((long)proc->pc + \
			(short)arg[0] % IDX_MOD) % MEM_SIZE);
	}
	else
		shift_pc(DIR_CODE << 6, proc, op_index, NULL);
}

t_proc	*ft_fork_new_proc(t_proc *tmp, unsigned int *arg, t_proc **procs)
{
	t_proc			*new_proc;
	int				i;

	new_proc = (t_proc *)malloc(sizeof(t_proc));
	if (!(new_proc))
		ft_error(5, NULL);
	if ((long)tmp->pc + (short)arg[0] % IDX_MOD < 0)
		new_proc->pc = (unsigned int)(MEM_SIZE + \
		((long)tmp->pc + (short)arg[0] % IDX_MOD) % MEM_SIZE);
	else
		new_proc->pc = (unsigned int)(((long)tmp->pc + \
		(short)arg[0] % IDX_MOD) % MEM_SIZE);
	i = -1;
	while (++i < REG_NUMBER)
		new_proc->regs[i] = tmp->regs[i];
	new_proc->carry = tmp->carry;
	new_proc->id = tmp->id;
	new_proc->inst_cycle = tmp->inst_cycle;
	new_proc->is_live = tmp->is_live;
	new_proc->next = *procs;
	return (new_proc);
}

void	ft_fork(unsigned char *map, t_proc **procs, t_proc *tmp,
				unsigned short op_index)
{
	unsigned int	arg[g_tab[op_index].count_arg];
	unsigned int	*heap_args;

	if (for_instruct(map, tmp, op_index, NULL) == 0)
		return ;
	heap_args = take_argument(map, DIR_CODE << 6, tmp, op_index);
	if (!(heap_args))
		return ;
	parse_heap_to_stack_args(arg, &heap_args, g_tab[op_index].count_arg);
	*procs = ft_fork_new_proc(tmp, (unsigned int *) &arg, procs);
	shift_pc(DIR_CODE << 6, tmp, op_index, NULL);
}

t_proc	*ft_lfork_new_proc(t_proc *tmp, unsigned int *arg, t_proc **procs)
{
	t_proc			*new_proc;
	int				i;

	new_proc = (t_proc *)malloc(sizeof(t_proc));
	if (!(new_proc))
		ft_error(5, NULL);
	if ((long)tmp->pc + (short)arg[0] < 0)
		new_proc->pc = (unsigned int)(MEM_SIZE +\
		((long)tmp->pc + (short)arg[0]) % MEM_SIZE);
	else
		new_proc->pc = (unsigned int)(((long)tmp->pc + (short)arg[0]) % MEM_SIZE);
	i = -1;
	while (++i < REG_NUMBER)
		new_proc->regs[i] = tmp->regs[i];
	new_proc->carry = tmp->carry;
	new_proc->id = tmp->id;
	new_proc->inst_cycle = tmp->inst_cycle;
	new_proc->is_live = tmp->is_live;
	new_proc->next = *procs;
	return (new_proc);
}

void	ft_lfork(unsigned char *map, t_proc **procs, t_proc *tmp,
					unsigned short op_index)
{
	unsigned int	arg[g_tab[op_index].count_arg];
	unsigned int	*heap_args;

	if (for_instruct(map, tmp, op_index, NULL) == 0)
		return ;
	heap_args = take_argument(map, DIR_CODE << 6, tmp, op_index);
	if (!(heap_args))
		return ;
	parse_heap_to_stack_args(arg, &heap_args, g_tab[op_index].count_arg);
	*procs = ft_lfork_new_proc(tmp, (unsigned int *) &arg, procs);
	shift_pc(DIR_CODE << 6, tmp, op_index, NULL);
}

void	ft_aff(unsigned char *map, t_proc *proc, unsigned short op_index,
				unsigned short is_aff)
{
	unsigned int	arg[g_tab[op_index].count_arg];
	unsigned int	*heap_args;
	unsigned char	codage;

	if (for_instruct(map, proc, op_index, &codage) == 0)
		return ;
	heap_args = take_argument(map, codage, proc, op_index);
	if (!(heap_args))
		return ;
	parse_heap_to_stack_args(arg, &heap_args, g_tab[op_index].count_arg);
	if (is_aff == 1)
		ft_printf("aff is "YEL"%u"RC, arg[0]);
	shift_pc(codage, proc, op_index, NULL);
}
