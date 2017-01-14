/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 21:20:40 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/11 21:20:41 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	range_a(t_box **ba, t_box **bb, t_nbr lnb, t_base *base)
{
	t_box *tmp;

	tmp = *ba;
	//ft_printf("range A\n");
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp->nbr != lnb.lastbig)
	{
		usecom(ba, bb, "ra\n", 1);
	//affichage(*ba, *bb);
		range_a(ba, bb, lnb, base);
	}
	base->okbas1 = 1;
	base->basea = lnb.lastbig;
}

void	range_b(t_box **ba, t_box **bb, t_nbr lnb, t_base *base)
{
	t_box *tmp;

	tmp = *bb;
	//ft_printf("range B\n");
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp->nbr != lnb.lastbig)
	{
		usecom(ba, bb, "rb\n", 2);
	//affichage(*ba, *bb);
		range_b(ba, bb, lnb, base);
	}
	base->okbas2 = 1;
	base->baseb = lnb.lastbig;
}
