/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
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
	t_push		*tmpa;
	int			start;

	if (*lista)
	{
		tmpa = *lista;
		start = (*lista)->nb;
		tmpa->color = ON;
		while (tmpa->next)
		{
			tmpa->nb = tmpa->next->nb;
			tmpa->color = ON;
			tmpa = tmpa->next;
		}
		tmpa->nb = start;
		add_action(action, cpy_list((*lista)), cpy_list((*listb)), "rra");
		reset_color(lista);
	}
}

void		rev_rotate_b(t_push **lista, t_push **listb, t_action **action)
{
	t_push		*tmpb;
	int			start;

	if (*listb)
	{
		tmpb = *listb;
		start = (*listb)->nb;
		tmpb->color = ON;
		while (tmpb->next)
		{
			tmpb->nb = tmpb->next->nb;
			tmpb->color = ON;
			tmpb = tmpb->next;
		}
		tmpb->nb = start;
		add_action(action, cpy_list((*lista)), cpy_list((*listb)), "rrb");
		reset_color(listb);
	}
}

void		rev_rotate_ab(t_push **lista, t_push **listb, t_action **action)
{
	rev_rotate_a(lista, listb, action);
	rev_rotate_b(lista, listb, action);
}
