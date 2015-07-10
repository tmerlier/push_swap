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

int				get_first(t_push *list)
{
	return (list->nb);
}

int				get_last(t_push *list)
{
	while (list->next)
		list = list->next;
	return (list->nb);
}

int				get_before_last(t_push *list)
{
	while (list->next)
		list = list->next;
	return (list->prev->nb);
}
