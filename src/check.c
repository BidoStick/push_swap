/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:42:41 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/20 16:38:10 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_isdig(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
		{
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
		i++;
	}
	return (1);
}

static int	ft_isint(char *str)
{
	intmax_t nbr;

	nbr = ft_atoi(str);
	if (nbr < INT_MIN)
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
	else if (nbr > INT_MAX)
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
	return (nbr);
}

int ft_checknbr(char *str, t_box *box)
{
	int nbr;

	nbr = 0;
	ft_isdig(str);
	nbr = ft_isint(str);
	while (box)
	{
		if (box->nbr == nbr)
		{
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
		box = box->next;
	}
	return (nbr);
}

char *ft_checkcom(char *str)
{
	if (!(ft_strstr("sa sb ss pa pb ra rb rr rra rrb rrr", str)))
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
	return (str);
}
