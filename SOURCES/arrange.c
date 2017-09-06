/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:00:44 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/09/06 19:37:24 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/fillit.h"

char	**leftpiece(char **tab, int left)
{
	int i;
	int j;
	int index;

	i = 0;
	while (i < 4)
	{
		j = 0;
		index = left;
		while (index < 4)
		{
			tab[i][j] = tab[i][index];
			j++;
			index++;
		}
		while (j < 4)
		{
			tab[i][j] = '.';
			j++;
		}
		i++;
	}
	return (tab);
}

char	**uppiece(char **tab, int up, int i, int j)
{
	while (up < 4)
	{
		while (j < 4)
		{
			tab[i][j] = tab[up][j];
			j++;
		}
		j = 0;
		up++;
		i++;
	}
	while (tab[i] != '\0' && i < 4)
	{
		tab[i][j] = '.';
		j++;
		if (j > 3)
		{
			j = 0;
			i++;
		}
	}
	return (tab);
}

char	**shift_up(char **tab, char letter)
{
	int up;

	up = upmax(tab, letter);
	if (up == 0)
		return (tab);
	return (uppiece(tab, up, 0, 0));
}

char	**shift_left(char **tab, char letter)
{
	int left;

	left = leftmax(tab, letter);
	if (left == 0)
		return (tab);
	return (leftpiece(tab, left));
}

char	**ft_shift(char **tab, char letter)
{
	shift_up(tab, letter);
	shift_left(tab, letter);
	return (tab);
}
