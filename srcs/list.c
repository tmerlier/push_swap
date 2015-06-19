/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:57:44 by tmerlier          #+#    #+#             */
/*   Updated: 2014/04/16 19:03:40 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "push_swap.h"

void	add_nb(int nb, t_push *list)
{
	t_push	*tmp;

	tmp = list;
	while (tmp->next->next)
		tmp = tmp->next;

	tmp->next->nb = nb;
	tmp->next->prev = tmp;
	tmp->next->next = list;
}

t_push	*create_list(char **argv, t_options *options)
{
	t_push	*list;

	while (*argv++)
	{
		if (ft_str_isint(*argv, ft_strlen(*argv)))
			add_nb(ft_atoi(*argv));
		else if (is_option(*argv))
			add_options(*argv, options);
		else
			error("Au moins un argument n\'est pas un int.");
	}
}
