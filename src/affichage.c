/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:52:13 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/09 14:52:14 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	affichage(t_box *ba, t_box *bb)
{
	ft_putstr("A :");
	while (ba)
	{
		ft_printf(" %d", ba->nbr);
		ba = ba->next;
	}
	ft_putchar('\n');
	ft_putstr("B :");
	while (bb)
	{
		ft_printf(" %d", bb->nbr);
		bb = bb->next;
	}
	ft_putstr("\n\n");
}
