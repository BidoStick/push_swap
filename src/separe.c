/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:23:15 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/08 12:23:16 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	separe(unsigned int i, unsigned int len, t_box **ba, t_box **bb, unsigned int max)
{
	char *str;
	t_box *tmp;

	while(max < len)
	{
		if (i <= len)
		{
			str = "pb\n";
			ft_push(ba, bb, 2);
			tmp = *ba;
			while (tmp && tmp->next)
				tmp = tmp->next;
			i = tmp->i;
			max++;
		}
		else
		{
			str = "ra\n";
			ft_rotate(ba, bb, 1);
			tmp = *ba;
			while (tmp && tmp->next)
				tmp = tmp->next;
			i = tmp->i;
		}
		status(*ba, *bb);
		ft_putstr(str);
	}
}

