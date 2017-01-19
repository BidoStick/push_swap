/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 15:04:37 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/03 17:15:35 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	ft_getnbr(char **tab, unsigned int size, t_box **box)
{
	unsigned int	i;

	i = 0;
	if (size == 1)
	{
		tab = ft_strsplit(tab[0], ' ');
		size = 0;
		while (tab[size])
			size++;
	}
	while (i < size)
	{
		if (!(ft_newbox(ft_checknbr(tab[i], *box), box)))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
	return (size);
}

void			ft_getcom(t_com **com)
{
	char	*str;

	str = NULL;
	while (get_next_line(0, &str) == 1)
		ft_newcom(ft_checkcom(str), com);
}

int				ft_checker(t_box *box, int len)
{
	int	nbr;
	int	lnb;

	lnb = 0;
	if (box == NULL || box->next == NULL)
		return (0);
	nbr = box->nbr;
	lnb++;
	box = box->next;
	while (box)
	{
		if (nbr > box->nbr)
			return (0);
		lnb++;
		nbr = box->nbr;
		box = box->next;
	}
	if (lnb != len)
		return (0);
	return (1);
}
