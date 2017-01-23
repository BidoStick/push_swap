/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:34:13 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/23 14:34:14 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	norme(t_box *ba, t_box *bb, unsigned int lena, unsigned int lenb)
{
	while (lena > 0 || lenb > 0)
	{
		if (lena >= lenb && lena > 0)
		{
			ft_printf("%10d", ba->nbr);
			ba = ba->next;
			lena--;
		}
		if (lenb >= lena && lenb > 0)
		{
			ft_printf("%16d", bb->nbr);
			bb = bb->next;
			lenb--;
		}
		ft_putchar('\n');
	}
}

void		cmd(t_com *com)
{
	if (com->com == s && com->pile == 0)
		ft_putstr("ss :\n");
	else if (com->com == s && com->pile == 1)
		ft_putstr("sa :\n");
	else if (com->com == s && com->pile == 2)
		ft_putstr("sb :\n");
	else if (com->com == p && com->pile == 1)
		ft_putstr("pa :\n");
	else if (com->com == p && com->pile == 2)
		ft_putstr("pb :\n");
	else if (com->com == r && com->pile == 0)
		ft_putstr("rr :\n");
	else if (com->com == r && com->pile == 1)
		ft_putstr("ra :\n");
	else if (com->com == r && com->pile == 2)
		ft_putstr("rb :\n");
	else if (com->com == rr && com->pile == 0)
		ft_putstr("rrr :\n");
	else if (com->com == rr && com->pile == 1)
		ft_putstr("rra :\n");
	else if (com->com == rr && com->pile == 2)
		ft_putstr("rrb :\n");
}

void		affichv(t_box *ba, t_box *bb, t_com *com)
{
	unsigned int	lena;
	unsigned int	lenb;

	lena = ft_count_nbr(ba);
	lenb = ft_count_nbr(bb);
	cmd(com);
	while (lena > lenb && lena > 0)
	{
		ft_printf("%10d", ba->nbr);
		ft_putchar('\n');
		ba = ba->next;
		lena--;
	}
	while (lenb > lena && lenb > 0)
	{
		ft_printf("%22d", bb->nbr);
		ft_putchar('\n');
		bb = bb->next;
		lenb--;
	}
	norme(ba, bb, lena, lenb);
	ft_printf("  _______________ _______________\n");
	ft_printf("         A               B\n\n");
	sleep(1);
}
