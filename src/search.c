/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:39:54 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/10 15:39:55 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		search_npivot(t_box *box, int small, int big)
{
	t_box	*tmp;
	t_box	*tmptmp;
	int		nb1;
	int		nb2;

	tmptmp = box;
	while (box)
	{
		tmp = tmptmp;
		nb1 = 0;
		nb2 = 0;
		if (box->nbr >= small && box->nbr <= big)
		{
			while (tmp && box->nbr >= small && box->nbr <= big)
			{
				if (tmp->nbr >= small && tmp->nbr <= big)
				{
					nb1 = (tmp->nbr < box->nbr ? nb1 + 1 : nb1);
					nb2 = (tmp->nbr > box->nbr ? nb2 + 1 : nb2);
				}
				tmp = tmp->next;
			}
			if ((check_nbr(tmptmp, small, big) % 2 == 1 && nb1 == nb2) ||
				(check_nbr(tmptmp, small, big) % 2 == 0 && nb1 + 1 == nb2))
				return (box->nbr);
		}
		box = box->next;
	}
	return (-5633);
}

int		search_nsmall(t_box *box, int small, int big)
{
	int nb;

	nb = big;
	while (box)
	{
		if (box->nbr > small && box->nbr <= big && box->nbr < nb)
			nb = box->nbr;
		box = box->next;
	}
	return (nb);
}


int		search_nbr(t_box *box, int nb)
{
	while (box)
	{
		if (box->nbr == nb)
			return (1);
		box = box->next;
	}
	return (0);
}
