/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 17:28:47 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/17 14:42:44 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_box	*ft_newbox(int nbr, int i, t_box **box)
{
	t_box *newbox;

	if (!(newbox = (t_box*)malloc(sizeof(t_box))))
		return (NULL);
	newbox->nbr = nbr;
	newbox->i = i;
	newbox->pile = 1;
	newbox->next = NULL;
	if (*box == NULL)
		*box = newbox;
	else
	{
		newbox->next = *box;
		*box = newbox;
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
	if (!(newcom->com = ft_strnew(sizeof(char) * ft_strlen(command))))
		return (NULL);
	ft_memcpy(newcom->com, command, ft_strlen(command));
	newcom->next = NULL;
	if (*com == NULL)
		*com = newcom;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = newcom;
	}
	return (newcom);
}
