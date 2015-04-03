/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 13:22:31 by emammadz          #+#    #+#             */
/*   Updated: 2015/02/22 16:51:37 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_tri
{
	int		j;
	int		tmp;
	int		des;
	int		*tab;
	int		tmp2;
	int		i;
}				t_tri;

typedef struct	s_env
{
	int		ac;
	int		ac2;
	char	**av;
	int		*tab;
	int		*tab2;
	int		*tab_tri;
	int		which;
	char	*buf;
	char	*tmp;
	int		i;
	int		i2;
}				t_env;
void			algo_swap_show(t_env *e);
void			algo_swap_2(t_env *e);
int				check_errors_3_part_2(t_env *e, int i, int s, int which);
void			tri_algo(t_tri *e, t_env *r);
void			main_conditions(t_env *e);
void			*ft_realloc(void *ptr, size_t size);
void			add_moves(t_env *e);
void			show_moves(t_env *e, int which);
int				check_half(t_env *e);
int				*tri(t_env *e);
void			rrr(t_env *e);
void			print_tab(t_env *e);
int				check_tab(t_env *e);
void			rrb(t_env *e);
void			rra(t_env *e);
void			rr(t_env *e);
void			rb(t_env *e);
void			copy_tmp_i(t_env *e, int *tmp_i, int which_rotate);
void			ra(t_env *e);
void			pb(t_env *e);
void			ss(t_env *e);
void			pa(t_env *e);
void			sb(t_env *e);
void			sa(t_env *e);
void			copy_tab(t_env *e);
int				check_errors_3(t_env *e);
void			algo_swap(t_env *e);
int				check_errors_2(t_env *e);
void			error_message(void);
int				check_errors(t_env *e);
#endif
