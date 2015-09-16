/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 14:13:56 by tmerlier          #+#    #+#             */
/*   Updated: 2015/06/27 14:39:57 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "push_swap.h"

int				checkempty(t_push *list)
{
	int		i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	if (i == 0)
		error("List is empty.");
	return (i);
}

int				checklen(t_push *list)
{
	int		i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

int				checkorder_decrease(t_push *list)
{
	while (list->next)
	{
		if (list->nb < list->next->nb)
			return (0);
		list = list->next;
	}
	return (1);
}

int				checkorder_increase(t_push *list)
{
	while (list->next)
	{
		if (list->nb > list->next->nb)
			return (0);
		list = list->next;
	}
	return (1);
}

int				checkdouble(t_push *list)
{
	t_push		*tmp;

	while (list)
	{
		tmp = list->next;
		while (tmp)
		{
			if (tmp->nb == list->nb)
				error("Double numbers.");
			tmp = tmp->next;
		}
		list = list->next;
	}
	return (1);
}
