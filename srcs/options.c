/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:57:44 by tmerlier          #+#    #+#             */
/*   Updated: 2015/06/26 16:06:09 by tmerlier         ###   ########.fr       */
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
	int		len;
	int		i;

	len = ft_strlen(argv);
	if (argv[0] == '-' && len > 1)
	{
		i = 1;
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
	return (0);
}
