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

int				checklen(t_push *list)
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
