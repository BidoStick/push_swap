/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 21:50:55 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/16 21:50:56 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	still_in(t_box *box, t_nbr lnb, t_base *base)
{
	while (box)
	{
		if (box->i >= base->ni && (box->i < lnb.big || lnb.small == lnb.big))
			return (1);
		box = box->next;
	}
	return (0);
}

static int	destinationb(t_box *box, t_nbr lnb, t_base *base)
{
	unsigned int	len_i;
	unsigned int	len;

	len_i = 1;
	len = ft_count_nbr(box);
	while (box && (box->i < base->ni || box->i >= lnb.big))
	{
		len_i++;
		box = box->next;
	}
	if ((len_i > len / 2 && len % 2 == 0) || (len_i - 1 > len / 2))
		return (1);
	return (2);
}

static void	move_a(t_box **ba, t_box **bb, t_nbr lnb, t_base *base)
{
	while (still_in(*ba, lnb, base) == 1)
	{
		pushback(ba, bb, lnb, base);
		if (still_in(*ba, lnb, base) == 1)
		{
			if ((*ba)->i >= base->ni && ((*ba)->i < lnb.big
				|| lnb.small == lnb.big))
				usecom(ba, bb, "pb\n", 2);
			else
			{
				if (*bb && (*bb)->next
					&& destinationb(*bb, lnb, base) == 2
					&& (*bb)->i >= (lnb.big - lnb.small) / 2 + lnb.small)
					usecom(ba, bb, "rr\n", 0);
				else
					usecom(ba, bb, "ra\n", 1);
			}
		}
		pushback(ba, bb, lnb, base);
	}
}

static void	move_b(t_box **ba, t_box **bb, t_nbr lnb, t_base *base)
{
	while (still_in(*bb, lnb, base) == 1)
	{
		pushback(ba, bb, lnb, base);
		if (still_in(*bb, lnb, base) == 1)
		{
			if ((*bb)->i >= base->ni && ((*bb)->i < lnb.big
				|| lnb.small == lnb.big))
				usecom(ba, bb, "pa\n", 1);
			else
			{
				if (destinationb(*bb, lnb, base) == 1)
					usecom(ba, bb, "rrb\n", 2);
				else
					usecom(ba, bb, "rb\n", 2);
			}
		}
		pushback(ba, bb, lnb, base);
	}
}

void		move(t_box **ba, t_box **bb, t_nbr lnb, t_base *base)
{
	if (is_in(*ba, lnb.big) == 1)
	{
		move_a(ba, bb, lnb, base);
		restore(ba, bb, lnb, base);
		remove_pushback_a(ba, bb, lnb, base);
	}
	else if (is_in(*bb, lnb.big) == 1)
	{
		move_b(ba, bb, lnb, base);
		restore(ba, bb, lnb, base);
	}
}
