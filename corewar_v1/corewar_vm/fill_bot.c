/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_bot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:25:28 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 12:25:29 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

/*
** flag == 1 for magic;
** flag == 0 for prog_size;
*/

int	check_size(char *av)
{
	char	*tmp;
	int		fd;
	int		i;

	i = 0;
	tmp = 0;
	fd = open(av, O_RDONLY);
	if (lseek(fd, CODE_POS, SEEK_SET) < 0)
	{
		ft_error(2, NULL);
	}
	while (read(fd, &tmp, 1))
		i++;
	close(fd);
	return (i);
}

void	fill_magic(unsigned int *magic_size, unsigned char *buf, char *str,
					int flag)
{
	int				i;
	unsigned char	tmp[4];

	i = -1;
	while (++i < 4)
		tmp[3 - i] = buf[i];
	*magic_size = *((unsigned int *)tmp);
	if (flag && *magic_size != COREWAR_EXEC_MAGIC)
		ft_error(3, str);
	if (!flag && *magic_size > CHAMP_MAX_SIZE)
	{
		ft_printf(RED"Error:"RC" File "BLU"%s"RC" has too large a code (%u"\
		" bytes vs %u bytes)\n", str, *magic_size, CHAMP_MAX_SIZE);
		exit(1);
	}
	if (!flag && *magic_size != (unsigned int)check_size(str))
		ft_error(4, str);
}

void	ft_magic_size(char *av, t_header *p)
{
	int				fd;
	unsigned char	buf[4];

	fd = open(av, O_RDONLY);
	if (read(fd, &buf, 4) == -1)
	{
		close(fd);
		ft_error(2, NULL);
	}
	fill_magic(&p->magic, buf, av, 1);
	close(fd);
	fd = open(av, O_RDONLY);
	if (lseek(fd, SIZE_POS, SEEK_SET) < 0)
	{
		ft_error(2, NULL);
	}
	if (read(fd, &buf, 4) == -1)
	{
		ft_error(2, NULL);
		close(fd);
	}
	fill_magic(&p->prog_size, buf, av, 0);
	close(fd);
}

/*
** flag 0 for name;
** flag 1 for comment;
*/

void	ft_name_comment(char *av, t_header *p, int flag)
{
	int	fd;
	int	k;

	fd = open(av, O_RDONLY);
	if (flag == 0)
		k = 4;
	else
		k = COMMENT_POS;
	if (lseek(fd, k, SEEK_SET) < 0)
		ft_error(2, NULL);
	if (flag == 0)
	{
		if (read(fd, &p->prog_name, PROG_NAME_LENGTH + 1 == -1))
			ft_error(2, NULL);
	}
	if (read(fd, &p->comment, COMMENT_LENGTH + 1) == -1)
		ft_error(2, NULL);
	close(fd);
}

void	ft_instraction(char *av, t_bs *bs)
{
	int		fd;
	int		k;

	k = 0;
	fd = open(av, O_RDONLY);
	if (lseek(fd, CODE_POS, SEEK_SET) < 0)
	{
		ft_error(2, NULL);
	}
	bs->list_champs->instructions = (unsigned char *)
		malloc(sizeof(unsigned char) * bs->list_champs->head.prog_size);
	if (!bs->list_champs->instructions)
	{
		close(fd);
		ft_error(5, av);
	}
	while (read(fd, &bs->list_champs->instructions[k], 1))
		++k;
	close(fd);
	if (k == 0)
		ft_error(4, av);
	bs->np++;
	if (bs->np > MAX_PLAYERS)
		ft_error(11, NULL);
}
