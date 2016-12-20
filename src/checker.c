/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:08:06 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/20 17:16:23 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	ft_getnbr(char **tab, int size, t_box **box)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (!(ft_newbox(ft_checknbr(tab[i], *box), size - 1 - i, box)))
		{
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
		i++;
	}
}

static inline void	ft_getcom(t_com **com)
{
	char *str;

	str = NULL;
	while (get_next_line(0, &str) == 1)
		ft_newcom(ft_checkcom(str), com);
}

static inline int	ft_checker(t_box *box, int len)
{
	int i;
	int comp;
	t_box *tmp;
	int rs;

	comp = 0;
	rs = 0;
	if (ft_count_nbr(box, 1) == 0)
		return (0);
	if ((rs = ft_count_nbr(box, 1)) != len)
		return (0);
	tmp = box;
	while (tmp)
	{
		if (tmp->i == 0)
		{
			comp = tmp->nbr;
			break ;
		}
		tmp = tmp->next;
	}
	tmp = box;
	i = 1;
	while (i < len && tmp)
	{
		if (tmp->i == i)
		{
			if (comp > tmp->nbr)
			{
				i++;
				comp = tmp->nbr;
				tmp = box;
			}
			else
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_box *box;
	t_com *com;

	box = NULL;
	if (ac > 1)
	{
		ft_getnbr(av + 1, ac - 1, &box);
		ft_getcom(&com);
		ft_execute(box, com);
		if (ft_checker(box, ac - 1) == 1)
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
		boxdel(&box);
		comdel(&com);
	}
	return (0);
}
