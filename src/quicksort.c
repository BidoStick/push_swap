/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:00:42 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/09 13:00:44 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_nbr(t_box *box, int small, int big)
{
	int i;

	i = 0;
	while (box)
	{
		if (box->nbr >= small && box->nbr <= big)
			i++;
		box = box->next;
	}
	return (i);
}

int check_tri(t_box *box, int small, int big)
{
	int len;
	int i;

	len = check_nbr(box, small, big);
	i = 1;
	while (box && i < len)
	{
		if (box->nbr > box->next->nbr)
			return (0);
		box = box->next;
	}
	return (1);
}

void	merge(t_box **ba, t_box **bb, t_nbr lnb)
{
	//ft_printf("merge\n");
	if (*bb)
	{
		if ((*bb)->nbr < (*ba)->nbr)
			usecom(ba, bb, "pa\n", 1);
		else
			usecom(ba, bb, "ra\n", 1);
		merge(ba, bb, lnb);
	}
	else if ((*ba)->nbr != lnb.small)
	{
		while ((*ba)->nbr != lnb.small)
			usecom(ba, bb, "ra\n", 1);
	}
}

int		getsmall(t_box *box, t_nbr lnb)
{
	int nb;

	nb = lnb.big;
	while (box)
	{
		if (nb > box->nbr && box->nbr >= lnb.small && box->nbr <= lnb.big)
			nb = box->nbr;
		box = box->next;
	}
	return (nb);
}

void	separe(t_box **ba, t_box **bb, t_nbr lnb, t_base *base)
{
	int ina;
	int inb;

	affichage(*ba, *bb);
	if (ft_checker(*ba, lnb.len) != 1)
	{
		ina = check_nbr(*ba, lnb.small, lnb.lastbig);
		if (*bb)
			inb = check_nbr(*bb, lnb.small, lnb.lastbig);
		if ((ina > 3 && (is_sort(*ba, lnb.small, lnb.lastbig) == 0))
			|| (inb > 3 && (*bb) && (is_sort(*bb, lnb.small, lnb.lastbig) == 0)))
		{
			separe1(ba, bb, lnb, base);
			restore(ba, bb, base);
			separe2(ba, bb, lnb, base);
			restore(ba, bb, base);
		}
		else
		{
			if (ina > 0)
			{
				if (is_sort(*ba, lnb.small, lnb.lastbig) == 0)
					sort_a(ba, bb, lnb);
				range_a(ba, bb, lnb, base);
			}
			else
			{
				if (is_sort(*bb, lnb.small, lnb.lastbig) == 0)
					sort_b(ba, bb, lnb);
				range_b(ba, bb, lnb, base);
			}
		}
	}
}

void	separe1(t_box **ba, t_box **bb, t_nbr lnb, t_base *base)
{
	int in;

	//affichage(*ba, *bb);
	in = check_nbr(*ba, lnb.small, lnb.big);
	if (in > 0)
	{
		separation_a(ba, bb, lnb, base);
		if (ft_checker(*ba, lnb.len) == 1 || (base->okbas1 == 1 && lnb.big == base->basea))
			return ;
		lnb.small = getsmall(*bb, lnb);
		lnb.lastbig = lnb.big;
  	 	lnb.big = search_npivot(*bb, lnb.small, lnb.big);
	}
	else
	{
		separation_b(ba, bb, lnb, base);
		if (base->okbas2 == 1 && lnb.big == base->baseb)
			return ;
		lnb.small = getsmall(*ba, lnb);
		lnb.lastbig = lnb.big;
		lnb.big = search_npivot(*ba, lnb.small, lnb.big);
	}
	if (ft_checker(*ba, lnb.len) != 1)
	{
		restore(ba, bb, base);
		separe(ba, bb, lnb, base);
	}
}

void	separe2(t_box **ba, t_box **bb, t_nbr lnb, t_base *base)
{
	int ina;
	int inb;
	int nsmalla;
	int nsmallb;

	//affichage(*ba, *bb);
	nsmalla = search_nsmall(*ba, lnb.big, lnb.lastbig);
	ina = check_nbr(*ba, nsmalla, lnb.lastbig);
	if (ft_checker(*ba, lnb.len) == 1)
		return ;
	if (*bb)
	{
		nsmallb = search_nsmall(*bb, lnb.big, lnb.lastbig);
		inb = check_nbr(*bb, nsmallb, lnb.lastbig);
	}
	if (ina > 0)
	{
		lnb.small = nsmalla;
		lnb.big = search_npivot(*ba, lnb.small, lnb.lastbig);
	}
	else
	{
		lnb.small = nsmallb;
		lnb.big = search_npivot(*bb, lnb.small, lnb.lastbig);
	}
	separe(ba, bb, lnb, base);
}

void	parse(t_box **ba, t_box **bb)
{
	t_box *tmp;
	t_nbr lnb;
	t_base base;

	tmp = *ba;
	lnb.small = (*ba)->nbr;
	lnb.lastbig = (*ba)->nbr;
	while (tmp)
	{
		if (tmp->nbr < lnb.small)
			lnb.small = tmp->nbr;
		if (tmp->nbr > lnb.lastbig)
			lnb.lastbig = tmp->nbr;
		tmp = tmp->next;
	}
	lnb.big = search_npivot(*ba, lnb.small, lnb.lastbig);
	lnb.first = 0;
	base.okbas1 = 0;
	base.okbas2 = 0;
	lnb.len = check_nbr(*ba, lnb.small, lnb.lastbig);
	separe(ba, bb, lnb, &base);
	merge(ba, bb, lnb);
	affichage(*ba, *bb);
}