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
	ft_putstr(str);
	if (ft_strcmp(str, "ra\n") == 0 || ft_strcmp(str, "rb\n") == 0 || ft_strcmp(str, "rr\n") == 0)
		ft_rotate(ba, bb, i);
	else if (ft_strcmp(str, "rra\n") == 0 || ft_strcmp(str, "rrb\n") == 0 || ft_strcmp(str, "rrr\n") == 0)
		ft_rotate_rev(ba, bb, i);
	else if (ft_strcmp(str, "sa\n") == 0 || ft_strcmp(str, "sb\n") == 0 || ft_strcmp(str, "ss\n") == 0)
		ft_swap(ba, bb, i);
	else if (ft_strcmp(str, "pa\n") == 0 || ft_strcmp(str, "pb\n") == 0)
		ft_push(ba, bb, i);
}
