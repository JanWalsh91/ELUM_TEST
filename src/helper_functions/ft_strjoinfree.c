/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:32:36 by jwalsh            #+#    #+#             */
/*   Updated: 2017/08/12 14:07:51 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lceb.h"

/*
** Concatenates s1 and s2 in a new string which was allocated enough memory
** with malloc. Returns a pointer to that new string.
** Frees s1 if c = l, s2 if c = r, and both if c = b or neither is c equals
** anything else.
*/

char	*ft_strjoinfree(char const *s1, char const *s2, char c)
{
	char	*newstr;

	newstr = ft_strjoin(s1, s2);
	if ((c == 'l' || c == 'b') && s1 != NULL) {
		free((char *)s1);
	}
	if ((c == 'r' || c == 'b') && s2 != NULL) {
		free((char *)s2);
	}
	return (newstr);
}