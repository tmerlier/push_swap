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

#include "push_swap.h"

// TEST
#include <stdio.h>
void		push_a(t_push **listA, t_push **listB)
{
	t_push		*tmpB;
	int			swap;

	tmpB = *listB;
	if (tmpB->next)
	{
		while (tmpB->next)
		tmpB = tmpB->next;
		swap = tmpB->nb;
		printf("swap =%d\n", swap);
		add_nb(swap, listA);
		del_nb(swap, listB);
	}
}

void		push_b(t_push **listA, t_push **listB)
{
	t_push		*tmpA;
	int			swap;

	tmpA = *listA;
	if (tmpA->next)
	{
		while (tmpA->next)
			tmpA = tmpA->next;
		swap = tmpA->nb;
		printf("swap =%d\n", swap);
		add_nb(swap, listB);
		printf("add_nb");
		del_nb(swap, listA);
		printf("del_nb");
	}
}

void		push_ab(t_push **listA, t_push **listB)
{
	push_a(listA, listB);
	push_b(listA, listB);
}
