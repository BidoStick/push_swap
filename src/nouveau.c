/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nouveau.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 16:04:44 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/15 16:04:45 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	lastnbr(t_box *box)
{
	while (box->next)
		box = box->next;
	return (box->i);
}

int				is_in(t_box *box, unsigned int i)
{
	while (box)
	{
		if (box->i == i)
			return (1);
		box = box->next;
	}
	return (0);
}

static void		quicksort(t_box **ba, t_box **bb, t_nbr lnb, t_base *base)
{
	t_nbr	nlnb;

	nlnb = lnb;
	if (ft_checker(*ba, lnb.len) != 1)
	{
		check_tri_a(*ba, base);
		pushback(ba, bb, lnb, base);
		move(ba, bb, lnb, base);
		if ((lnb.lastbig - lnb.small) / 4 != 0)
		{
			nlnb.lastbig = lnb.big;
			nlnb.big = (lnb.big - lnb.small) / 2 + lnb.small;
			quicksort(ba, bb, nlnb, base);
			pushback(ba, bb, lnb, base);
			nlnb = lnb;
			nlnb.small = lnb.big;
			nlnb.big = lnb.big + (lnb.lastbig - lnb.big) / 2 + 1;
			nlnb.lastbig = lnb.lastbig;
			quicksort(ba, bb, nlnb, base);
			pushback(ba, bb, lnb, base);
		}
	}
}

void			start(t_box **ba, t_box **bb)
{
	t_nbr	lnb;
	t_base	base;
	t_box	*tmp;

	tmp = *ba;
	lnb.len = ft_count_nbr(*ba);
	lnb.small = 0;
	lnb.lastbig = lnb.len - 1;
	lnb.big = lnb.len / 2;
	base.a = 0;
	base.ni = 1;
	quicksort(ba, bb, lnb, &base);
}
