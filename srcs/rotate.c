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

#include <libft.h>
#include "push_swap.h"

void			rotate_a(t_push **listA)
{
	t_push		*tmpA;
	int			end;

	if (options()->d)
		ft_putendl("ra ");
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

void			rotate_b(t_push **listB)
{
	t_push		*tmpB;
	int			end;

	if (options()->d)
		ft_putendl("rb ");
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

void			rotate_ab(t_push **listA, t_push **listB)
{
	rotate_a(listA);
	rotate_b(listB);
}
