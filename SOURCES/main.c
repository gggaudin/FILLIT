/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:45:51 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/09/06 19:31:29 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/fillit.h"

t_tetri		*newtetri(char **tetri, char letter)
{
	t_tetri *new;

	new = (t_tetri*)ft_memalloc(sizeof(t_tetri));
	new->tetri = tetri;
	new->letter = letter;
	new->x = 0;
	new->y = 0;
	new->next = NULL;
	return (new);
}

char		**tabfinal(char **tab, int square_size)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	tab = ft_memalloc(sizeof(char*) * square_size + 1);
	while (++i < square_size)
		tab[i] = ft_memalloc(sizeof(char) * square_size + 1);
	i = 0;
	while (j < square_size)
	{
		while (i < square_size)
			tab[j][i++] = '.';
		tab[j][i] = '\0';
		i = 0;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

void		free_tab(char **tab, int tab_size)
{
	int i;

	i = -1;
	while (++i < tab_size)
		ft_strdel(&tab[i]);
	ft_strdel(tab);
}

int			get_square_size(int nbtetri)
{
	int		square_size;
	float	float_nb;

	float_nb = ft_sqrt((float)(nbtetri) * 4.0);
	square_size = (int)float_nb;
	if (square_size == float_nb)
		return (square_size);
	return (square_size);
}

int			main(int ac, char **av)
{
	int		fd;
	int		nbtetri;
	t_tetri	*start;
	t_tetri	*tmp;

	nbtetri = -1;
	start = NULL;
	tmp = NULL;
	if (ac != 2 || (ft_strlen(av[1]) < 8) || \
	(ft_strcmp(&(av[1])[ft_strlen(av[1]) - 7], ".fillit") != 0))
		ft_putendl_fd("usage: ./fillit [file.fillit]\nESC == quit", 2);
	else
	{
		if ((fd = open(av[1], O_RDONLY)) <= 0)
			write(1, "error\n", 6);
		else if (!fillit(fd, nbtetri, start, tmp))
			write(1, "error\n", 6);
		close(fd);
	}
	return (0);
}
