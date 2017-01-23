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

static unsigned int	banzai(char **tab, t_box **box)
{
	unsigned int size;

	size = 0;
	tab = ft_strsplit(tab[0], ' ');
	if (tab[0] == '\0')
		exit(0);
	while (tab[size])
	{
		if (!(ft_newbox(ft_checknbr(tab[size], *box), box)))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		ft_strdel(&tab[size]);
		size++;
	}
	free(tab);
	return (size);
}

unsigned int		ft_getnbr(char **tab, unsigned int size, t_box **box)
{
	unsigned int	i;

	i = 0;
	if (size == 1)
		size = banzai(tab, box);
	else
	{
		while (i < size)
		{
			if (!(ft_newbox(ft_checknbr(tab[i], *box), box)))
			{
				ft_putstr_fd("Error\n", 2);
				exit(1);
			}
			i++;
		}
	}
	return (size);
}

void				ft_getcom(t_com **com)
{
	char	*str;

	str = NULL;
	while (get_next_line(0, &str) == 1)
	{
		ft_newcom(ft_checkcom(str), com);
		ft_strdel(&str);
	}
}

int					ft_checker(t_box *box, int len)
{
	int	nbr;
	int	lnb;

	lnb = 0;
	if (box == NULL)
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
