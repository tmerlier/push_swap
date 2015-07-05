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

// TEST
#include <stdio.h>
void		push_a(t_push **listA, t_push **listB)
{
	t_push		*tmpB;
	int			swap;

	if (options()->d)
		ft_putendl("pa ");
	tmpB = *listB;
	if (tmpB->next)
	{
		while (tmpB->next)
			tmpB = tmpB->next;
	}
	swap = tmpB->nb;
	add_nb(swap, listA);
	del_nb(swap, listB);
}

void		push_b(t_push **listA, t_push **listB)
{
	t_push		*tmpA;
	int			swap;

	if (options()->d)
		ft_putendl("pb ");
	tmpA = *listA;
	if (tmpA->next)
	{
		while (tmpA->next)
			tmpA = tmpA->next;
	}
	swap = tmpA->nb;
	add_nb(swap, listB);
	del_nb(swap, listA);
}

void		push_ab(t_push **listA, t_push **listB)
{
	push_a(listA, listB);
	push_b(listA, listB);
}
