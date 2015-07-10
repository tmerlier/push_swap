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
	int				color;
	struct s_push	*prev;
	struct s_push	*next;
}					t_push;

typedef struct		s_options
{
	int				r;
	int				v;
	int				c;
}					t_options;

typedef struct		s_action
{
	char			*action;
	t_push			*lista;
	t_push			*listb;
	struct s_action	*next;
}					t_action;

t_action			*push_swap(t_push *listb);

t_push				*create_list(int argc, char **argv);
void				add_nb(int nb, t_push **list);
void				del_nb(int nb, t_push **list);

t_push				*cpy_list(t_push *list);

void				add_action(t_action **action_list, t_push *lista,
								t_push *listb, char *action);

int					get_first(t_push *list);
int					get_last(t_push *list);
int					get_before_last(t_push *list);

void				print_list(t_push *list, char *list_name);
void				print_actions(t_action *action);
void				print_display(t_push *lista, t_push *listb);

void				reset_color(t_push **list);
t_options			*init_options(void);
t_options			*options(void);
int					is_option(char *argv);

int					checklen(t_push *list);
int					checkdouble(t_push *list);
int					checkempty(t_push *list);
int					checkorder(t_push *list);

void				swap_a(t_push **lista, t_push **listb, t_action **action);
void				swap_b(t_push **lista, t_push **listb, t_action **action);
void				swap_ab(t_push **lista, t_push **listb, t_action **action);

void				push_a(t_push **lista, t_push **listb, t_action **action);
void				push_b(t_push **lista, t_push **listb, t_action **action);

void				rotate_a(t_push **lista, t_push **listb,
								t_action **action);
void				rotate_b(t_push **lista, t_push **listb, t_action **action);
void				rotate_ab(t_push **lista, t_push **listb,
								t_action **action);

void				rev_rotate_a(t_push **lista, t_push **listb,
								t_action **action);
void				rev_rotate_b(t_push **lista, t_push **listb,
								t_action **action);
void				rev_rotate_ab(t_push **lista, t_push **listb,
								t_action **action);

void				error(char *err_msg);

#endif
