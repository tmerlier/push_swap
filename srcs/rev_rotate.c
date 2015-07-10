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

void		rev_rotate_a(t_push **listA, t_push **listB, t_action **action)
{
	t_push		*tmpA;
	int			start;

	if (*listA)
	{
		tmpA = *listA;
		start = (*listA)->nb;
		tmpA->color = ON;
		while (tmpA->next)
		{
			tmpA->nb = tmpA->next->nb;
			tmpA->color = ON;
			tmpA = tmpA->next;
		}
		tmpA->nb = start;
		add_action(action, cpy_list((*listA)), cpy_list((*listB)), "rra");
		reset_color(listA);
	}
}

void		rev_rotate_b(t_push **listA, t_push **listB, t_action **action)
{
	t_push		*tmpB;
	int			start;

	if (*listB)
	{
		tmpB = *listB;
		start = (*listB)->nb;
		tmpB->color = ON;
		while (tmpB->next)
		{
			tmpB->nb = tmpB->next->nb;
			tmpB->color = ON;
			tmpB = tmpB->next;
		}
		tmpB->nb = start;
		add_action(action, cpy_list((*listA)), cpy_list((*listB)), "rrb");
		reset_color(listB);
	}
}

void		rev_rotate_ab(t_push **listA, t_push **listB, t_action **action)
{
	rev_rotate_a(listA, listB, action);
	rev_rotate_b(listA, listB, action);
}
