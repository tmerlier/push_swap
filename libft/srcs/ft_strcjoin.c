/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/21 10:48:53 by tmerlier          #+#    #+#             */
/*   Updated: 2014/04/21 11:48:51 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_strcjoin(char *s1, char *s2, char c)
{
	char	*sout;
	int		lens1;
	int		lens2;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	sout = (char *)malloc(lens1 + lens2 + 2);
	ft_strcpy(sout, s1);
	sout[lens1] = c;
	ft_strcpy(sout + lens1 + 1, s2);
	sout[lens1 + lens2 + 1] = 0;
	return (sout);
}
