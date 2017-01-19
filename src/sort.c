/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 21:17:20 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/11 21:17:22 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_box **ba, t_box **bb, t_base *base)
{
	if ((*ba)->i == (*ba)->next->i + 1 && *bb
		&& (*bb)->next && (*bb)->i + 1 == (*bb)->next->i)
		usecom(ba, bb, "ss\n", 0);
	else if ((*ba)->next->i == base->ni
		&& lastnbr(*ba) == base->a && *bb && (*bb)->next
		&& (*bb)->i + 1 == (*bb)->next->i)
		usecom(ba, bb, "ss\n", 0);
	else if (*bb && (*bb)->next && (*ba)->next->i == base->ni
		&& (*ba)->i == base->ni + 2 && (*bb)->i == base->ni + 1
		&& (*bb)->i + 1 == (*bb)->next->i)
		usecom(ba, bb, "ss\n", 0);
	else if ((*ba)->i == (*ba)->next->i + 1)
		usecom(ba, bb, "sa\n", 1);
	else if ((*ba)->next->i == base->ni && lastnbr(*ba) == base->a)
		usecom(ba, bb, "sa\n", 1);
	else if ((*bb) && (*ba)->next->i == base->ni
		&& (*ba)->i == base->ni + 2 && (*bb)->i == base->ni + 1)
		usecom(ba, bb, "sa\n", 1);
}
