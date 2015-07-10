/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:57:44 by tmerlier          #+#    #+#             */
/*   Updated: 2015/06/21 11:11:31 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static t_push		*new_list_cpy(int nb, int color)
{
	t_push	*new;

	if (!(new = (t_push *) malloc(sizeof(t_push))))
		error("Malloc fail.");
	new->nb = nb;
	new->color = color;
	new->prev = NULL;
	new->next = NULL;

	return (new);
}

static void			add_new_cpy(int nb, int color, t_push **cpy)
{
	t_push			*new;
	t_push			*tmp;

	new = new_list_cpy(nb, color);
	tmp = *cpy;
	if (!*cpy)
		*cpy = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

t_push				*cpy_list(t_push *list)
{
	t_push	*cpy;

	cpy = NULL;
	while (list)
	{
		add_new_cpy(list->nb, list->color, &cpy);
		list = list->next;
	}
	return (cpy);
}
