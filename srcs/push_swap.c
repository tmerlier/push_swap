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

void			orderB(t_push **lista, t_push **listb, t_action **actions)
{
	while(checklen(*listb) > 1 && !checkorder(*listb))
	{
		if (get_last(*listb) < get_before_last(*listb))
		{
			swap_b(lista, listb, actions);
			push_a(lista, listb, actions);
		}
		else
			break;
	}
}

void		orderA(t_push **lista, t_push **listb, t_action **actions)
{
	while (!checkorder(*lista))
	{
		if (get_last(*lista) > get_before_last(*lista))
			swap_a(lista, listb, actions);
		else
			push_b(lista, listb, actions);
		orderB(lista, listb, actions);
	}
}

t_action		*push_swap(t_push *lista)
{
	t_push		*listb;
	t_action	*actions;

	listb = NULL;
	actions = NULL;
	add_action(&actions, cpy_list(lista), cpy_list(listb), "START");
	orderA(&lista, &listb, &actions);
	while (checklen(listb))
	{
		push_a(&lista, &listb, &actions);
		orderA(&lista, &listb, &actions);
	}
	return actions;
}
