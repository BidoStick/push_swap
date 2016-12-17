/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 19:39:10 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/17 14:51:44 by jgoncalv         ###   ########.fr       */
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
		if (box->next)
			box = box->next;
		else
			break ;
	}
	while (tmp)
	{
		if (tmp->pile == pile && tmp->i == len - 1)
			break ;
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
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
		if ((len = ft_count_nbr(box, 1)) > 2)
			ft_swap_now(box, len, 1);
		if ((len = ft_count_nbr(box, 2)) > 2)
			ft_swap_now(box, len, 2);
	}
	else
	{
		if ((len = ft_count_nbr(box, pile)) > 2)
			ft_swap_now(box, len, pile);
	}
}
