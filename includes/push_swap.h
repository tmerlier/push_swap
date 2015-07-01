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

void			push_swap(t_push *listB);

t_push			*create_list(int argc, char **argv);
void			add_nb(int nb, t_push **list);
void			del_nb(int nb, t_push **list);

void			print_list(t_push *list, char * list_name);
void			print_display(t_push *listA, t_push *listB);

t_options		*init_options(void);
t_options		*options(void);
int				is_option(char *argv);

int				checklen(t_push *list);
int				checkdouble(t_push *list);

void			swap_a(t_push **listA);
void			swap_b(t_push **listB);
void			swap_ab(t_push **listA, t_push **listB);


void			push_a(t_push **listA, t_push **listB);
void			push_b(t_push **listA, t_push **listB);
void			push_ab(t_push **listA, t_push **listB);

void			rotate_a(t_push **listA);
void			rotate_b(t_push **listB);
void			rotate_ab(t_push **listA, t_push **listB);

void			rev_rotate_a(t_push **listA);
void			rev_rotate_b(t_push **listB);
void			rev_rotate_ab(t_push **listA, t_push **listB);

void			error(char *err_msg);

#endif
