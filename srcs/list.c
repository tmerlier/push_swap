/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:57:44 by tmerlier          #+#    #+#             */
/*   Updated: 2015/06/27 15:52:22 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "push_swap.h"

static t_push	*new_list(int nb)
{
	t_push	*new;

	if (!(new = (t_push *)malloc(sizeof(t_push))))
		error("Malloc fail.");
	new->nb = nb;
	new->color = OFF;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void			del_nb(int nb, t_push **list)
{
	t_push	*tmp;

	tmp = *list;
	while (tmp && tmp->nb != nb)
		tmp = tmp->next;
	free(tmp);
	if (tmp->prev)
		tmp->prev->next = NULL;
	else
		*list = NULL;
	tmp = NULL;
}

void			add_nb(int nb, t_push **list)
{
	t_push			*new;
	t_push			*tmp;

	new = new_list(nb);
	tmp = *list;
	if (!*list)
		*list = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

static void		add_new_nb(int nb, t_push **list)
{
	static t_push	*last = NULL;
	t_push			*new;

	new = new_list(nb);
	if (last)
	{
		last->next = new;
		new->prev = last;
	}
	else
		*list = new;
	last = new;
}

t_push			*create_list(int argc, char **argv)
{
	t_push	*list;
	int		option;

	list = NULL;
	option = 0;
	if (argv[1][0] == '-')
		option += is_option(argv[1]);
	argc--;
	while (argc > option)
	{
		if (ft_str_isint(argv[argc], ft_strlen(argv[argc])))
			add_new_nb(ft_atoi(argv[argc]), &list);
		else
			error("Au moins un argument n\'est pas un int.");
		argc--;
	}
	checkdouble(list);
	checkempty(list);
	return (list);
}
