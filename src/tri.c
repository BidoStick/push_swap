/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:45:56 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/17 19:46:18 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			check_tri_a(t_box *ba, t_base *base)
{
	while (ba && ba->i != base->a)
		ba = ba->next;
	if (ba->next)
		ba = ba->next;
	while (ba)
	{
		if (ba->i == base->ni)
		{
			base->a = ba->i;
			base->ni++;
		}
		else
			break ;
		ba = ba->next;
	}
}

unsigned int	check_tri_b(t_box *bb, t_base *base)
{
	unsigned int	i;
	t_box			*tmp;

	i = base->ni;
	if (bb && bb->next)
	{
		tmp = bb;
		while (tmp && tmp->next->i != i)
		{
			if (bb->i == i)
				break ;
			if (tmp->i == i + 1 && tmp->next->i == i)
			{
				tmp = bb;
				i = tmp->i;
			}
			tmp = tmp->next;
		}
		if (bb->next->i == i && bb->i == i + 1)
			i = bb->i;
	}
	return (i);
}
