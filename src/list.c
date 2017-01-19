/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 17:28:47 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/03 13:40:02 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_box	*ft_newbox(int nbr, t_box **box)
{
	t_box	*newbox;
	t_box	*tmp;

	tmp = *box;
	if (!(newbox = (t_box*)malloc(sizeof(t_box))))
		return (NULL);
	newbox->nbr = nbr;
	newbox->next = NULL;
	if (*box == NULL)
		*box = newbox;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = newbox;
	}
	return (newbox);
}

t_com	*ft_newcom(char *command, t_com **com)
{
	t_com *newcom;
	t_com *tmp;

	tmp = *com;
	if (!(newcom = (t_com*)malloc(sizeof(t_com))))
		return (NULL);
	if (ft_strstr("sa sb ss", command))
		newcom->com = s;
	else if (ft_strstr("pa pb", command))
		newcom->com = p;
	else if (ft_strstr("ra rb rr", command))
		newcom->com = r;
	else if (ft_strstr("rra rrb rrr", command))
		newcom->com = rr;
	newcom->pile = ft_getpile(command);
	newcom->next = NULL;
	if (*com == NULL)
		*com = newcom;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = newcom;
	}
	return (newcom);
}

void	boxdel(t_box **box)
{
	if (*box)
	{
		boxdel(&(*box)->next);
		free(*box);
		*box = NULL;
	}
}

void	comdel(t_com **com)
{
	if (*com)
	{
		comdel(&(*com)->next);
		free(*com);
		*com = NULL;
	}
}
