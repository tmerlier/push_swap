/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:57:44 by tmerlier          #+#    #+#             */
/*   Updated: 2015/06/26 16:07:00 by tmerlier         ###   ########.fr       */
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

void			add_nb(int nb, t_push **list)
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

	list = NULL;
	i = 1;
	while (i < argc)
	{
		if (checkint(argv[i]))
		{
			ft_putendl("checkint");
			add_nb(ft_atoi(argv[i]), &list);
		}
		else if (is_option(argv[i]))
		{
			ft_putendl("is_option");
		}
		else
			error("Au moins un argument n\'est pas un int.");
		i++;
	}
	checkdouble(list);
	ft_putendl("Tout roule!");
	return list;
}
