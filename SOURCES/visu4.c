/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 12:30:55 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/09/06 22:38:21 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/fillit.h"

void		putptborder(t_visu *v, int i)
{
	v->indexa = (150 * (v->bpp / 8)) + (i * 4800);
	v->indexb = (v->endx * (v->bpp / 8)) + (i * 4800);
	v->data[v->indexa] = (char)v->color;
	v->data[v->indexa + 1] = (char)(v->color >> 8);
	v->data[v->indexa + 2] = (char)(v->color >> 16);
	v->data[v->indexb] = (char)v->color;
	v->data[v->indexb + 1] = (char)(v->color >> 8);
	v->data[v->indexb + 2] = (char)(v->color >> 16);
}

void		grid2(t_visu *v)
{
	int start;
	int line;
	int i;
	int h;
	int j;

	start = 150;
	line = 50;
	i = 0;
	h = 0;
	j = 0;
	v->color = mlx_get_color_value(v->mlx, 0x00FEFEFE);
	while (i <= 600)
	{
		if (i % 60 == 0)
			putcolgrid(start, line, v, h);
		else
			putcolgrid3(v, line);
		j = 0;
		start = 150;
		i++;
		line++;
	}
}

void		grid(t_visu *v)
{
	int line;
	int start;

	line = 89;
	start = 1050;
	v->color = mlx_get_color_value(v->mlx, 0x00010101);
	while (++line < 700)
	{
		v->index = (start * (v->bpp / 8)) + (line * 4800);
		v->data[v->index] = (char)v->color;
		v->data[v->index + 1] = (char)(v->color >> 8);
		v->data[v->index + 2] = (char)(v->color >> 16);
	}
	line = 196;
	start = 900;
	while (line < 700)
	{
		putcolgrid4(v, start, line);
		start++;
		if ((start * (v->bpp / 8)) >= 4800)
		{
			start = 900;
			line += 126;
		}
	}
}

void		info(t_visu *v, int nb)
{
	mlx_string_put(v->mlx, v->win, 1025, 15, 0x001E2A7D, "FILLIT");
	mlx_string_put(v->mlx, v->win, 900, 30, 0x001E2A7D,\
	"------------------------------");
	mlx_string_put(v->mlx, v->win, 930, 50, 0x001E2A7D,\
	"Number of TETRIMINOS : ");
	mlx_string_put(v->mlx, v->win, 1160, 50, 0x001E2A7D, (ft_itoa(nb + 1)));
}

void		background(t_visu *v)
{
	int start;
	int line;
	int color;

	line = 0;
	start = 900;
	color = mlx_get_color_value(v->mlx, 0x00F9FE6B);
	while ((((start * (v->bpp / 8)) + (line * 4800)) < (4800 + (line * 4800)))\
	&& (line < 700))
	{
		v->data[(start * (v->bpp / 8)) + (line * 4800)] = (char)color;
		v->data[((start * (v->bpp / 8)) +\
	(line * 4800)) + 1] = (char)(color >> 8);
		v->data[((start * (v->bpp / 8)) +\
	(line * 4800)) + 2] = (char)(color >> 16);
		start++;
		if (start >= 1200)
		{
			start = 900;
			line++;
		}
	}
}
