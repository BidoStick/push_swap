/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 16:32:25 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/21 16:32:26 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	unsigned int	premier(t_box **ba,
	t_com *com, unsigned int lena, int *i)
{
	if (com->com == p && com->pile == 1 && *i > 0)
	{
		ft_printf("\033[35m%10d\033[00m", (*ba)->nbr);
		*i = 0;
	}
	else if (com->com == s && (com->pile == 1 || com->pile == 0) && *i > 0)
	{
		ft_printf("\033[31m%10d\033[00m", (*ba)->nbr);
		(*i)--;
	}
	else if (com->com == r && (com->pile == 1 || com->pile == 0))
		ft_printf("\033[34m%10d\033[00m", (*ba)->nbr);
	else if (com->com == rr && (com->pile == 1 || com->pile == 0))
		ft_printf("\033[33m%10d\033[00m", (*ba)->nbr);
	else
		ft_printf("%10d", (*ba)->nbr);
	ft_putchar('\n');
	(*ba) = (*ba)->next;
	lena--;
	return (lena);
}

static	unsigned int	deuxieme(t_box **bb,
	t_com *com, unsigned int lenb, int *j)
{
	if (com->com == p && com->pile == 2 && *j > 0)
	{
		ft_printf("\033[32m%26d\033[00m", (*bb)->nbr);
		*j = 0;
	}
	else if (com->com == s && (com->pile == 2 || com->pile == 0) && *j > 0)
	{
		ft_printf("\033[31m%26d\033[00m", (*bb)->nbr);
		(*j)--;
	}
	else if (com->com == r && (com->pile == 2 || com->pile == 0))
		ft_printf("\033[34m%26d\033[00m", (*bb)->nbr);
	else if (com->com == rr && (com->pile == 2 || com->pile == 0))
		ft_printf("\033[33m%16d\033[00m", (*bb)->nbr);
	else
		ft_printf("%26d", (*bb)->nbr);
	ft_putchar('\n');
	(*bb) = (*bb)->next;
	lenb--;
	return (lenb);
}

static	unsigned int	troisieme(t_box **ba,
	t_com *com, unsigned int lena, int *i)
{
	if (com->com == p && com->pile == 1 && *i > 0)
	{
		ft_printf("\033[35m%10d\033[00m", (*ba)->nbr);
		*i = 0;
	}
	else if (com->com == s && (com->pile == 1 || com->pile == 0) && *i > 0)
	{
		ft_printf("\033[31m%10d\033[00m", (*ba)->nbr);
		(*i)--;
	}
	else if (com->com == r && (com->pile == 1 || com->pile == 0))
		ft_printf("\033[34m%10d\033[00m", (*ba)->nbr);
	else if (com->com == rr && (com->pile == 1 || com->pile == 0))
		ft_printf("\033[33m%10d\033[00m", (*ba)->nbr);
	else
		ft_printf("%10d", (*ba)->nbr);
	(*ba) = (*ba)->next;
	lena--;
	return (lena);
}

static	unsigned int	quatrieme(t_box **bb,
	t_com *com, unsigned int lenb, int *j)
{
	if (com->com == p && com->pile == 2 && *j > 0)
	{
		ft_printf("\033[32m%16d\033[00m", (*bb)->nbr);
		*j = 0;
	}
	else if (com->com == s && (com->pile == 2 || com->pile == 0) && *j > 0)
	{
		ft_printf("\033[31m%16d\033[00m", (*bb)->nbr);
		(*j)--;
	}
	else if (com->com == r && (com->pile == 2 || com->pile == 0))
		ft_printf("\033[34m%16d\033[00m", (*bb)->nbr);
	else if (com->com == rr && (com->pile == 2 || com->pile == 0))
		ft_printf("\033[33m%16d\033[00m", (*bb)->nbr);
	else
		ft_printf("%16d", (*bb)->nbr);
	(*bb) = (*bb)->next;
	lenb--;
	return (lenb);
}

void					affichage(t_box *ba, t_box *bb, t_com *com)
{
	unsigned int	lena;
	unsigned int	lenb;
	int				i;
	int				j;

	i = 2;
	j = 2;
	cmd(com);
	lena = ft_count_nbr(ba);
	lenb = ft_count_nbr(bb);
	while (lena > lenb && lena > 0)
		lena = premier(&ba, com, lena, &i);
	while (lenb > lena && lenb > 0)
		lenb = deuxieme(&bb, com, lenb, &j);
	while (lena > 0 || lenb > 0)
	{
		if (lena >= lenb && lena > 0)
			lena = troisieme(&ba, com, lena, &i);
		if (lenb >= lena && lenb > 0)
			lenb = quatrieme(&bb, com, lenb, &j);
		ft_putchar('\n');
	}
	ft_printf("  \033[36m_______________ _______________\033[00m\n");
	ft_printf("         \033[32mA\033[00m               \033[35mB\033[00m\n\n");
	sleep(1);
}
