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

static void			order_b(t_push **lista, t_push **listb)
{
	// Tant que b n'est pas vide et qu'elle n'est pas rangée
	while (checklen(*listb) > 1 && !checkorder_increase(*listb))
	{
		if (get_last(*listb) < get_before_last(*listb))
		{
			swap_b(lista, listb);
			if (!checkorder_increase(*listb))
				push_a(lista, listb);
		}
		else
			break ;
	}
}

static void			order_a(t_push **lista, t_push **listb)
{
	while (!checkorder_decrease(*lista))
	{
		// Si le dernier est le plus petit
		if (get_last(*lista) < get_before_last(*lista) && get_last(*lista) < get_first(*lista))
		{
			if (*listb == NULL || get_last(*lista) > get_last(*listb))
				push_b(lista, listb);
			else
			{
				push_a(lista, listb);
				swap_a(lista, listb);
			}
		}
		else
		{
			// SI l'avant dernier qui est le plus petit
			if (get_before_last(*lista) < get_first(*lista))
				swap_a(lista, listb);
			else
				rev_rotate_a(lista, listb);
		}
		order_b(lista, listb);
	}
}

t_action			*push_swap(t_push *lista)
{
	t_push		*listb;
	t_action	*actions;

	listb = cpy_list(lista);
	actions = NULL;
	add_action(lista, listb, "START");
	order_a(&lista, &listb);
	while (checklen(listb))
	{
		push_a(&lista, &listb);
		order_a(&lista, &listb);
	}
	del_list(&lista);
	del_list(&listb);
	return (actions);
}
