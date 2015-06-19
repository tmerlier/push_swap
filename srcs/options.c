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

#include "push_swap.h"

t_options	*add_options()
{
	t_options	*options;

	options->l = 0;
	return options
}

t_options	*is_options(char **argv, t_option *options)
{
	if (*argv[0] == '-')
	{
		if (*argv[1] == 'l')
		{
			options->l = 1;
			return (1);
		}
	}
	return (0);
}
