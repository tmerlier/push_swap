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

static void			print_total(t_action *action)
{
	int		i;

	i = -1;
	while (action)
	{
		action = action->next;
		i++;
	}
	ft_putstr("Stack order in: ");
	if (i == 1)
		ft_putstr("One single move...Easy.");
	else
	{
		ft_putnbr(i);
		ft_putstr(" moves.");
	}
}

static void			print_data(int nb, int color)
{
	if (color && options()->c)
	{
		ft_putstr("\033[4;32m");
		ft_putnbr(nb);
		ft_putstr("\033[0m");
	}
	else
		ft_putnbr(nb);
}

void				print_list(t_push *list, char *list_name)
{
	t_push	*tmp;

	tmp = list;
	ft_putstr(list_name);
	while (tmp)
	{
		print_data(tmp->nb, tmp->color);
		if (tmp->next)
			ft_putchar(' ');
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

void				print_display(t_push *lista, t_push *listb)
{
	print_list(lista, "a: ");
	print_list(listb, "b: ");
	ft_putchar('\n');
}

void				print_actions(t_action *action)
{
	t_action	*tmp;

	if (options()->v)
		tmp = action;
	else
		tmp = action->next;
	while (tmp)
	{
		if (options()->v)
		{
			ft_putendl(tmp->action);
			print_display(tmp->lista, tmp->listb);
		}
		else
		{
			ft_putstr(tmp->action);
			if (tmp->next)
				ft_putchar(' ');
		}
		tmp = tmp->next;
	}
	if (options()->v)
		print_total(action);
	ft_putchar('\n');
}
