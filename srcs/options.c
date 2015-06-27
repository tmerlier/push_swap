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
	if (len > 1)
	{
		ft_putendl("coucou");
		i = 1;
		while (i < len)
		{
			if (argv[i] == 'r')
				options()->r = ON;
			else if (argv[i] == 'd')
				options()->d = ON;
			else if (argv[i] >= 48 && argv[i] <= 57)
				return (0);
			else
				error("Option doesn't exist.");
			i++;
			ft_putendl("continu");
		}
	}
	return (0);
}
