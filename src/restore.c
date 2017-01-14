/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 21:16:05 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/11 21:16:06 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	restore_a(t_box **ba, t_box **bb, t_base *base)
{
	//ft_printf("restore_a\n");
	usecom(ba, bb, "rra\n", 1);
	//affichage(*ba, *bb);
	restore(ba, bb, base);
}

static inline void	restore_b(t_box **ba, t_box **bb, t_base *base)
{
	//ft_printf("restore_b\n");
	usecom(ba, bb, "rrb\n", 2);
	//affichage(*ba, *bb);
	restore(ba, bb, base);
}

static inline void	restore_ab(t_box **ba, t_box **bb, t_base *base)
{
	//ft_printf("restore_ab\n");
	usecom(ba, bb, "rrr\n", 3);
	//affichage(*ba, *bb);
	restore(ba, bb, base);
}

void				restore(t_box **ba, t_box **bb, t_base *base)
{
	t_box *tmpa;
	t_box *tmpb;

	tmpa = *ba;
	tmpb = *bb;
	//ft_putstr("RESTORE\n");
	while (tmpa && tmpa->next)
		tmpa = tmpa->next;
	while (tmpb && tmpb->next)
		tmpb = tmpb->next;
	if (base->okbas1 == 1 && tmpa->nbr != base->basea && base->okbas2 == 1 && tmpb->nbr != base->baseb)
		restore_ab(ba, bb, base);
	else if (base->okbas1 == 1 && tmpa->nbr != base->basea)
		restore_a(ba, bb, base);
	else if (base->okbas2 == 1 && tmpb->nbr != base->baseb)
		restore_b(ba, bb, base);
	else
		return ;
}