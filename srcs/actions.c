/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:57:44 by tmerlier          #+#    #+#             */
/*   Updated: 2015/06/21 11:11:31 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static t_action		*new_action(t_push *lista, t_push *listb, char *action)
{
	t_action	*new;

	if (!(new = (t_action *)malloc(sizeof(t_action))))
		error("Malloc fail.");
	new->action = action;
	new->lista = lista;
	new->listb = listb;
	new->next = NULL;
	return (new);
}

void				add_action(t_action **action_list, t_push *lista,
									t_push *listb, char *action)
{
	static t_action		*last = NULL;
	t_action			*new;

	new = new_action(lista, listb, action);
	if (last)
		last->next = new;
	else
		*action_list = new;
	last = new;
}
