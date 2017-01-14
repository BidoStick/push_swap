/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 18:30:42 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/09 18:30:44 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int geti(t_box *box, t_nbr lnb)
{
	while (box->nbr != lnb.small)
		box = box->next;
	return (box->i);
}

int	getinbr(t_box *box, unsigned int i)
{
	while (box->i != i)
		box = box->next;
	return (box->nbr);
}

void		istop_small(t_box **ba, t_box **bb, int nbr, t_base *base)
{
	if ((*ba)->nbr == nbr)
	{
		usecom(ba, bb, "ra\n", 1);
		base->okbas1 = 1;
		base->basea = nbr;
	}
	else if ((*bb) && (*bb)->next && (*bb)->nbr == nbr)
	{
		usecom(ba, bb, "rb\n", 2);
		base->okbas2 = 1;
		base->baseb = nbr;
	}
}

void	separation_a(t_box **ba, t_box **bb, t_nbr lnb, t_base *base)
{
	unsigned int		check;
	unsigned int i;
	t_box	*tmp;

	i = geti(*ba, lnb);
	check = check_nbr(*ba, lnb.small, lnb.big);
	//ft_printf("separation_a\n");
	while (check > 0 && ft_checker(*ba, lnb.len) != 1)
	{
		if ((*ba)->nbr >= lnb.small && (*ba)->nbr <= lnb.big)
			check--;
		tmp = *ba;
		while (tmp->next)
			tmp = tmp->next;
		if ((*ba)->i == i && (base->okbas1 == 0 || (base->okbas1 == 1 && base->basea == tmp->nbr)))
		{
			istop_small(ba, bb, (*ba)->nbr, base);
			i++;
		}
		else if ((*ba)->nbr >= lnb.small && (*ba)->nbr <= lnb.big)
			usecom(ba, bb, "pb\n", 2);
		else
			usecom(ba, bb, "ra\n", 1);
		affichage(*ba, *bb);
	}
}

void	separation_b(t_box **ba, t_box **bb, t_nbr lnb, t_base *base)
{
	unsigned int	check;
	unsigned int i;
	t_box *tmp;


	check = check_nbr(*bb, lnb.small, lnb.big);
	i = geti(*bb, lnb);
	tmp = *bb;
	//ft_printf("separation_b\n");
	while (check > 0)
	{
		if ((*bb)->nbr >= lnb.small && (*bb)->nbr <= lnb.big)
			check--;
		tmp = *bb;
		while (tmp->next)
			tmp = tmp->next;
		if ((*bb)->i == i && (base->okbas2 == 0 || (base->okbas1 == 1 && base->baseb == tmp->nbr)))
		{
			istop_small(ba, bb, (*bb)->nbr, base);
			i++;
		}
		else if ((*bb)->nbr >= lnb.small && (*bb)->nbr <= lnb.big)
			usecom(ba, bb, "pa\n", 1);
		else
			usecom(ba, bb, "rb\n", 2);
	//	affichage(*ba, *bb);
	}
}

