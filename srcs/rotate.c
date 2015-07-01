/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:57:44 by tmerlier          #+#    #+#             */
/*   Updated: 2015/06/21 11:11:31 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rotate_a(t_push **listA)
{
	t_push		*tmpA;
	int			start;

	tmpA = *listA;
	start = (*listA)->nb;
	while (tmpA->next)
	{
		tmpA->nb = tmpA->next->nb;
		tmpA = tmpA->next;
	}
	tmpA->nb = start;
}

void		rotate_b(t_push **listB)
{
	t_push		*tmpB;
	int			start;

	tmpB = *listB;
	start = (*listB)->nb;
	while (tmpB->next)
	{
		tmpB->nb = tmpB->next->nb;
		tmpB = tmpB->next;
	}
	tmpB->nb = start;
}

void		rotate_ab(t_push **listA, t_push **listB)
{
	rotate_a(listA);
	rotate_b(listB);
}
