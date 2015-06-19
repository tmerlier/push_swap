/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:57:44 by tmerlier          #+#    #+#             */
/*   Updated: 2014/04/16 19:03:40 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "push_swap.h"

static t_push	new_list(int nb)
{
	t_push	*new;

	if (!(new = ft_memalloc(sizeof(t_push *))))
		error("Malloc fail.")
	tmp->nb = nb;
	tmp->start = ON;
	tmp->prev = NULL;
	tmp->next = NULL;
// }
// struct dada
// {
// 	t_push		start;
// 	t_push		end;
// }

// void rotate (dada e)
// {
// 	e.end->next = e.start;
// 	e.start = e.start->next;
// 	e.end->next.next = NULL;
// 	e.end = e.end->next;
// }

void			add_nb(int nb, t_push *list)
{
	static t_push	*last = NULL;
	t_push			*new;

	new = new_list(nb);
	if (last)
	{
		tmp->start = OFF;
		tmp->prev = last;
		tmp->next = list;
		last = tmp;
		list->prev = last;
	}
	else
		list = new_list(nb);
}

t_push			*create_list(char **argv)
{
	t_push	*list;

	list = NULL
	while (*argv++)
	{
		if (ft_str_isint(*argv, ft_strlen(*argv)))
			add_nb(ft_atoi(*argv), list);
		else if (is_option(*argv))
			;
		else
			error("Au moins un argument n\'est pas un int.");
	}
}


// []->[]->[]->[tmp2]->[tmp]->//
