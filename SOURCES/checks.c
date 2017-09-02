/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 10:34:10 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/08/25 13:09:25 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/fillit.h"

int	chk_char(char *tmp)
{
	int i;
	int shap;

	i = 0;
	shap = 0;
	if (tmp[0] != '.' && tmp[0] != '#')
		return (FALSE);
	while (i <= 19)
	{
		if (tmp[i] != '.' && tmp[i] != '#' && tmp[i] != '\n' && tmp[i] != '\0')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	chk_shape(char *tmp)
{
	int i;
	int dot;
	int hash;
	int endl;

	i = 0;
	dot = 0;
	hash = 0;
	endl = 0;
	while (i <= 19)
	{
		if (tmp[i] == '.')
			dot++;
		else if (tmp[i] == '#')
			hash++;
		else if (tmp[i] == '\n')
			endl++;
		i++;
	}
	if (dot != 12 || hash != 4 || endl != 4)
		return (FALSE);
	return (TRUE);
}

int	chk_void(char *tmp)
{
	int i;
	int h;
	int bug;

	bug = 0;
	i = 0;
	h = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '#')
			h++;
		if (h == 2 && tmp[i] == '#')
		{
			while (tmp[i + 1 + bug] != '#' && tmp[i + bug] != '\0')
				bug++;
			if (bug >= 5)
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int	chk_bound(char *tmp)
{
	int i;
	int bound;

	i = 0;
	bound = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '#')
		{
			if (tmp[i + 1] == '#')
				bound++;
			if (tmp[i + 5] == '#')
				bound++;
		}
		i++;
	}
	if (bound >= 3 && bound <= 4)
		return (TRUE);
	return (FALSE);
}

int	ft_check(char *tmp)
{
	if (!chk_char(tmp) || !chk_shape(tmp) || !chk_bound(tmp) \
			|| !chk_void(tmp))
		return (FALSE);
	return (TRUE);
}
