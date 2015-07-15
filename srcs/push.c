/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:57:44 by tmerlier          #+#    #+#             */
/*   Updated: 2015/06/21 11:11:31 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "push_swap.h"

void		push_color(t_push **list)
{
	t_push			*tmp;

	tmp = *list;
	if (!*list)
		(*list)->color = ON;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->color = ON;
	}
}

void		push_a(t_push **lista, t_push **listb, t_action **action)
{
	t_push		*tmpB;
	int			swap;

	tmpB = *listb;
	if (tmpB)
	{
		while (tmpB->next)
			tmpB = tmpB->next;
		swap = tmpB->nb;
		add_nb(swap, lista);
		push_color(lista);
		del_nb(swap, listb);
		add_action(action, cpy_list((*lista)), cpy_list((*listb)), "pa");
		reset_color(lista);
	}
}

void		push_b(t_push **lista, t_push **listb, t_action **action)
{
	t_push		*tmpA;
	int			swap;

	tmpA = *lista;
	if (tmpA)
	{
		while (tmpA->next)
			tmpA = tmpA->next;
		swap = tmpA->nb;
		add_nb(swap, listb);
		push_color(listb);
		del_nb(swap, lista);
		add_action(action, cpy_list((*lista)), cpy_list((*listb)), "pb");
		(*listb)->color = OFF;
		reset_color(listb);
	}
}
