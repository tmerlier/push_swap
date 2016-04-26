/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:57:44 by tmerlier          #+#    #+#             */
/*   Updated: 2015/06/21 11:11:31 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "push_swap.h"

void	swap_a(t_push **lista, t_push **listb)
{
	t_push		*tmp;
	int			swap;

	if (checklen(*lista) > 1)
	{
		tmp = *lista;
		while (tmp->next)
			tmp = tmp->next;
		swap = tmp->nb;
		tmp->nb = tmp->prev->nb;
		tmp->prev->nb = swap;
		tmp->color = ON;
		tmp->prev->color = ON;
		// add_action(action, cpy_list((*lista)), cpy_list((*listb)), "sa");
		add_action(cpy_list((*lista)), cpy_list((*listb)), "sa");
		reset_color(lista);
	}
}

void	swap_b(t_push **lista, t_push **listb)
{
	t_push		*tmp;
	int			swap;

	if (checklen(*listb) > 1)
	{
		tmp = *listb;
		while (tmp->next)
			tmp = tmp->next;
		swap = tmp->nb;
		tmp->nb = tmp->prev->nb;
		tmp->prev->nb = swap;
		tmp->color = ON;
		tmp->prev->color = ON;
		// add_action(action, cpy_list((*lista)), cpy_list((*listb)), "sb");
		add_action(cpy_list((*lista)), cpy_list((*listb)), "sb");
		reset_color(listb);
	}
}

void	swap_ab(t_push **lista, t_push **listb)
{
	swap_a(lista, listb);
	swap_b(lista, listb);
}
