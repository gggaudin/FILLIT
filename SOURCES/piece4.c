/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 13:56:42 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/08/25 14:42:37 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/fillit.h"

void	piece16(t_visu *v, int x, int y, char c)
{
	mlx_string_put(v->mlx, v->win, x, y, choosecol(c, v), "#");
	mlx_string_put(v->mlx, v->win, x, (y + 15), choosecol(c, v), "# ");
	mlx_string_put(v->mlx, v->win, (x + 15), (y + 15), \
	choosecol(c, v), "#");
	mlx_string_put(v->mlx, v->win, x, (y + 30), choosecol(c, v), "#");
	v->flagpp = 1;
}

void	piece17(t_visu *v, int x, int y, char c)
{
	mlx_string_put(v->mlx, v->win, x, y, choosecol(c, v), "#");
	mlx_string_put(v->mlx, v->win, x, (y + 15), choosecol(c, v), "#");
	mlx_string_put(v->mlx, v->win, (x + 15), (y + 15), \
	choosecol(c, v), "#");
	mlx_string_put(v->mlx, v->win, (x - 15), (y + 15), \
	choosecol(c, v), "#");
	v->flagpp = 1;
}

void	piece18(t_visu *v, int x, int y, char c)
{
	mlx_string_put(v->mlx, v->win, (x + 15), (y - 15), \
	choosecol(c, v), "#");
	mlx_string_put(v->mlx, v->win, (x + 15), y, choosecol(c, v), "#");
	mlx_string_put(v->mlx, v->win, x, y, choosecol(c, v), "# ");
	mlx_string_put(v->mlx, v->win, (x + 15), (y + 15), \
	choosecol(c, v), "#");
	v->flagpp = 1;
}

void	piece19(t_visu *v, int x, int y, char c)
{
	mlx_string_put(v->mlx, v->win, x, y, choosecol(c, v), "#");
	mlx_string_put(v->mlx, v->win, (x + 15), y, choosecol(c, v), "#");
	mlx_string_put(v->mlx, v->win, x, (y + 15), choosecol(c, v), "#");
	mlx_string_put(v->mlx, v->win, (x + 15), (y + 15), \
	choosecol(c, v), "#");
	v->flagpp = 1;
}
