/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 13:28:37 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/08/25 14:41:15 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/fillit.h"

void	piece1(t_visu *v, int x, int y, char c)
{
	mlx_string_put(v->mlx, v->win, x, y, choosecol(c, v), "# # # #");
	v->flagpp = 1;
}

void	piece2(t_visu *v, int x, int y, char c)
{
	mlx_string_put(v->mlx, v->win, x, y, choosecol(c, v), "#");
	mlx_string_put(v->mlx, v->win, x, (y + 15), choosecol(c, v), "#");
	mlx_string_put(v->mlx, v->win, x, (y + 30), choosecol(c, v), "#");
	mlx_string_put(v->mlx, v->win, x, (y + 45), choosecol(c, v), "#");
	v->flagpp = 1;
}

void	piece3(t_visu *v, int x, int y, char c)
{
	mlx_string_put(v->mlx, v->win, x, y, choosecol(c, v), "# ");
	mlx_string_put(v->mlx, v->win, (x + 15), y, choosecol(c, v), "#");
	mlx_string_put(v->mlx, v->win, (x + 15), (y + 15), \
	choosecol(c, v), "# ");
	mlx_string_put(v->mlx, v->win, (x + 30), (y + 15), \
	choosecol(c, v), "#");
	v->flagpp = 1;
}

void	piece4(t_visu *v, int x, int y, char c)
{
	mlx_string_put(v->mlx, v->win, x, y, choosecol(c, v), "#");
	mlx_string_put(v->mlx, v->win, x, (y + 15), choosecol(c, v), "#");
	mlx_string_put(v->mlx, v->win, (x - 15), (y + 15), \
	choosecol(c, v), "# ");
	mlx_string_put(v->mlx, v->win, (x - 15), (y + 30), \
	choosecol(c, v), "#");
	v->flagpp = 1;
}

void	piece5(t_visu *v, int x, int y, char c)
{
	mlx_string_put(v->mlx, v->win, x, y, choosecol(c, v), "# ");
	mlx_string_put(v->mlx, v->win, (x + 15), y, choosecol(c, v), "#");
	mlx_string_put(v->mlx, v->win, (x), (y + 15), \
	choosecol(c, v), "# ");
	mlx_string_put(v->mlx, v->win, (x - 15), (y + 15), \
	choosecol(c, v), "#");
	v->flagpp = 1;
}
