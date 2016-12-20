/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 13:38:47 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/20 16:52:55 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push_now(t_box *box, int len1, int len2, int pile)
{
	while (box)
	{
		if (box->pile == pile && box->i == len2 - 1)
		{
			box->i = len1;
			if (pile == 1)
				box->pile = 2;
			else if (pile == 2)
				box->pile = 1;
			break ;
		}
		box = box->next;
	}
}

void	ft_push(t_box *box, int pile)
{
	int lena;
	int lenb;

	lena = ft_count_nbr(box, 1);
	lenb = ft_count_nbr(box, 2);
	if (pile == 1 && lenb > 0)
		ft_push_now(box, lena, lenb, 2);
	else if (pile == 2 && lena > 0)
		ft_push_now(box, lenb, lena, 1);
}
