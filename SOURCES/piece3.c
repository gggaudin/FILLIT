/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 13:48:52 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/09/02 12:14:39 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/fillit.h"

void	piece11(t_visu *v, int x, int y, char c)
{
	mlx_string_put(v->mlx, v->win, x, y, choosecol(c, v), "# ");
	mlx_string_put(v->mlx, v->win, (x + 15), y, choosecol(c, v), "# ");
	mlx_string_put(v->mlx, v->win, (x + 30), y, choosecol(c, v), "#");
	mlx_string_put(v->mlx, v->win, x, (y + 15), choosecol(c, v), "#");
	v->flagpp = 1;
}

void	piece12(t_visu *v, int x, int y, char c)
{
	mlx_string_put(v->mlx, v->win, x, y, choosecol(c, v), "#");
	mlx_string_put(v->mlx, v->win, x, (y + 15), choosecol(c, v), "#");
	mlx_string_put(v->mlx, v->win, x, (y + 30), choosecol(c, v), "#");
	mlx_string_put(v->mlx, v->win, (x + 15), (y + 30), \
	choosecol(c, v), "#");
	v->flagpp = 1;
}

void	piece13(t_visu *v, int x, int y, char c)
{
	mlx_string_put(v->mlx, v->win, (x + 30), y, choosecol(c, v), "#");
	mlx_string_put(v->mlx, v->win, (x + 30), (y + 15), \
	choosecol(c, v), "#");
	mlx_string_put(v->mlx, v->win, (x + 15), (y + 15), \
	choosecol(c, v), "#");
	mlx_string_put(v->mlx, v->win, x, (y + 15), choosecol(c, v), "#");
	v->flagpp = 1;
}

void	piece14(t_visu *v, int x, int y, char c)
{
	mlx_string_put(v->mlx, v->win, x, y, choosecol(c, v), "#");
	mlx_string_put(v->mlx, v->win, (x + 15), y, choosecol(c, v), "#");
	mlx_string_put(v->mlx, v->win, (x + 15), (y + 15), \
	choosecol(c, v), "#");
	mlx_string_put(v->mlx, v->win, (x + 15), (y + 30), \
	choosecol(c, v), "#");
	v->flagpp = 1;
}

void	piece15(t_visu *v, int x, int y, char c)
{
	mlx_string_put(v->mlx, v->win, x, y, choosecol(c, v), "# ");
	mlx_string_put(v->mlx, v->win, (x + 15), y, choosecol(c, v), "# ");
	mlx_string_put(v->mlx, v->win, (x + 30), y, choosecol(c, v), "#");
	mlx_string_put(v->mlx, v->win, (x + 15), (y + 15), \
	choosecol(c, v), "# ");
	v->flagpp = 1;
}
