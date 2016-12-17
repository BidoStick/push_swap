/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 18:44:31 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/17 15:35:39 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_getpile(char *str)
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
		if (pile > 0 && box->pile == pile)
			len++;
		if (box->next != NULL)
			box = box->next;
		else
			break ;
	}
	return (len);
}

void	ft_execute(t_box *box, t_com *com)
{
	t_com *tmp;
	t_box *tmp2;

	tmp = com;
	tmp2 = box;
	while (tmp)
	{
		if (ft_strstr("sasbss", tmp->com))
			ft_swap(box, ft_getpile(tmp->com));
		else if (ft_strstr("papb", tmp->com))
			ft_push(box, ft_getpile(tmp->com));
		else if (ft_strstr("rarbrr", tmp->com))
			ft_rotate(box, ft_getpile(tmp->com));
		else if (ft_strstr("rrarrbrrr", tmp->com))
			ft_rotate_rev(box, ft_getpile(tmp->com));
		if (tmp->next != NULL)
			tmp = tmp->next;
		else
			break ;
	}
}
	