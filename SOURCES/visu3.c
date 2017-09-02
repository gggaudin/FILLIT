/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 12:29:00 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/09/02 13:09:54 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/fillit.h"

void		piece(char **tab, t_visu *v, int nb, int len)
{
	int n;
	int i;
	int j;

	n = -1;
	while (++n < nb)
	{
		v->flagpp = 0;
		i = -1;
		while (++i < len)
		{
			j = -1;
			while (++j < len)
			{
				if ((tab[i][j] == 'A' + n) && v->flagpp == 0)
					putpiece(('A' + n), i, j, v);
			}
			if (tab[i][j] == 'A' + n)
				break ;
		}
		initxypp(v);
	}
}

void		putcolor(t_visu *v, char c, int x, int y)
{
	int i;
	int j;
	int index;
	int start;

	i = 0;
	v->color = choosecol(c, v);
	while (i <= 58)
	{
		j = 0;
		start = x;
		while (j <= 58)
		{
			index = (start * (v->bpp / 8)) + (y * 4800);
			v->data[index] = (char)v->color;
			v->data[index + 1] = (char)(v->color >> 8);
			v->data[index + 2] = (char)(v->color >> 16);
			start++;
			j++;
		}
		y++;
		i++;
	}
}

void		putingrid(char **tab, t_visu *v)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	x = 151;
	y = 51;
	while (tab[i] != '\0')
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (ft_isalpha(tab[i][j]) != 0)
				putcolor(v, tab[i][j], x, y);
			x += 60;
			j++;
		}
		x = 151;
		y += 60;
		i++;
	}
}

void		letter2(t_visu *v)
{
	mlx_string_put(v->mlx, v->win, 910, 87, 0x001E2A7D, "A");
	mlx_string_put(v->mlx, v->win, 910, 213, 0x001E2A7D, "C");
	mlx_string_put(v->mlx, v->win, 910, 339, 0x001E2A7D, "E");
	mlx_string_put(v->mlx, v->win, 910, 468, 0x001E2A7D, "G");
	mlx_string_put(v->mlx, v->win, 910, 594, 0x001E2A7D, "I");
	mlx_string_put(v->mlx, v->win, 1060, 87, 0x001E2A7D, "B");
	mlx_string_put(v->mlx, v->win, 1060, 213, 0x001E2A7D, "D");
	mlx_string_put(v->mlx, v->win, 1060, 339, 0x001E2A7D, "F");
	mlx_string_put(v->mlx, v->win, 1060, 468, 0x001E2A7D, "H");
	mlx_string_put(v->mlx, v->win, 1060, 594, 0x001E2A7D, "J");
}

void		letter(t_visu *v)
{
	mlx_string_put(v->mlx, v->win, 175, 30, 0x00FEFEFE, "1");
	mlx_string_put(v->mlx, v->win, 235, 30, 0x00FEFEFE, "2");
	mlx_string_put(v->mlx, v->win, 295, 30, 0x00FEFEFE, "3");
	mlx_string_put(v->mlx, v->win, 355, 30, 0x00FEFEFE, "4");
	mlx_string_put(v->mlx, v->win, 415, 30, 0x00FEFEFE, "5");
	mlx_string_put(v->mlx, v->win, 475, 30, 0x00FEFEFE, "6");
	mlx_string_put(v->mlx, v->win, 535, 30, 0x00FEFEFE, "7");
	mlx_string_put(v->mlx, v->win, 595, 30, 0x00FEFEFE, "8");
	mlx_string_put(v->mlx, v->win, 655, 30, 0x00FEFEFE, "9");
	mlx_string_put(v->mlx, v->win, 710, 30, 0x00FEFEFE, "10");
	mlx_string_put(v->mlx, v->win, 135, 70, 0x00FEFEFE, "1");
	mlx_string_put(v->mlx, v->win, 135, 130, 0x00FEFEFE, "2");
	mlx_string_put(v->mlx, v->win, 135, 190, 0x00FEFEFE, "3");
	mlx_string_put(v->mlx, v->win, 135, 250, 0x00FEFEFE, "4");
	mlx_string_put(v->mlx, v->win, 135, 310, 0x00FEFEFE, "5");
	mlx_string_put(v->mlx, v->win, 135, 370, 0x00FEFEFE, "6");
	mlx_string_put(v->mlx, v->win, 135, 430, 0x00FEFEFE, "7");
	mlx_string_put(v->mlx, v->win, 135, 490, 0x00FEFEFE, "8");
	mlx_string_put(v->mlx, v->win, 135, 550, 0x00FEFEFE, "9");
	mlx_string_put(v->mlx, v->win, 125, 610, 0x00FEFEFE, "10");
	letter2(v);
}
