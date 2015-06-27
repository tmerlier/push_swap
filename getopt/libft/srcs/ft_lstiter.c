/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbernand <rbernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 15:38:15 by rbernand          #+#    #+#             */
/*   Updated: 2013/12/03 16:57:31 by rbernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (f)
	{
		while (lst)
		{
			f(lst);
			lst = lst->next;
		}
	}
}