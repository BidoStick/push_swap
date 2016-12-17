/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:18:48 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/17 16:11:56 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "get_next_line.h"

typedef	struct		s_com
{
	char			*com;
	struct s_com	*next;
}					t_com;

typedef struct		s_box
{
	int	nbr;
	int i;
	int pile;
	struct s_box *next;
}					t_box;

int ft_checknbr(char *str, t_box *box);
char *ft_checkcom(char *str);
t_box	*ft_newbox(int nbr, int i, t_box **box);
t_com	*ft_newcom(char *command, t_com **com);
void	ft_execute(t_box *box, t_com *com);
void	ft_swap(t_box *box, int pile);
int		ft_count_nbr(t_box *box, int pile);
void	ft_push(t_box *box, int pile);
void	ft_rotate(t_box *box, int pile);
void	ft_rotate_rev(t_box *box, int pile);

#endif
