/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:25:47 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/08 12:25:48 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *parse(t_box **ba, t_box **bb)
{
	unsigned int len;
	t_box *tmp;
	unsigned int i;

	tmp = *ba;
	i = 0;
	len = ft_count_nbr(*ba);
	while (tmp->next)
		tmp = tmp->next;
	while (len / 2 )
	{
		separe(tmp->i, len / 2, ba, bb, 0);
	}
	return ("coucou\n");
}
