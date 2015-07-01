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

#include "push_swap.h"

void	swap_a(t_push **listA)
{
	t_push		*tmp;
	int			swap;

	tmp = *listA;
	while (tmp->next)
		tmp = tmp->next;
	swap = tmp->nb;
	tmp->nb = tmp->prev->nb;
	tmp->prev->nb = swap;
}

void	swap_b(t_push **listB)
{
	t_push		*tmp;
	int			swap;

	tmp = *listB;
	while (tmp->next)
		tmp = tmp->next;
	swap = tmp->nb;
	tmp->nb = tmp->prev->nb;
	tmp->prev->nb = swap;
}

void	swap_ab(t_push **listA, t_push **listB)
{
	swap_a(listA);
	swap_b(listB);
}
