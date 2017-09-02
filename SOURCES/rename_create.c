/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rename_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:33:37 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/08/25 06:02:10 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/fillit.h"

int		upmax(char **tab, char letter)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			if (tab[i][j] == letter)
				return (i);
			j++;
		}
		j = 0;
		i++;
	}
	return (i);
}

int		leftmax(char **tab, char letter)
{
	int i;
	int j;
	int left;

	i = 0;
	j = 0;
	left = 4;
	while (i < 4)
	{
		while (tab[i][j] != letter && (j < 4))
			j++;
		if (j < left)
			left = j;
		j = 0;
		i++;
	}
	return (left);
}

char	**createtab(char *tmp)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	j = 0;
	k = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * 5)))
		return (NULL);
	while (j < 4)
	{
		if (!(tab[j] = (char*)malloc(sizeof(char) * 5)))
			return (NULL);
		while (tmp[i] != '\n')
			tab[j][k++] = tmp[i++];
		tab[j++][k] = '\0';
		i++;
		k = 0;
	}
	return (tab);
}

char	*changeletter(char *tmp, char letter)
{
	int i;

	i = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '#')
			tmp[i] = letter;
		i++;
	}
	return (tmp);
}

char	**rnm_fill(char letter, char *tmp)
{
	char **tab;
	char *line;

	if (!(line = (char*)malloc(sizeof(char) * 21)))
		return (NULL);
	line = changeletter(tmp, letter);
	tab = createtab(line);
	tab = ft_shift(tab, letter);
	return (tab);
}
