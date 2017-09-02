/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 18:00:55 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/09/02 14:19:36 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/fillit.h"

void		creaindex(t_visu *v, char **tab)
{
	background(v);
	grid(v);
	grid2(v);
	putingrid(tab, v);
}

int			lentab(char **tab)
{
	int i;

	i = 0;
	while (tab[0][i] != '\0')
	{
		i++;
	}
	return (i);
}

int			ft_keyhook(int key)
{
	if (key == 53)
	{
		ft_putendl("FILLIT//ggaudin-");
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void		border(t_visu *v, int len)
{
	int i;
	int j;

	i = 50;
	v->endx = 150 + (60 * len);
	v->endy = 50 + (60 * len);
	v->color = mlx_get_color_value(v->mlx, 0x00FF0065);
	while (i <= v->endy)
	{
		j = 150;
		if ((i == 50) || (i == v->endy))
		{
			while (j <= v->endx)
			{
				v->indexa = (j * (v->bpp / 8)) + (i * 4800);
				v->data[v->indexa] = (char)v->color;
				v->data[v->indexa + 1] = (char)(v->color >> 8);
				v->data[v->indexa + 2] = (char)(v->color >> 16);
				j++;
			}
		}
		else
			putptborder(v, i);
		i++;
	}
}

void		ft_visurender(int nbtetri, char **tab)
{
	t_visu	*v;

	v = (t_visu*)ft_memalloc(sizeof(t_visu));
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, 1200, 700, "FILLIT");
	v->img = mlx_new_image(v->mlx, 1200, 700);
	v->data = mlx_get_data_addr(v->img, &v->bpp, &v->szline, &v->endian);
	v->flag1 = 1;
	v->xpp = 950;
	v->ypp = 120;
	v->t = tab;
	v->len = lentab(v->t);
	creaindex(v, v->t);
	border(v, v->len);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	info(v, nbtetri);
	letter(v);
	piece(v->t, v, (nbtetri + 1), v->len);
	mlx_string_put(v->mlx, v->win, 300, 660, 0x00FEFEFE, \
	"Le plus petit carre est de ");
	mlx_string_put(v->mlx, v->win, 570, 660, 0x00FEFEFE, ft_itoa(v->len));
	mlx_string_put(v->mlx, v->win, 585, 660, 0x00FEFEFE, "x");
	mlx_string_put(v->mlx, v->win, 600, 660, 0x00FEFEFE, ft_itoa(v->len));
	mlx_hook(v->win, 2, 0, (int (*)())ft_keyhook, v);
	mlx_loop(v->mlx);
}
