/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 13:28:38 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/05 17:29:39 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_tri(t_box *box)
{
	t_box *tmp;
	t_box *tmptmp;
	int nbr;
	unsigned int i;

	tmptmp = box;
	nbr = box->nbr;
	while (box)
	{
		i = 0;
		tmp = tmptmp;
		while (tmp)
		{
			if (tmp->nbr < box->nbr)
				i++;
			tmp = tmp->next;
		}
		box->i = i;
		box = box->next;
	}
}

int	main(int ac, char **av)
{
	t_box	*ba;
	t_box	*bb;
	int		i = 0;

	ba = NULL;
	bb = NULL;
	if (ac > 1)
	{
		ft_getnbr(av + 1, ac - 1, &ba);
		ft_tri(ba);
		while (ft_checker(ba, ac - 1) != 1 && i < 1)
		{
			parse(&ba, &bb);
			i++;
		}
		boxdel(&ba);
		boxdel(&bb);
	}
	return (0);
}
