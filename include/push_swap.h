/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:18:48 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/03 17:42:38 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "get_next_line.h"
# include "ft_printf.h"

typedef	struct		s_opt
{
	enum {
		nul,
		v,
		c
	}				opt;
}					t_opt;

typedef	struct		s_com
{
	enum {
		s,
		p,
		r,
		rr
	}				com;
	int				pile;
	struct s_com	*next;
}					t_com;

typedef struct		s_box
{
	int				nbr;
	unsigned int	i;
	struct s_box	*next;
}					t_box;

typedef struct		s_nbr
{
	unsigned int	small;
	unsigned int	big;
	unsigned int	lastbig;
	unsigned int	len;
}					t_nbr;

typedef struct		s_base
{
	unsigned int	a;
	unsigned int	ni;
}					t_base;

void				affichage(t_box *ba, t_box *bb, t_com *com);
void				affichv(t_box *ba, t_box *bb, t_com *com);
void				cmd(t_com *com);

t_box				*ft_newbox(int nbr, t_box **box);
t_com				*ft_newcom(char *command, t_com **com);
void				boxdel(t_box **box);
void				comdel(t_com **com);

unsigned int		ft_getnbr(char **tab, unsigned int size, t_box **box);
unsigned int		ft_count_nbr(t_box *box);
int					ft_checknbr(char *str, t_box *box);
char				*ft_checkcom(char *str);
void				ft_getcom(t_com **com);
int					ft_getpile(char *str);

void				ft_swap(t_box **ba, t_box **bb, int pile);
void				ft_push(t_box **ba, t_box **bb, int pile);
void				ft_rotate(t_box **ba, t_box **bb, int pile);
void				ft_rotate_rev(t_box **ba, t_box **bb, int pile);

void				ft_execute(t_box **ba, t_box **bb, t_com *com, t_opt opt);
int					ft_checker(t_box *box, int len);

void				start(t_box **ba, t_box **bb);

int					check_nbr(t_box *box, int small, int big);
void				usecom(t_box **ba, t_box **bb, char *str, int i);

void				pushback(t_box **ba, t_box **bb, t_nbr lnb, t_base *base);
void				sort(t_box **ba, t_box **bb, t_base *base);
unsigned int		lastnbr(t_box *box);
void				check_tri_a(t_box *ba, t_base *base);
void				restore(t_box **ba, t_box **bb, t_nbr lnb, t_base *base);
void				move(t_box **ba, t_box **bb, t_nbr lnb, t_base *base);
void				remove_pushback_a(t_box **ba, t_box **bb, t_nbr lnb,
					t_base *base);
int					is_in(t_box *box, unsigned int i);
unsigned int		check_tri_b(t_box *bb, t_base *base);
void				remove_rev_pushback(t_box **ba, t_box **bb, t_base *base);

#endif
