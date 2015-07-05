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

void		rev_rotate_a(t_push **listA)
{
	t_push		*tmpA;
	int			start;

	if (options()->d)
		ft_putendl("rra ");
	tmpA = *listA;
	start = (*listA)->nb;
	while (tmpA->next)
	{
		tmpA->nb = tmpA->next->nb;
		tmpA = tmpA->next;
	}
	tmpA->nb = start;
}

void		rev_rotate_b(t_push **listB)
{
	t_push		*tmpB;
	int			start;

	if (options()->d)
		ft_putendl("rrb ");
	tmpB = *listB;
	start = (*listB)->nb;
	while (tmpB->next)
	{
		tmpB->nb = tmpB->next->nb;
		tmpB = tmpB->next;
	}
	tmpB->nb = start;
}

void		rev_rotate_ab(t_push **listA, t_push **listB)
{
	rev_rotate_a(listA);
	rev_rotate_b(listB);
}
