/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 15:27:51 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/03 17:32:17 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	ft_rotate_rev_now(t_box **box)
{
	t_box *tmp;
	t_box *tmp2;

	tmp = *box;
	tmp2 = *box;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	tmp->next = *box;
	*box = tmp;
	tmp2->next = NULL;
}

void				ft_rotate_rev(t_box **ba, t_box **bb, int pile)
{
	if ((pile == 1 || pile == 0) && *ba && (*ba)->next)
		ft_rotate_rev_now(ba);
	else if ((pile == 2 || pile == 0) && *bb && (*bb)->next)
		ft_rotate_rev_now(bb);
}
