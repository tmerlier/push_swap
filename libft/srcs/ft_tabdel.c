/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/21 10:46:59 by tmerlier          #+#    #+#             */
/*   Updated: 2014/04/21 11:13:26 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void	ft_tabdel(char ***table)
{
	unsigned int	i;

	i = 0;
	while ((*table)[i])
	{
		ft_strdel(&((*table)[i]));
		i++;
	}
	free(*table);
	*table = NULL;
}
