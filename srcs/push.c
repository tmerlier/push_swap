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

void		push_a(t_push **listA, t_push **listB, t_action **action)
{
	t_push		*tmpB;
	int			swap;

	tmpB = *listB;
	if (tmpB)
	{
		while (tmpB->next)
			tmpB = tmpB->next;
		swap = tmpB->nb;
		add_nb(swap, listA);
		push_color(listA);
		del_nb(swap, listB);
		add_action(action, cpy_list((*listA)), cpy_list((*listB)), "pa");
		reset_color(listA);
	}
}

void		push_b(t_push **listA, t_push **listB, t_action **action)
{
	t_push		*tmpA;
	int			swap;

	tmpA = *listA;
	if (tmpA)
	{
		while (tmpA->next)
			tmpA = tmpA->next;
		swap = tmpA->nb;
		add_nb(swap, listB);
		push_color(listB);
		del_nb(swap, listA);
		add_action(action, cpy_list((*listA)), cpy_list((*listB)), "pb");
		(*listB)->color = OFF;
		reset_color(listB);
	}
}
