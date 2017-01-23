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

static inline void	noodle(t_box **ba, t_box **bb, unsigned int len, t_opt opt)
{
	t_com			*com;

	com = NULL;
	ft_getcom(&com);
	ft_execute(ba, bb, com, opt);
	if (ft_checker(*ba, len) == 1)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	boxdel(ba);
	boxdel(bb);
	comdel(&com);
}

int					main(int ac, char **av)
{
	t_box			*ba;
	t_box			*bb;
	t_opt			opt;
	int				i;

	i = 1;
	ba = NULL;
	bb = NULL;
	opt.opt = nul;
	if (ac > 1)
	{
		if (ft_strcmp(av[i], "-c") == 0)
		{
			opt.opt = c;
			i++;
		}
		else if (ft_strcmp(av[i], "-v") == 0)
		{
			opt.opt = v;
			i++;
		}
		if (ac > i)
			noodle(&ba, &bb, ft_getnbr(av + i, ac - i, &ba), opt);
	}
	return (0);
}
