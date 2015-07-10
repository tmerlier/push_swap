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

static t_action		*new_action(t_push *listA, t_push *listB, char *action)
{
	t_action	*new;

	if (!(new = (t_action *) malloc(sizeof(t_action))))
		error("Malloc fail.");
	new->action = action;
	new->listA = listA;
	new->listB = listB;
	new->next = NULL;

	return (new);
}


void				add_action(t_action **action_list, t_push *listA, t_push *listB, char *action)
{
	static t_action		*last = NULL;
	t_action			*new;

	new = new_action(listA, listB, action);
	if (last)
		last->next = new;
	else
		*action_list = new;
	last = new;
}

