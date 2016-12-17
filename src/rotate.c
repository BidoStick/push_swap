/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 14:06:52 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/17 15:18:48 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_rotate_now(t_box *box, int len, int pile)
{
	while (box)
	{
		if (box->i == len - 1 && box->pile == pile)
			box->i = 0;
		else
			box->i++;
		if (box->next != NULL)
			box = box->next;
		else
			break ;
	}
}

void	ft_rotate(t_box *box, int pile)
{
	int lena;
	int lenb;

	lena = ft_count_nbr(box, 1);
	lenb = ft_count_nbr(box, 2);
	if (pile == 0)
	{
		if (lena > 0)
			ft_rotate_now(box, lena, 1);
		if (lenb > 0)
			ft_rotate_now(box, lenb, 2);
	}
	else if (pile == 1 && lena > 0)
		ft_rotate_now(box, lena, 1);
	else if (pile == 2 && lenb > 0)
		ft_rotate_now(box, lenb, 2);
}
