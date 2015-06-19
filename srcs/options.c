/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:57:44 by tmerlier          #+#    #+#             */
/*   Updated: 2014/04/16 19:03:40 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "push_swap.h"

t_options				*options(void)
{
	static t_options		*glob = NULL;

	if (!glob)
	{
		if (!(glob = ft_memalloc(sizeof(t_options))))
			malloc_error("glob");
		glob->r = OFF
		glob->d = OFF
	}
	return (glob);
}

int			*is_options(char **argv)
{
	if (*argv[0] == '-')
	{
		if (*argv[1] == 'l')
		{
			options()->r = ON;
			return (1);
		}
	}
	return (0);
}
