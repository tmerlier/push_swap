/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:57:44 by tmerlier          #+#    #+#             */
/*   Updated: 2015/06/21 15:23:10 by tmerlier         ###   ########.fr       */
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

void			print_list(t_push **list)
{
	t_push	*tmp;

	tmp = *list;
	while (tmp->next != *list && tmp->next)
	{
		// ft_putnbr(tmp->nb);
		// ft_putchar('\n');
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
		ft_putstr("-|(");
		ft_putnbr(last->nb);
		ft_putstr(")|-\n");

		last->next = new;  //problem
		new->prev = last;
		new->next = *list;
		last = new;        //problem
		ft_putstr("-|(");
		ft_putnbr(last->nb);
		ft_putstr(")|-\n");

		(*list)->prev = last;
	}
	else
	{
		*list = new;
		last = *list;
	}
}

// NULL<-[list]->NULL
// NULL<-[new1]->NULL

int				check_number(t_push *list, char *nbr)
{
	t_push	*tmp;

	if (!ft_str_isint(nbr, ft_strlen(nbr)))
	{
		if (list)
		{
			tmp = list;
			// ft_putendl("list");
			while (tmp->next)
			{
				// ft_putendl("while");
				if (tmp->next == list)
				{
				// ft_putendl("break");
					break;
				}
				if (tmp->nb == ft_atoi(nbr))
					error("Argument en double.");
				tmp = tmp->next;
			}
			return (1);
		}
		else
			return (1);
	}
	error("Au moins un argument n\'est pas un int.");
	return (0);
}

t_push			*create_list(int argc, char **argv)
{
	t_push	*list;
	int		i;

	list = NULL;
	i = 1;
	while (i < argc)
	{
		if (check_number(list, argv[i]))
			add_nb(ft_atoi(argv[i]), &list);
		else if (is_option(argv[i]))
			;
		else
			error("???");
		i++;
	}
	return list;
}


// /<-[list]-><-[new/last]->/
