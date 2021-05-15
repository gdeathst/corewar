/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:25:59 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 12:26:00 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_chek_proc_regs(unsigned char *map, t_proc *proc, \
	unsigned int *arg, unsigned char codage);

void	ft_ld_lld(unsigned char *map, t_proc *proc, unsigned short op_index)
{
	unsigned int	arg[g_tab[op_index].count_arg];
	unsigned int	*heap_args;
	unsigned char	codage;

	if (for_instruct(map, proc, op_index, &codage) == 0)
		return ;
	heap_args = take_argument(map, codage, proc, op_index);
	if (!heap_args)
		return ;
	parse_heap_to_stack_args(arg, &heap_args, g_tab[op_index].count_arg);
	proc->regs[arg[1]] = arg[0];
	if (arg[0] == 0)
	{
		proc->carry = (unsigned char) 1;
	}
	else
	{
		proc->carry = (unsigned char) 0;
	}
	shift_pc(codage, proc, op_index, NULL);
}

void	ft_ldi_lldi(unsigned char *map, t_proc *proc, unsigned short op_index)
{
	unsigned int	arg[g_tab[op_index].count_arg];
	unsigned int	*heap_args;
	unsigned char	codage;

	if (for_instruct(map, proc, op_index, &codage) == 0)
		return ;
	heap_args = take_argument(map, codage, proc, op_index);
	if (!heap_args)
		return ;
	parse_heap_to_stack_args(arg, &heap_args, g_tab[op_index].count_arg);
	ft_chek_proc_regs(map, proc, arg, codage);
	shift_pc(codage, proc, op_index, NULL);
}

void	ft_chek_proc_regs(unsigned char *map, t_proc *proc, \
	unsigned int *arg, unsigned char codage)
{
	if (((codage >> 6) & 0x3) == REG_CODE)
		arg[0] = proc->regs[arg[0]];
	else
		arg[0] = arg[0];
	if (((codage >> 4) & 0x3) == REG_CODE)
		arg[1] = proc->regs[arg[1]];
	else
		arg[1] = arg[1];
	proc->regs[arg[2]] = take_value_from_address(map, proc, \
	(unsigned short)(arg[0] + arg[1]));
	if (proc->regs[arg[2]] == 0)
		proc->carry = (unsigned char) 1;
	else
		proc->carry = (unsigned char) 0;
}

void	set_bytes_on_map(t_bs *bs, unsigned int i, t_proc *proc,
							unsigned int *arg)
{
	if (bs->is_v)
		add_color(i % MEM_SIZE, proc->id, bs);
	bs->map[i++ % MEM_SIZE] = (unsigned char)(arg[0] >> 24);
	if (bs->is_v)
		add_color(i % MEM_SIZE, proc->id, bs);
	bs->map[i++ % MEM_SIZE] = (unsigned char)(arg[0] >> 16);
	if (bs->is_v)
		add_color(i % MEM_SIZE, proc->id, bs);
	bs->map[i++ % MEM_SIZE] = (unsigned char)(arg[0] >> 8);
	if (bs->is_v)
		add_color(i % MEM_SIZE, proc->id, bs);
	bs->map[i % MEM_SIZE] = (unsigned char)arg[0];
}

unsigned int	ft_get_gtf(const t_proc *proc, const unsigned int *arg)
{
	unsigned int	i;

	if ((long) proc->pc + (short) arg[1] % IDX_MOD < 0)
		i = (unsigned int)(MEM_SIZE + ((long) proc->pc + (short) \
			arg[1] % IDX_MOD) % MEM_SIZE);
	 else
		i = (unsigned int)(((long) \
		proc->pc + (short)arg[1] % IDX_MOD) % MEM_SIZE);
	return (i);
}

void	ft_st(t_bs *bs, t_proc *proc, unsigned short op_index)
{
	unsigned int	arg[g_tab[op_index].count_arg];
	unsigned int	*heap_args;
	unsigned char	codage;
	unsigned int	i;

	if (for_instruct(bs->map, proc, op_index, &codage) == 0)
		return ;
	g_tab[op_index].dir_size = 1;
	if (codage == 0x70)
		codage = 0x60;
	heap_args = take_argument(bs->map, codage, proc, op_index);
	if (!heap_args)
		return ;
	parse_heap_to_stack_args(arg, &heap_args, g_tab[op_index].count_arg);
	arg[0] = proc->regs[arg[0]];
	if (codage == 0x50)
	{
		proc->regs[arg[1]] = arg[0];
		shift_pc(codage, proc, op_index, NULL);
		return ;
	}
	i = ft_get_gtf(proc, arg);
	set_bytes_on_map(bs, i, proc, arg);
	shift_pc(codage, proc, op_index, NULL);
}

void	ft_codage_reg(const t_proc *proc, unsigned int *arg, \
	unsigned char codage)
				   {
	if (((codage >> 6) & 0x3) == REG_CODE)
		arg[0] = proc->regs[arg[0]];
	else
		arg[0] = arg[0];
	if (((codage >> 4) & 0x3) == REG_CODE)
		arg[1] = proc->regs[arg[1]];
	else
		arg[1] = arg[1];
	if (((codage >> 2) & 0x3) == REG_CODE)
		arg[2] = proc->regs[arg[2]];
	else
		arg[2] = arg[2];
}

void	ft_sti(t_bs *bs, t_proc *proc, unsigned short op_index)
{
	unsigned int	arg[g_tab[op_index].count_arg];
	unsigned int	*heap_args;
	unsigned char	codage;
	unsigned int	i;

	if (for_instruct(bs->map, proc, op_index, &codage) == 0)
		return ;
	heap_args = take_argument(bs->map, codage, proc, op_index);
	if (!heap_args)
		return ;
	parse_heap_to_stack_args(arg, &heap_args, g_tab[op_index].count_arg);
	ft_codage_reg(proc, arg, codage);
	if (((long)proc->pc + (short)(arg[1] + arg[2]) % IDX_MOD) < 0)
		i = (unsigned int)(MEM_SIZE + ((long)proc->pc + (short) \
		(arg[1] + arg[2]) % IDX_MOD) % MEM_SIZE);
	else
		i = (unsigned int)(((long) proc->pc + (short) \
		(arg[1] + arg[2]) % IDX_MOD) % MEM_SIZE);
	set_bytes_on_map(bs, i, proc, arg);
	shift_pc(codage, proc, op_index, NULL);
}
