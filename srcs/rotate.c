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

void			rotate_a(t_push **listA, t_push **listB, t_action **action)
{
	t_push		*tmpA;
	int			end;

	if (*listA)
	{
		tmpA = *listA;
		tmpA->color = ON;
		while (tmpA->next)
			tmpA = tmpA->next;
		end = tmpA->nb;
		while (tmpA->prev)
		{
			tmpA->nb = tmpA->prev->nb;
			tmpA = tmpA->prev;
			tmpA->color = ON;
		}
		(*listA)->nb = end;
		add_action(action, cpy_list(*listA), cpy_list(*listB), "ra");
		reset_color(listA);
	}
}

void			rotate_b(t_push **listA, t_push **listB, t_action **action)
{
	t_push		*tmpB;
	int			end;

	if (*listB)
	{
		tmpB = *listB;
		tmpB->color = ON;
		while (tmpB->next)
			tmpB = tmpB->next;
		end = tmpB->nb;
		while (tmpB->prev)
		{
			tmpB->nb = tmpB->prev->nb;
			tmpB = tmpB->prev;
			tmpB->color = ON;
		}
		(*listB)->nb = end;
		add_action(action, cpy_list(*listA), cpy_list(*listB), "rb");
		reset_color(listB);
	}
}

void			rotate_ab(t_push **listA, t_push **listB, t_action **action)
{
	rotate_a(listA, listB, action);
	rotate_b(listA, listB, action);
}
