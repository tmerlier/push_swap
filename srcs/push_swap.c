/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:57:44 by tmerlier          #+#    #+#             */
/*   Updated: 2015/06/27 15:52:22 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void		push_swap(t_push *listA)
{
	t_push	*listB;

	if (!(listB = (t_push *) malloc(sizeof(t_push) * checklen(listA))))
		error("Malloc fail.");
	print_display(listA, listB);
	swap_a(&listA);
	print_display(listA, listB);
	push_b(&listA, &listB);
	print_display(listA, listB);
}
