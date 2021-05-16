/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:25:00 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 12:25:01 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int		ft_check_fd(char *av);
void	ft_gt_sdf(t_chmp **pChmp, unsigned int num, t_chmp *pChmp1);

void	add_new_process(t_proc **proc)
{
	t_proc	*tmp_proc;
	int		i;

	tmp_proc = (t_proc *)malloc(sizeof(t_proc));
	if (!tmp_proc)
		ft_error(5, NULL);
	tmp_proc->carry = 0;
	tmp_proc->is_live = 0;
	tmp_proc->inst_cycle = 0;
	i = -1;
	while (++i < REG_NUMBER)
		tmp_proc->regs[i] = 0;
	tmp_proc->next = *proc;
	*proc = tmp_proc;
}

void	ft_flag_t_check(t_chmp *const *first, unsigned int flag_num, \
	t_chmp *curr)
{
	if (flag_num != 0)
	{
		curr = *first;
		while (curr)
		{
			if (curr->flag_num == flag_num)
				ft_error(12, NULL);
			else
				curr = curr->next;
		}
	}
}

void	a_n_c(t_chmp **first, unsigned int flag_num, t_proc **proc,
			  char *av)
{
	t_chmp	*tmp_cmp;
	t_chmp	*curr;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		ft_error(2, NULL);
	}
	tmp_cmp = (t_chmp *)malloc(sizeof(t_chmp));
	if (!tmp_cmp)
		ft_error(5, NULL);
	tmp_cmp->live = 0;
	tmp_cmp->cycle_live = 0;
	tmp_cmp->flag_num = flag_num;
	ft_flag_t_check(first, flag_num, curr);
	tmp_cmp->next = *first;
	*first = tmp_cmp;
	add_new_process(proc);
	close(fd);
}

void	print_champs(t_chmp *champs, unsigned short is_visual)
{
	t_chmp			*tmp;

	tmp = champs;
	if (is_visual == 0)
		ft_printf(YEL"Introducing contestants...\n"RC);
	while (tmp)
	{
		if (is_visual == 0)
		{
			ft_printf("* Player %u, weighing %u bytes, \"%s\" (\"%s\")\n", \
			 tmp->num, tmp->head.prog_size, tmp->head.prog_name, \
			 tmp->head.comment);
		}
		tmp = tmp->next;
	}
}