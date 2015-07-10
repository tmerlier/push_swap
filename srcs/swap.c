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

void	swap_a(t_push **listA, t_push **listB, t_action **action)
{
	t_push		*tmp;
	int			swap;

	if (checklen(*listA) > 1)
	{
		tmp = *listA;
		while (tmp->next)
			tmp = tmp->next;
		swap = tmp->nb;
		tmp->nb = tmp->prev->nb;
		tmp->prev->nb = swap;
		tmp->color = ON;
		tmp->prev->color = ON;
		add_action(action, cpy_list((*listA)), cpy_list((*listB)), "sa");
		reset_color(listA);
	}
}

void	swap_b(t_push **listA, t_push **listB, t_action **action)
{
	t_push		*tmp;
	int			swap;

	if (checklen(*listB) > 1)
	{
		tmp = *listB;
		while (tmp->next)
			tmp = tmp->next;
		swap = tmp->nb;
		tmp->nb = tmp->prev->nb;
		tmp->prev->nb = swap;
		tmp->color = ON;
		tmp->prev->color = ON;
		add_action(action, cpy_list((*listA)), cpy_list((*listB)), "sb");
		reset_color(listB);
	}
}

void	swap_ab(t_push **listA, t_push **listB, t_action **action)
{
	swap_a(listA, listB, action);
	swap_b(listA, listB, action);
}
