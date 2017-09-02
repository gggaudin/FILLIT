/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnbelem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 09:37:18 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/09/02 12:09:03 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_strnbelem(const char *s, const char sep)
{
	ssize_t	i;

	i = 0;
	while (*s != '\0')
	{
		if (*s != sep)
		{
			i++;
			while (*s != sep && *s != '\0')
				s++;
		}
		else if (*s == sep)
		{
			while (*s == sep && *s != '\0')
				s++;
		}
	}
	return (i);
}
