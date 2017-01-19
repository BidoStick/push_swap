/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 19:39:10 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/03 17:42:23 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	ft_swap_now(t_box **box)
{
	t_box	*tmp;

	tmp = *box;
	*box = (*box)->next;
	tmp->next = (*box)->next;
	(*box)->next = tmp;
}

void				ft_swap(t_box **ba, t_box **bb, int pile)
{
	if ((pile == 1 || pile == 0) && *ba && (*ba)->next)
		ft_swap_now(ba);
	if ((pile == 2 || pile == 0) && *bb && (*bb)->next)
		ft_swap_now(bb);
}
