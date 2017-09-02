/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 12:16:12 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/09/02 13:24:18 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/fillit.h"

int		choosecol(char c, t_visu *v)
{
	if (c == 'A')
		return (mlx_get_color_value(v->mlx, 0x00F0A003));
	else if (c == 'B')
		return (mlx_get_color_value(v->mlx, 0x0000EFEE));
	else if (c == 'C')
		return (mlx_get_color_value(v->mlx, 0x000000F0));
	else if (c == 'D')
		return (mlx_get_color_value(v->mlx, 0x00F2F101));
	else if (c == 'E')
		return (mlx_get_color_value(v->mlx, 0x00F00001));
	else if (c == 'F')
		return (mlx_get_color_value(v->mlx, 0x009E00EF));
	else if (c == 'G')
		return (mlx_get_color_value(v->mlx, 0x0002F100));
	else if (c == 'H')
		return (mlx_get_color_value(v->mlx, 0x00C1C1C1));
	else if (c == 'I')
		return (mlx_get_color_value(v->mlx, 0x00b9a485));
	return (mlx_get_color_value(v->mlx, 0x00f0679b));
}

void	putpiece(char c, int i, int j, t_visu *v)
{
	if ((j <= (v->len - 4)) && ((v->t[i][j + 1] == c) && (v->t[i][j + 2] == c)\
	&& (v->t[i][j + 3] == c)))
		piece1(v, v->xpp, v->ypp, c);
	else if (((i + 3) < v->len) && ((v->t[i + 1][j] == c) &&\
	(v->t[i + 2][j] == c) && (v->t[i + 3][j] == c)))
		piece2(v, v->xpp, v->ypp, c);
	else if (((i <= (v->len - 2)) && (j <= (v->len - 3))) &&\
		((v->t[i][j + 1] == c) && (v->t[i + 1][j + 1] == c) &&\
	(v->t[i + 1][j + 2] == c)))
		piece3(v, v->xpp, v->ypp, c);
	else if (((i <= (v->len - 3)) && (j <= (v->len - 1)) && (j >= 1)) && \
(v->t[i + 1][j] == c && v->t[i + 1][j - 1] == c && (v->t[i + 2][j - 1] == c)))
		piece4(v, v->xpp, v->ypp, c);
	else if (((i <= (v->len - 2)) && (j <= (v->len - 3)) && j >= 1) && \
((v->t[i][j + 1] == c) && (v->t[i + 1][j] == c) && (v->t[i + 1][j - 1] == c)))
		piece5(v, v->xpp, v->ypp, c);
	else if (((i <= (v->len - 3)) && (j <= (v->len - 2))) &&\
((v->t[i + 1][j] == c) && (v->t[i + 1][j + 1] == c) &&\
	(v->t[i + 2][j + 1] == c)))
		piece6(v, v->xpp, v->ypp, c);
	else if (((i <= (v->len - 2)) && (j <= (v->len - 3)) &&\
	(v->t[i][j + 1] == c && v->t[i][j + 2] == c && v->t[i + 1][j + 2] == c)))
		piece7(v, v->xpp, v->ypp, c);
	else
		putpiece2(c, i, j, v);
}

void	putpiece2(char c, int i, int j, t_visu *v)
{
	if (((i <= (v->len - 3)) && (j <= (v->len - 2)) && (v->t[i][j + 1] == c && \
					v->t[i + 1][j] == c && v->t[i + 2][j] == c)))
		piece8(v, v->xpp, v->ypp, c);
	else if (((i <= (v->len - 2)) && (j <= (v->len - 3)) &&\
(v->t[i + 1][j] == c && v->t[i + 1][j + 1] == c && v->t[i + 1][j + 2] == c)))
		piece9(v, v->xpp, v->ypp, c);
	else if (((i <= (v->len - 3)) && (j <= (v->len - 1) && (j >= 1)) && \
	(v->t[i + 1][j] == c && v->t[i + 2][j] == c && v->t[i + 2][j - 1] == c)))
		piece10(v, v->xpp, v->ypp, c);
	else if (((i <= (v->len - 2)) && (j <= (v->len - 3)) &&\
	(v->t[i][j + 1] == c && v->t[i][j + 2] == c && v->t[i + 1][j] == c)))
		piece11(v, v->xpp, v->ypp, c);
	else if (((i <= (v->len - 3)) && (j <= (v->len - 2)) &&\
	(v->t[i + 1][j] == c && v->t[i + 2][j] == c && v->t[i + 2][j + 1] == c)))
		piece12(v, v->xpp, v->ypp, c);
	else if ((i <= v->len - 2) && (j <= v->len - 1 && j >= 2) &&\
	(v->t[i + 1][j] == c && v->t[i + 1][j - 1] == c && v->t[i + 1][j - 2] == c))
		piece13(v, v->xpp, v->ypp, c);
	else if (((i <= (v->len - 3)) && (j <= (v->len - 2)) &&\
(v->t[i][j + 1] == c && v->t[i + 1][j + 1] == c && v->t[i + 2][j + 1] == c)))
		piece14(v, v->xpp, v->ypp, c);
	else
		putpiece3(c, i, j, v);
}

void	putpiece3(char c, int i, int j, t_visu *v)
{
	if (((i <= (v->len - 2)) && (j <= (v->len - 3)) && (v->t[i][j + 1] == c && \
					v->t[i][j + 2] == c && v->t[i + 1][j + 1] == c)))
		piece15(v, v->xpp, v->ypp, c);
	else if (((i <= (v->len - 3)) && (j <= (v->len - 2)) &&\
	(v->t[i + 1][j] == c && v->t[i + 1][j + 1] == c && v->t[i + 2][j] == c)))
		piece16(v, v->xpp, v->ypp, c);
	else if (((i <= (v->len - 2)) && (j <= (v->len - 3) && (j >= 1)) && \
(v->t[i + 1][j] == c && v->t[i + 1][j + 1] == c && v->t[i + 1][j - 1] == c)))
		piece17(v, v->xpp, v->ypp, c);
	else if (((i <= (v->len - 3)) && (j <= (v->len - 2) && (j >= 1)) && \
	(v->t[i + 1][j] == c && v->t[i + 2][j] == c && v->t[i + 1][j - 1] == c)))
		piece18(v, v->xpp, v->ypp, c);
	else if (((i <= (v->len - 2)) && (j <= (v->len - 2))) &&\
	(v->t[i][j + 1] == c && v->t[i + 1][j] == c && v->t[i + 1][j + 1] == c))
		piece19(v, v->xpp, v->ypp, c);
}

void	initxypp(t_visu *v)
{
	v->flag1++;
	if (v->flag1 % 2 == 0)
		v->xpp += 160;
	else
	{
		v->xpp = 950;
		v->ypp += 125;
	}
}
