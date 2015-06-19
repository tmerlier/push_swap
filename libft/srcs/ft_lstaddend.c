/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/21 10:50:38 by tmerlier          #+#    #+#             */
/*   Updated: 2014/04/21 10:50:49 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (new)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			tmp = (t_list *)*alst;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
		new->next = NULL;
	}
}
