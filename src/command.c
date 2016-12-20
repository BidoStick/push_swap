/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 18:44:31 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/20 16:46:56 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_getpile(char *str)
{
	int i;
	char c;

	i = 0;
	while (str[i])
	{
		if (str[i + 1] == '\0')
			c = str[i];
		i++;
	}
	if (c == 'a')
		return (1);
	else if (c == 'b')
		return (2);
	else
		return (0);
}

int		ft_count_nbr(t_box *box, int pile)
{
	int len;

	len = 0;
	while (box)
	{
		if (box->pile == pile)
			len++;
		box = box->next;
	}
	return (len);
}

void	ft_execute(t_box *box, t_com *com)
{
	t_com *tmp;

	tmp = com;
	while (tmp)
	{
		if (tmp->com == s)
			ft_swap(box, tmp->pile);
		else if (tmp->com == p)
			ft_push(box, tmp->pile);
		else if (tmp->com == r)
			ft_rotate(box, tmp->pile);
		else if (tmp->com == rr)
			ft_rotate_rev(box, tmp->pile);
		tmp = tmp->next;
	}
}
	