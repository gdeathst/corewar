/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:25:04 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 12:25:06 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int		check_num_atoi(char *line, unsigned int *num)
{
	int		count;

	*num = 0;
	while (*line == '0')
		line++;
	count = 0;
	while (count <= 10 && line[count])
		count++;
	if (count > 10)
		return (0);
	if (count == 10 && ft_strncmp(line, "4294967295", 10) > 0)
		return (0);
	while (count > 0)
	{
		*num = (*num * 10) + (*line - '0');
		count--;
		line++;
	}
	return (1);
}
