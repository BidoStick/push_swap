/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 13:38:47 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/03 17:12:30 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	ft_push_now(t_box **b1, t_box **b2)
{
	t_box *tmp;

	tmp = *b1;
	*b1 = (*b1)->next;
	tmp->next = *b2;
	*b2 = tmp;
}

void				ft_push(t_box **ba, t_box **bb, int pile)
{
	if (pile == 1 && *bb != NULL)
		ft_push_now(bb, ba);
	else if (pile == 2 && *ba != NULL)
		ft_push_now(ba, bb);
}
