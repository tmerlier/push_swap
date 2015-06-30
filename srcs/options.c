/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:57:44 by tmerlier          #+#    #+#             */
/*   Updated: 2015/06/27 14:39:48 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "push_swap.h"

static int				option_active()
{
	if (options()->r == ON)
		return (1);
	else if (options()->d == ON)
		return (1);
	else
		return (0);
}

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
	int		active;
	int		len;
	int		i;

	active = 0;
	len = ft_strlen(argv);
	if (len > 2 && argv[1] == '-')
	{
		i = 2;
		while (i < len)
		{
			if (argv[i] == 'r')
				options()->r = ON;
			else if (argv[i] == 'd')
				options()->d = ON;
			else
				error("Option doesn't exist.");
			i++;
		}
	}
	return (option_active());
}
