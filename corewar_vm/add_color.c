/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:24:52 by mevelyne          #+#    #+#             */
/*   Updated: 2021/05/09 12:24:54 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	add_color(int a, unsigned int champ, t_bs *bs)
{
	bs->color_map[a].champ = (char)champ;
	bs->color_map[a].cycle_n = g_count;
}
