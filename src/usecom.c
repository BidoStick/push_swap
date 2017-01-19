/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usecom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 18:20:10 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/14 18:20:14 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	usecom(t_box **ba, t_box **bb, char *str, int i)
{
	if (!ft_strcmp(str, "ra\n") || !ft_strcmp(str, "rb\n")
		|| !ft_strcmp(str, "rr\n"))
	{
		ft_putstr(str);
		ft_rotate(ba, bb, i);
	}
	else if (!ft_strcmp(str, "rra\n") || !ft_strcmp(str, "rrb\n")
		|| !ft_strcmp(str, "rrr\n"))
	{
		ft_putstr(str);
		ft_rotate_rev(ba, bb, i);
	}
	else if (!ft_strcmp(str, "sa\n") || !ft_strcmp(str, "sb\n")
		|| !ft_strcmp(str, "ss\n"))
	{
		ft_putstr(str);
		ft_swap(ba, bb, i);
	}
	else if (!ft_strcmp(str, "pa\n") || !ft_strcmp(str, "pb\n"))
	{
		ft_putstr(str);
		ft_push(ba, bb, i);
	}
}
