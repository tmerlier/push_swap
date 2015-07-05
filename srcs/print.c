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
	ft_putnbr(nb);
	ft_putchar(' ');
}

void			print_list(t_push *list, char *list_name)
{
	t_push	*tmp;

	tmp = list;
	ft_putstr(list_name);
	while (tmp)
	{
		print_data(tmp->nb);
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

void			print_display(t_push *listA, t_push *listB)
{
	print_list(listA, "a: ");
	print_list(listB, "b: ");
	ft_putchar('\n');
}
