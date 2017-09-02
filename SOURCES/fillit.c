/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:49:18 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/09/02 12:12:30 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/fillit.h"

void	ft_puttab(char **tab)
{
	int		i;

	i = 0;
	while (i < lentab(tab))
	{
		ft_putendl(tab[i]);
		i++;
	}
}

int		ft_checkend(char *str)
{
	if (str[20] != '\0')
		return (0);
	return (1);
}

int		display(t_tetri *start, int nb, char *buf)
{
	char **res;

	if (!ft_checkend(buf))
		return (0);
	res = solve(start, get_square_size(nb + 1), NULL);
	if (nb >= 10)
		ft_puttab(res);
	else
		ft_visurender(nb, res);
	return (1);
}

int		fillit(int fd, int nbtetri, t_tetri *start, t_tetri *tmp)
{
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	**tab;

	while ((ret = read(fd, buf, (BUF_SIZE + 1))) > 0 && nbtetri++ <= 25)
	{
		buf[ret] = '\0';
		if (!ft_check(buf) || !(tab = rnm_fill(('A' + nbtetri), buf)) \
				|| (('A' + nbtetri) > 'Z'))
			return (0);
		if (('A' + nbtetri) == 'A')
		{
			start = newtetri(tab, ('A' + nbtetri));
			tmp = start;
		}
		else
		{
			tmp->next = newtetri(tab, ('A' + nbtetri));
			tmp = tmp->next;
		}
	}
	display(start, nbtetri, buf);
	return (1);
}
