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

typedef	struct		s_com
{
	enum {
		s,
		p,
		r,
		rr
	} com;
	int pile;
	struct s_com	*next;
}					t_com;

typedef struct		s_box
{
	int	nbr;
	unsigned int i;
	struct s_box *next;
}					t_box;

typedef struct		s_nbr
{
	int small;
	int big;
	int lastbig;
	int first;
	int len;
}					t_nbr;

typedef struct		s_base
{
	int okbas1;
	int okbas2;
	int basea;
	int baseb;
}					t_base;

t_box	*ft_newbox(int nbr, t_box **box);
t_com	*ft_newcom(char *command, t_com **com);
void	boxdel(t_box **box);
void	comdel(t_com **com);

void	ft_getnbr(char **tab, int size, t_box **box);
unsigned int		ft_count_nbr(t_box *box);
int 	ft_checknbr(char *str, t_box *box);
char 	*ft_checkcom(char *str);
void	ft_getcom(t_com **com);
int		ft_getpile(char *str);

void	ft_swap(t_box **ba, t_box **bb, int pile);
void	ft_push(t_box **ba, t_box **bb, int pile);
void	ft_rotate(t_box **ba, t_box **bb, int pile);
void	ft_rotate_rev(t_box **ba, t_box **bb, int pile);

void	ft_execute(t_box **ba, t_box **bb, t_com *com);
int		ft_checker(t_box *box, int len);

void	parse(t_box **ba, t_box **bb);
void	affichage(t_box *ba, t_box *bb);

int		check_nbr(t_box *box, int small, int big);
void		separation_a(t_box **ba, t_box **bb, t_nbr lnb, t_base *base);
void		separation_b(t_box **ba, t_box **bb, t_nbr lnb, t_base *base);

int		search_nbr(t_box *box, int nb);
int		search_nsmall(t_box *box, int small, int big);
int		search_npivot(t_box *box, int small, int big);
void	separe(t_box **ba, t_box **bb, t_nbr lnb, t_base *base);
void	separe1(t_box **ba, t_box **bb, t_nbr lnb, t_base *base);
void	separe2(t_box **ba, t_box **bb, t_nbr lnb, t_base *base);

void	restore(t_box **ba, t_box **bb, t_base *base);

int		is_sort(t_box *box, int small, int big);
void	sort_a(t_box **ba, t_box **bb, t_nbr lnb);
void	sort_b(t_box **ba, t_box **bb, t_nbr lnb);

void	range_a(t_box **ba, t_box **bb, t_nbr lnb, t_base *base);
void	range_b(t_box **ba, t_box **bb, t_nbr lnb, t_base *base);

void	separe_a(t_box **ba, t_box **bb, t_nbr lnb, t_base *base);
void	separe_b(t_box **ba, t_box **bb, t_nbr lnb, t_base *base);

void	range_short_a(t_box **ba, t_box **bb, t_nbr lnb, t_base *base);
void	range_short_b(t_box **ba, t_box **bb, t_nbr lnb, t_base *base);

void	usecom(t_box **ba, t_box **bb, char *str, int i);
/*
char *pb_c(t_box *box, char *str);
char *s_c(t_box *box, char *str);
int	nbr_out(t_box *box, int i, int pile);
*/
#endif
