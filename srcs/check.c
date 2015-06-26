/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 14:13:56 by tmerlier          #+#    #+#             */
/*   Updated: 2015/06/26 16:13:45 by tmerlier         ###   ########.fr       */
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
			if (i == 0 && arg[i] == 45 && len > 1)
			{
				ft_putendl("C est un tiret");
			}
			else if (arg[i] < 48 || *arg > 57)
			{
				ft_putendl("Houla");
				return (0);
			}
			else
				;
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
