/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 21:17:20 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/11 21:17:22 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sort(t_box *box, int small, int big)
{
	int len;

	len = check_nbr(box, small, big);
	while (box && box->next && len - 1)
	{
		if (box->nbr > box->next->nbr || box->nbr < small || box->nbr > big || box->next->nbr < small || box->next->nbr > big)
			return (0);
		len--;
		box = box->next;
	}
	return (1);
}

void	sort_a(t_box **ba, t_box **bb, t_nbr lnb)
{
	int counta;

	counta = check_nbr(*ba, lnb.small, lnb.lastbig);
	//ft_printf("sort_a\n");
	if (counta == 2 && (*ba)->nbr > (*ba)->next->nbr)
		usecom(ba, bb, "sa\n", 1);
	else if (counta == 3)
	{
		if ((*ba)->nbr == lnb.lastbig || ((*ba)->next->nbr == lnb.lastbig && (*ba)->next->next->nbr == lnb.small))
		{
			if ((*ba)->next->nbr == lnb.lastbig && (*ba)->next->next->nbr == lnb.small)
				usecom(ba, bb, "sa\n", 1);
			usecom(ba, bb, "pb\n", 2);
			if ((*ba)->nbr > (*ba)->next->nbr)
				usecom(ba, bb, "sa\n", 1);
			usecom(ba, bb, "ra\n", 1);
			usecom(ba, bb, "ra\n", 1);
			usecom(ba, bb, "pa\n", 1);
		}
		else if ((*ba)->nbr == lnb.small)
		{
			usecom(ba, bb, "ra\n", 1);
			if ((*ba)->nbr > (*ba)->next->nbr)
				usecom(ba, bb, "sa\n", 1);
		}
		else if ((*ba)->nbr > (*ba)->next->nbr)
			usecom(ba, bb, "sa\n", 1);
	}
}


void	sort_b(t_box **ba, t_box **bb, t_nbr lnb)
{
	int countb;

	countb = check_nbr(*bb, lnb.small, lnb.lastbig);
	//ft_printf("sort_b\n");
	if (countb == 2 && (*bb)->nbr > (*bb)->next->nbr)
		usecom(ba, bb, "sb\n", 2);
	else if (countb == 3)
	{
		if ((*bb)->nbr == lnb.lastbig || ((*bb)->next->nbr == lnb.lastbig && (*bb)->next->next->nbr == lnb.small))
		{
			if ((*bb)->next->nbr == lnb.lastbig && (*bb)->next->next->nbr == lnb.small)
				usecom(ba, bb, "sb\n", 2);
			usecom(ba, bb, "pa\n", 1);
			if ((*bb)->nbr > (*bb)->next->nbr)
				usecom(ba, bb, "sb\n", 2);
			usecom(ba, bb, "rb\n", 2);
			usecom(ba, bb, "rb\n", 2);
			usecom(ba, bb, "pb\n", 2);
		}
		else if ((*bb)->nbr == lnb.small)
		{
			usecom(ba, bb, "rb\n", 2);
			if ((*bb)->nbr > (*bb)->next->nbr)
				usecom(ba, bb, "sb\n", 2);
		}
		else if ((*bb)->nbr > (*bb)->next->nbr)
			usecom(ba, bb, "sb\n", 2);
	}
}
