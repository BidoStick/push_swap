/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:10:02 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/16 19:10:04 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pushback_a(t_box **ba, t_box **bb, t_nbr lnb, t_base *base)
{
	base->a = base->ni;
	usecom(ba, bb, "ra\n", 1);
	base->ni++;
	pushback(ba, bb, lnb, base);
}

void		pushback(t_box **ba, t_box **bb, t_nbr lnb, t_base *base)
{
	sort(ba, bb, base);
	remove_rev_pushback(ba, bb, base);
	remove_pushback_a(ba, bb, lnb, base);
	if ((*ba)->i == base->ni && lastnbr(*ba) == base->a)
		pushback_a(ba, bb, lnb, base);
	sort(ba, bb, base);
	remove_rev_pushback(ba, bb, base);
	remove_pushback_a(ba, bb, lnb, base);
}

void		remove_pushback_a(t_box **ba, t_box **bb, t_nbr lnb, t_base *base)
{
	if (*bb)
	{
		if ((*bb)->i == base->ni && lastnbr(*ba) == base->a)
		{
			usecom(ba, bb, "pa\n", 1);
			remove_pushback_a(ba, bb, lnb, base);
		}
	}
}

void		remove_rev_pushback(t_box **ba, t_box **bb, t_base *base)
{
	if (*bb && (*bb)->next && lastnbr(*ba) == base->a)
	{
		if (is_in(*bb, base->ni))
		{
			if ((*bb)->i == check_tri_b(*bb, base))
			{
				while ((*bb) && (*bb)->i != base->ni)
					usecom(ba, bb, "pa\n", 1);
			}
		}
	}
}
