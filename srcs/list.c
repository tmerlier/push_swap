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

	if (!(new = (t_push *) malloc(sizeof(t_push))))
		error("Malloc fail.");
	new->nb = nb;
	new->prev = NULL;
	new->next = NULL;

	return (new);
}

void			del_nb(int nb, t_push **list)
{
	t_push	*tmp;

	tmp = *list;
	while (tmp->nb != nb)
	{
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		tmp->next = NULL;
		tmp = NULL;
		free(tmp);
	}
}
// A MODIFIER !!!!!!!!!
void			add_nb(int nb, t_push **list)
{
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

static void			add_new_nb(int nb, t_push **list)
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
	int		i;
	int		option;

	list = NULL;
	option = 0;
	if (argv[1][0] == '-')
		option = is_option(argv[1]);
	i = 1 + option;
	while (i < argc)
	{
		if (ft_str_isint(argv[i], ft_strlen(argv[i])))
			add_new_nb(ft_atoi(argv[i]), &list);
		else
			error("Au moins un argument n\'est pas un int.");
		i++;
	}
	checkdouble(list);
	checklen(list);
	return list;
}
