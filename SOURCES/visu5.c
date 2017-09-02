/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 13:32:16 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/09/02 14:18:43 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/fillit.h"

void	putcolgrid1(t_visu *v, int start, int line)
{
	v->index = (start * (v->bpp / 8)) + (line * 4800);
	v->data[v->index] = (char)v->color;
	v->data[v->index + 1] = (char)(v->color >> 8);
	v->data[v->index + 2] = (char)(v->color >> 16);
}

void	putcolgrid2(t_visu *v, int start, int line)
{
	if (line <= 650)
	{
		v->index = (start * (v->bpp / 8)) + (line * 4800);
		v->data[v->index] = (char)v->color;
		v->data[v->index + 1] = (char)(v->color >> 8);
		v->data[v->index + 2] = (char)(v->color >> 16);
	}
}

void	putcolgrid3(t_visu *v, int line)
{
	v->indexa = (150 * (v->bpp / 8)) + (line * 4800);
	v->indexb = (750 * (v->bpp / 8)) + (line * 4800);
	v->data[v->indexa] = (char)v->color;
	v->data[v->indexb] = (char)v->color;
	v->data[v->indexa + 1] = (char)(v->color >> 8);
	v->data[v->indexb + 1] = (char)(v->color >> 8);
	v->data[v->indexa + 2] = (char)(v->color >> 16);
	v->data[v->indexb + 2] = (char)(v->color >> 16);
}

void	putcolgrid4(t_visu *v, int start, int line)
{
	v->index = (start * (v->bpp / 8)) + (line * 4800);
	v->indexa = (start * (v->bpp / 8)) + ((line - 1) * 4800);
	v->indexb = (start * (v->bpp / 8)) + ((line + 1) * 4800);
	v->data[v->index] = (char)(v->color);
	v->data[v->index + 1] = (char)(v->color >> 8);
	v->data[v->index + 2] = (char)(v->color >> 16);
	v->data[v->indexa] = (char)(v->color);
	v->data[v->indexa + 1] = (char)(v->color >> 8);
	v->data[v->indexa + 2] = (char)(v->color >> 16);
	v->data[v->indexb] = (char)(v->color);
	v->data[v->indexb + 1] = (char)(v->color >> 8);
	v->data[v->indexb + 2] = (char)(v->color >> 16);
}

void	putcolgrid(int start, int line, t_visu *v, int h)
{
	int j;

	j = -1;
	while (++j <= 600)
	{
		putcolgrid1(v, start, line);
		start++;
	}
	start = 150;
	j = -1;
	while (++j <= 600 && v->flag2 == 0)
	{
		if (j % 60 == 0)
		{
			while (h <= 600)
			{
				putcolgrid2(v, start, line);
				line++;
				h++;
			}
			h = 0;
			line = 50;
		}
		start++;
	}
}
