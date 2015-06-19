/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:54:51 by tmerlier          #+#    #+#             */
/*   Updated: 2014/04/21 11:29:19 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ON 1
# define OFF 0

typedef struct		s_push
{
	int				nb;
	int				start;
	struct s_push	*prev;
	struct s_push	*next;
}					t_push;

typedef struct	s_options
{
	int			r;
	int			d;
}				t_options;

t_push			*create_list(char **argv);
void			add_nb(int nb);
t_options		*init_options(void);
int				is_options(char **argv);
void			error(char *err_msg);

#endif
