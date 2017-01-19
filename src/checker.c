/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:08:06 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/04 18:33:00 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_box			*ba;
	t_box			*bb;
	t_com			*com;
	unsigned int	len;

	ba = NULL;
	bb = NULL;
	com = NULL;
	len = 0;
	if (ac > 1)
	{
		len = ft_getnbr(av + 1, ac - 1, &ba);
		ft_getcom(&com);
		ft_execute(&ba, &bb, com);
		if (ft_checker(ba, len) == 1)
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
		boxdel(&ba);
		boxdel(&bb);
		comdel(&com);
	}
	return (0);
}
