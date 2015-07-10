/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:57:44 by tmerlier          #+#    #+#             */
/*   Updated: 2015/06/27 15:52:22 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void			orderB(t_push **listA, t_push **listB, t_action **actions)
{
	while(checklen(*listB) > 1 && !checkorder(*listB))
	{
		if (get_last(*listB) < get_before_last(*listB))
		{
			swap_b(listA, listB, actions);
			push_a(listA, listB, actions);
		}
		else
			break;
	}
}

void		orderA(t_push **listA, t_push **listB, t_action **actions)
{
	while (!checkorder(*listA))
	{
		if (get_last(*listA) > get_before_last(*listA))
			swap_a(listA, listB, actions);
		else
			push_b(listA, listB, actions);
		orderB(listA, listB, actions);
	}
}

t_action		*push_swap(t_push *listA)
{
	t_push		*listB;
	t_action	*actions;

	listB = NULL;
	actions = NULL;
	add_action(&actions, cpy_list(listA), cpy_list(listB), "START");
	orderA(&listA, &listB, &actions);
	while (checklen(listB))
	{
		push_a(&listA, &listB, &actions);
		orderA(&listA, &listB, &actions);
	}
	return actions;
}
