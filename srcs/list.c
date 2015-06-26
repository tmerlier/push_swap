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

#include <stdlib.h>
#include <libft.h>
#include "push_swap.h"

static t_push	*new_list(int nb)
{
	t_push	*new;

	if (!(new = (t_push *) malloc(sizeof(t_push *))))
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

void			print_data(int nb)
{
	ft_putstr("list = ");
	ft_putnbr(nb);
	ft_putchar('\n');
}

void			print_list(t_push *list)
{
	t_push	*tmp;

	tmp = list;
	if (tmp)
	{
		ft_putendl("tmp");
		print_data(tmp->nb);
		if (tmp->next)
		{
			tmp = tmp->next;
			ft_putendl("if");
			while (tmp != list)
			{
				ft_putendl("while");
				print_data(tmp->nb);
				tmp = tmp->next;
			}
		}
	}
}


// test
#include <stdio.h>

void			add_nb(int nb, t_push **list)
{
	static t_push	*last = NULL;
	t_push			*new;

	new = new_list(nb);
	if (last)
	{
		// printf("last = %p\nlist = %p\nnew  = %p\n\n",last, list, new);
		last->next = new;
		// printf("last = %p\nlist = %p\nnew = %p\n",last, list, new);
		new->prev = last;
		// printf("last = %p\nlist = %p\nnew = %p\n",last, list, new);
		new->next = *list;
		// printf("last = %p\nlist = %p\nnew = %p\n",last, list, new);
		(*list)->prev = new;
		// printf("last = %p\nlist = %p\nnew = %p\n",last, list, new);
		last = new;
		// printf("last = %p\nlist = %p\nnew = %p\n",last, list, new);
	}
	else
	{
		printf("last = %p\nlist = %p\nnew  = %p\n\n",last, list, new);
		*list = new;
		printf("last = %p\nlist = %p\nnew  = %p\n\n",last, list, new);
		last = *list;
		printf("last = %p\nlist = %p\nnew  = %p\n\n",last, list, new);
	}
}

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
