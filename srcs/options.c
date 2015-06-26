/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:57:44 by tmerlier          #+#    #+#             */
/*   Updated: 2015/06/21 12:15:26 by tmerlier         ###   ########.fr       */
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
			error("Malloc fail.");
		glob->r = OFF;
		glob->d = OFF;
	}
	return (glob);
}

int			is_option(char *argv)
{
	if (argv[0] == '-')
	{
		if (argv[1] == 'r')
		{
			options()->r = ON;
			return (1);
		}
	}
	return (0);
}
