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

int				checkint(char *arg)
{
	int			len;
	int			i;

	i = 0;
	len = ft_strlen(arg);
	if (!ft_str_isint(arg, len))
	{
		while (arg[i])
		{
			if (arg[i] < 48 || arg[i] > 57)
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

void			checkdouble(t_push *list)
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
}
