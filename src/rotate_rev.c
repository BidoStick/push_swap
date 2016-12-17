/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 15:27:51 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/17 15:30:20 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_rotate_rev_now(t_box *box, int len, int pile)
{
	while (box)
	{
		if (box->i == 0 && box->pile == pile)
			box->i = len - 1;
		else
			box->i--;
		if (box->next != NULL)
			box = box->next;
		else
			break ;
	}
}

void	ft_rotate_rev(t_box *box, int pile)
{
	int lena;
	int lenb;

	lena = ft_count_nbr(box, 1);
	lenb = ft_count_nbr(box, 2);
	if (pile == 0)
	{
		if (lena > 0)
			ft_rotate_rev_now(box, lena, 1);
		if (lenb > 0)
			ft_rotate_rev_now(box, lenb, 2);
	}
	else if (pile == 1 && lena > 0)
		ft_rotate_rev_now(box, lena, 1);
	else if (pile == 2 && lenb > 0)
		ft_rotate_rev_now(box, lenb, 2);
}
