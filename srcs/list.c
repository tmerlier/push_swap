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

static t_push	*new_list(int nb)
{
	t_push	*new;

	if (!(new = ft_memalloc(sizeof(t_push *))))
		error("Malloc fail.");
	new->nb = nb;
	new->prev = NULL;
	new->next = NULL;

	return (new);
}
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

void			print_list(t_push *list)
{
	t_push	*tmp;

	tmp = list;
	while (tmp->next != list)
	{
		ft_putstr("list = ");
		ft_putnbr(tmp->nb);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

void			add_nb(int nb, t_push **list)
{
	static t_push	*last = NULL;
	t_push			*new;

	new = new_list(nb);
	if (last)
	{
		last->next = new;
		new->prev = last;
		new->next = *list;
		(*list)->prev = new;
		last = new;
	}
	else
	{
		*list = new;
		last = *list;
	}
}

// new<-[list]->new
// last<-[new/last]->list


t_push			*create_list(int argc, char **argv)
{
	t_push	*list;
	int		i;

	list = NULL;
	i = 1;
	while (i < argc)
	{
		if (!ft_str_isint(argv[i], ft_strlen(argv[i])))
			add_nb(ft_atoi(argv[i]), &list);
		else if (is_option(argv[i]))
			;
		else
			error("Au moins un argument n\'est pas un int.");
		i++;
	}
	return list;
}


// /<-[list]-><-[new/last]->/
