/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:54:51 by tmerlier          #+#    #+#             */
/*   Updated: 2014/04/21 11:29:19 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct		s_push
{
	int				nb;
	struct s_push	*prev;
	struct s_push	*next;
}					t_push;

typedef struct	s_options
{
	int			l;

}				t_options;

t_push			*create_list(char **argv, t_options *options);
void			add_nb(int nb);
t_options		*add_options(char *argv, t_options *options);
t_options		*is_options(char **argv, t_options *options);
void			error(char *err_msg, t_options *options);

#endif
