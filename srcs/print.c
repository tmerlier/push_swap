/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/26 14:16:39 by tmerlier          #+#    #+#             */
/*   Updated: 2015/06/26 14:24:32 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "push_swap.h"

static void			print_data(int nb)
{
	ft_putstr("list = ");
	ft_putnbr(nb);
	ft_putchar('\n');
}

void			print_list(t_push *list)
{
	t_push	*tmp;

	tmp = list;
	while (tmp)
	{
		print_data(tmp->nb);
		tmp = tmp->next;
	}
}
