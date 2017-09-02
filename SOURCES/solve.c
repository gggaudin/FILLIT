/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:25:55 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/08/25 06:02:19 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/fillit.h"

int		test_pos(t_tetri *start, char **tab, int square_size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if ((start->tetri[i][j] >= 'A' && start->tetri[i][j] <= 'Z') && \
					(start->x + j >= square_size \
						|| start->y + i >= square_size))
				return (0);
			if ((start->tetri[i][j] >= 'A' && start->tetri[i][j] <= 'Z') && \
					ft_isalpha(tab[start->y + i][start->x + j]) == 1)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

char	**placement(t_tetri *start, char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (start->tetri[i][j] >= 'A' && start->tetri[i][j] <= 'Z')
				tab[start->y + i][start->x + j] = start->letter;
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}

char	**suppr(t_tetri *start, char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == start->letter)
				tab[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}

int		place(t_tetri *start, int square_size, char **tab)
{
	if (start != NULL)
	{
		while ((start->y * start->x) < (square_size * square_size))
		{
			if ((test_pos(start, tab, square_size)) == 1)
			{
				tab = placement(start, tab);
				if (place(start->next, square_size, tab) == 1)
					return (1);
				tab = suppr(start, tab);
			}
			if (start->x < square_size)
				start->x++;
			else
			{
				start->x = 0;
				start->y++;
			}
		}
		start->x = 0;
		start->y = 0;
		return (0);
	}
	return (1);
}

char	**solve(t_tetri *start, int square_size, char **tab_solved)
{
	tab_solved = tabfinal(tab_solved, square_size);
	while (place(start, square_size, tab_solved) == 0)
	{
		square_size++;
		start->x = 0;
		start->y = 0;
		free_tab(tab_solved, square_size);
		tab_solved = tabfinal(tab_solved, square_size);
	}
	return (tab_solved);
}
