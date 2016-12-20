/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 19:39:10 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/20 16:15:05 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_swap_now(t_box *box, int len, int pile)
{
	t_box *tmp;

	tmp = box;
	while (box)
	{
		if (box->pile == pile && box->i == len - 2)
			break ;
		box = box->next;
	}
	while (tmp)
	{
		if (tmp->pile == pile && tmp->i == len - 1)
			break ;
		tmp = tmp->next;
	}
	box->i = len - 1;
	tmp->i = len - 2;
}

void	ft_swap(t_box *box, int pile)
{
	int len;

	len = 0;
	if (pile == 0)
	{
		if ((len = ft_count_nbr(box, 1)) > 1)
			ft_swap_now(box, len, 1);
		if ((len = ft_count_nbr(box, 2)) > 1)
			ft_swap_now(box, len, 2);
	}
	else
	{
		if ((len = ft_count_nbr(box, pile)) > 1)
			ft_swap_now(box, len, pile);
	}
}
