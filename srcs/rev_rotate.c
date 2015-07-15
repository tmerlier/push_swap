/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:57:44 by tmerlier          #+#    #+#             */
/*   Updated: 2015/06/21 11:11:31 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "push_swap.h"

void		rev_rotate_a(t_push **lista, t_push **listb, t_action **action)
{
	t_push		*tmpA;
	int			start;

	if (*lista)
	{
		tmpA = *lista;
		start = (*lista)->nb;
		tmpA->color = ON;
		while (tmpA->next)
		{
			tmpA->nb = tmpA->next->nb;
			tmpA->color = ON;
			tmpA = tmpA->next;
		}
		tmpA->nb = start;
		add_action(action, cpy_list((*lista)), cpy_list((*listb)), "rra");
		reset_color(lista);
	}
}

void		rev_rotate_b(t_push **lista, t_push **listb, t_action **action)
{
	t_push		*tmpB;
	int			start;

	if (*listb)
	{
		tmpB = *listb;
		start = (*listb)->nb;
		tmpB->color = ON;
		while (tmpB->next)
		{
			tmpB->nb = tmpB->next->nb;
			tmpB->color = ON;
			tmpB = tmpB->next;
		}
		tmpB->nb = start;
		add_action(action, cpy_list((*lista)), cpy_list((*listb)), "rrb");
		reset_color(listb);
	}
}

void		rev_rotate_ab(t_push **lista, t_push **listb, t_action **action)
{
	rev_rotate_a(lista, listb, action);
	rev_rotate_b(lista, listb, action);
}
