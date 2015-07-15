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

void			rotate_a(t_push **lista, t_push **listb, t_action **action)
{
	t_push		*tmpA;
	int			end;

	if (*lista)
	{
		tmpA = *lista;
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
		(*lista)->nb = end;
		add_action(action, cpy_list(*lista), cpy_list(*listb), "ra");
		reset_color(lista);
	}
}

void			rotate_b(t_push **lista, t_push **listb, t_action **action)
{
	t_push		*tmpB;
	int			end;

	if (*listb)
	{
		tmpB = *listb;
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
		(*listb)->nb = end;
		add_action(action, cpy_list(*lista), cpy_list(*listb), "rb");
		reset_color(listb);
	}
}

void			rotate_ab(t_push **lista, t_push **listb, t_action **action)
{
	rotate_a(lista, listb, action);
	rotate_b(lista, listb, action);
}
