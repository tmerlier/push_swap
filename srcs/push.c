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
	t_push		*tmpb;
	int			swap;

	tmpb = *listb;
	if (tmpb)
	{
		while (tmpb->next)
			tmpb = tmpb->next;
		swap = tmpb->nb;
		add_nb(swap, lista);
		push_color(lista);
		del_nb(swap, listb);
		add_action(action, cpy_list((*lista)), cpy_list((*listb)), "pa");
		reset_color(lista);
	}
}

void		push_b(t_push **lista, t_push **listb, t_action **action)
{
	t_push		*tmpa;
	int			swap;

	tmpa = *lista;
	if (tmpa)
	{
		while (tmpa->next)
			tmpa = tmpa->next;
		swap = tmpa->nb;
		add_nb(swap, listb);
		push_color(listb);
		del_nb(swap, lista);
		add_action(action, cpy_list((*lista)), cpy_list((*listb)), "pb");
		(*listb)->color = OFF;
		reset_color(listb);
	}
}
