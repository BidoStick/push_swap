/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 14:06:52 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/05 13:27:41 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	inline	void	ft_rotate_now(t_box **box)
{
	t_box *tmp;

	tmp = *box;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *box;
	tmp = *box;
	*box = (*box)->next;
	tmp->next = NULL;
}

void					ft_rotate(t_box **ba, t_box **bb, int pile)
{
	if ((pile == 1 || pile == 0) && *ba && (*ba)->next)
		ft_rotate_now(ba);
	if ((pile == 2 || pile == 0) && *bb && (*bb)->next)
		ft_rotate_now(bb);
}
