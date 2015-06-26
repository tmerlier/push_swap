/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:54:51 by tmerlier          #+#    #+#             */
/*   Updated: 2015/06/26 15:09:31 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ON 1
# define OFF 0

typedef struct		s_push
{
	int				nb;
	struct s_push	*prev;
	struct s_push	*next;
}					t_push;

typedef struct	s_options
{
	int			r;
	int			d;
}				t_options;

t_push			*create_list(int argc, char **argv);
void			print_list(t_push *list);
void			add_nb(int nb, t_push **list);

t_options		*init_options(void);
t_options		*options(void);
int				is_option(char *argv);

int				checkint(char *arg);
void			checkdouble(t_push *list);

void			error(char *err_msg);

#endif
