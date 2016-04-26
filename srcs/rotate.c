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

void			rotate_a(t_push **lista, t_push **listb)
{
	t_push		*tmpa;
	int			end;

	if (*lista)
	{
		tmpa = *lista;
		tmpa->color = ON;
		while (tmpa->next)
			tmpa = tmpa->next;
		end = tmpa->nb;
		while (tmpa->prev)
		{
			tmpa->nb = tmpa->prev->nb;
			tmpa = tmpa->prev;
			tmpa->color = ON;
		}
		(*lista)->nb = end;
		// add_action(action, cpy_list(*lista), cpy_list(*listb), "ra");
		add_action(cpy_list(*lista), cpy_list(*listb), "ra");
		reset_color(lista);
	}
}

void			rotate_b(t_push **lista, t_push **listb)
{
	t_push		*tmpb;
	int			end;

	if (*listb)
	{
		tmpb = *listb;
		tmpb->color = ON;
		while (tmpb->next)
			tmpb = tmpb->next;
		end = tmpb->nb;
		while (tmpb->prev)
		{
			tmpb->nb = tmpb->prev->nb;
			tmpb = tmpb->prev;
			tmpb->color = ON;
		}
		(*listb)->nb = end;
		// add_action(action, cpy_list(*lista), cpy_list(*listb), "rb");
		add_action(cpy_list(*lista), cpy_list(*listb), "rb");
		reset_color(listb);
	}
}

void			rotate_ab(t_push **lista, t_push **listb)
{
	rotate_a(lista, listb);
	rotate_b(lista, listb);
}
