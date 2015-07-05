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

	listB = NULL;
	print_display(listA, listB);
	swap_a(&listA);
	print_display(listA, listB);
	push_b(&listA, &listB);
	push_b(&listA, &listB);
	push_b(&listA, &listB);
	print_display(listA, listB);
	rotate_ab(&listA, &listB);
	print_display(listA, listB);
	rev_rotate_ab(&listA, &listB);
	print_display(listA, listB);
	swap_a(&listA);
	print_display(listA, listB);
	push_a(&listA, &listB);
	push_a(&listA, &listB);
	push_a(&listA, &listB);
	print_display(listA, listB);
}
