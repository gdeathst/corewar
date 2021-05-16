/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_instruct_and_live.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:25:35 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 12:25:37 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int	for_instruct(unsigned char *map, t_proc *proc,
								unsigned short op_index, unsigned char *codage)
{
	if (++proc->inst_cycle != g_tab[op_index].cycles)
		return (0);
	proc->inst_cycle = 0;
	if (codage != NULL && g_tab[op_index].is_codage)
	{
		*codage = map[(proc->pc + 1) % MEM_SIZE];
		if (!check_codage(*codage, proc, op_index))
			return (0);
	}
	return (1);
}

void	parse_heap_to_stack_args(unsigned int *args,
											unsigned int **heap_args,
											int count_arg)
{
	int	i;

	i = 0;
	while (i < count_arg)
	{
		args[i] = (*heap_args)[i];
		++i;
	}
	free(*heap_args);
	*heap_args = NULL;
}

void	shift_pc2(unsigned short op_index, unsigned char codage, t_proc *proc)
{
	int				i;
	int				j;
	unsigned char	tmp;

	i = 8;
	j = 0;
	while (j < g_tab[op_index].count_arg)
	{
		i -= 2;
		tmp = (unsigned char)((codage >> i) & 0x3);
		if (tmp == REG_CODE)
			proc->pc = (proc->pc + 1) % MEM_SIZE;
		else if (tmp == DIR_CODE)
		{
			if (g_tab[op_index].dir_size)
				proc->pc = (proc->pc + 2) % MEM_SIZE;
			else
				proc->pc = (proc->pc + 4) % MEM_SIZE;
		}
		else if (tmp == IND_CODE)
			proc->pc = (proc->pc + IND_SIZE) % MEM_SIZE;
		++j;
	}
}

unsigned int	*shift_pc(unsigned char codage, t_proc *proc,
							unsigned short op_index, unsigned int **args)
{
	if (args != NULL && *args != NULL)
		free(*args);
	proc->pc = (proc->pc + 1) % MEM_SIZE;
	if (g_tab[op_index].is_codage)
		proc->pc = (proc->pc + 1) % MEM_SIZE;
	else
		proc->pc = proc->pc % MEM_SIZE;
	shift_pc2(op_index, codage, proc);
	return (NULL);
}

unsigned int	take_value_from_address(unsigned char *map, t_proc *proc,
										short address)
{
	unsigned int	index;
	unsigned int	value;

	if (proc->pc == 0x0f || proc->pc == 0x0d || proc->pc == 0x0e)
	{
		if ((long)proc->pc + address < 0)
			index = (unsigned int)(MEM_SIZE + \
			((long)proc->pc + address) % MEM_SIZE);
		else
			index = (unsigned int)(((long)proc->pc + address) % MEM_SIZE);
	}
	else
	{
		if ((long)proc->pc + address % IDX_MOD < 0)
			index = (unsigned int)(MEM_SIZE + \
			((long)proc->pc + address % IDX_MOD) % MEM_SIZE);
		else
			index = (unsigned int)(((long)proc->pc + \
			address % IDX_MOD) % MEM_SIZE);
	}
	value = map[index++ % MEM_SIZE];
	value = (value << 8) | (unsigned int)map[index++ % MEM_SIZE];
	value = (value << 8) | (unsigned int)map[index++ % MEM_SIZE];
	value = (value << 8) | (unsigned int)map[index % MEM_SIZE];
	return (value);
}

void	ft_live(t_bs *bs, t_proc *proc, unsigned short op_index,
						t_chmp *champs)
{
	unsigned int	arg[g_tab[op_index].count_arg];
	unsigned int	*heap_args;
	t_chmp			*curr;

	if (for_instruct(bs->map, proc, op_index, NULL) == 0)
		return ;
	heap_args = take_argument(bs->map, DIR_CODE << 6, proc, op_index);
	if (!(heap_args))
		return ;
	parse_heap_to_stack_args(arg, &heap_args, g_tab[op_index].count_arg);
	proc->is_live = 1;
	++bs->num_live;
	curr = champs;
	while (curr)
	{
		if (curr->num * -1 == arg[0])
		{
			++curr->live;
			bs->color_map[proc->pc].live = g_count;
			curr->cycle_live = g_count;
		}
		curr = curr->next;
	}
	shift_pc(DIR_CODE << 6, proc, op_index, NULL);
}
