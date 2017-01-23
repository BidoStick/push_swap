/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 21:16:05 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/11 21:16:06 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	direction(t_box *box, t_base *base)
{
	unsigned int	len;
	unsigned int	len_i;

	len = ft_count_nbr(box);
	len_i = 0;
	while (box->i != base->a)
	{
		len_i++;
		box = box->next;
	}
	if (len_i > len / 2)
		return (1);
	else
		return (2);
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

static void	restore_a(t_box **ba, t_box **bb, t_nbr lnb, t_base *base)
{
	check_tri_a(*ba, base);
	if (direction(*ba, base) == 1 && lastnbr(*ba) != base->a)
	{
		if (*bb && (*bb)->next
			&& destinationb(*bb, lnb, base) == 1
			&& (*bb)->i >= (lnb.big - lnb.small) / 2 + lnb.small)
			usecom(ba, bb, "rrr\n", 0);
		else
			usecom(ba, bb, "rra\n", 1);
		restore(ba, bb, lnb, base);
	}
	else if (lastnbr(*ba) != base->a)
	{
		if (*bb && (*bb)->next
			&& destinationb(*bb, lnb, base) == 2
			&& (*bb)->i >= (lnb.big - lnb.small) / 2 + lnb.small)
			usecom(ba, bb, "rr\n", 0);
		else
			usecom(ba, bb, "ra\n", 1);
		restore(ba, bb, lnb, base);
	}
}

void		restore(t_box **ba, t_box **bb, t_nbr lnb, t_base *base)
{
	pushback(ba, bb, lnb, base);
	if (lastnbr(*ba) != base->a)
		restore_a(ba, bb, lnb, base);
}
