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

#include "push_swap.h"

void			rev_rotate_a(t_push **listA)
{
	t_push		*tmpA;
	int			end;

	tmpA = *listA;
	while (tmpA->next)
		tmpA = tmpA->next;
	end = tmpA->nb;
	while (tmpA->prev)
	{
		tmpA->nb = tmpA->prev->nb;
		tmpA = tmpA->prev;
	}
	(*listA)->nb = end;
}

void			rev_rotate_b(t_push **listB)
{
	t_push		*tmpB;
	int			end;

	tmpB = *listB;
	while (tmpB->next)
		tmpB = tmpB->next;
	end = tmpB->nb;
	while (tmpB->prev)
	{
		tmpB->nb = tmpB->prev->nb;
		tmpB = tmpB->prev;
	}
	(*listB)->nb = end;
}

void			rev_rotate_ab(t_push **listA, t_push **listB)
{
	rev_rotate_a(listA);
	rev_rotate_b(listB);
}
