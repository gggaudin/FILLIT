/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggaudin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 10:24:17 by ggaudin-          #+#    #+#             */
/*   Updated: 2017/09/02 13:57:54 by ggaudin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# define BUF_SIZE 20
# define TRUE 1
# define FALSE 0
# include <stdlib.h>
# include "../MINILIBX/mlx.h"
# include "../LIBFT/includes/libft.h"

typedef struct		s_visu
{
	void			*mlx;
	void			*win;
	char			*data;
	void			*img;
	int				bpp;
	int				szline;
	int				endian;
	int				flag1;
	int				flag2;
	int				flagpp;
	int				xpp;
	int				ypp;
	int				color;
	int				endx;
	int				endy;
	int				indexa;
	int				indexb;
	int				index;
	int				len;
	char			**t;
}					t_visu;

typedef struct		s_tetri
{
	char			**tetri;
	char			letter;
	int				x;
	int				y;
	struct s_tetri	*next;
}					t_tetri;

void				putcolgrid1(t_visu *v, int start, int line);
void				putcolgrid2(t_visu *v, int start, int line);
void				putcolgrid3(t_visu *v, int line);
void				putcolgrid4(t_visu *v, int start, int line);
void				putcolgrid(int start, int line, t_visu *v, int h);
void				piece(char **tab, t_visu *v, int nb, int len);
void				letter(t_visu *v);
void				info(t_visu *v, int nb);
void				putingrid(char **tab, t_visu *v);
void				putptborder(t_visu *v, int i);
void				grid2(t_visu *v);
void				grid(t_visu *v);
void				background(t_visu *v);
void				initxypp(t_visu *v);
int					choosecol(char c, t_visu *v);
void				putpiece(char c, int i, int j, t_visu *v);
void				putpiece2(char c, int i, int j, t_visu *v);
void				putpiece3(char c, int i, int j, t_visu *v);
void				piece1(t_visu *v, int x, int y, char c);
void				piece2(t_visu *v, int x, int y, char c);
void				piece3(t_visu *v, int x, int y, char c);
void				piece4(t_visu *v, int x, int y, char c);
void				piece5(t_visu *v, int x, int y, char c);
void				piece6(t_visu *v, int x, int y, char c);
void				piece7(t_visu *v, int x, int y, char c);
void				piece8(t_visu *v, int x, int y, char c);
void				piece9(t_visu *v, int x, int y, char c);
void				piece10(t_visu *v, int x, int y, char c);
void				piece11(t_visu *v, int x, int y, char c);
void				piece12(t_visu *v, int x, int y, char c);
void				piece13(t_visu *v, int x, int y, char c);
void				piece14(t_visu *v, int x, int y, char c);
void				piece15(t_visu *v, int x, int y, char c);
void				piece16(t_visu *v, int x, int y, char c);
void				piece17(t_visu *v, int x, int y, char c);
void				piece18(t_visu *v, int x, int y, char c);
void				piece19(t_visu *v, int x, int y, char c);
int					lentab(char **tab);
void				ft_visurender(int nbtetri, char **tab);
int					ft_checkend(char *str);
int					fillit(int fd, int nbtetri, t_tetri *start, t_tetri *tmp);
int					ft_check(char *tmp);
void				ft_puttab(char **tab);
int					chk_bound(char *tmp);
int					chk_shape(char *tmp);
int					chk_char(char *tmp);
int					chk_void(char *tmp);
int					get_square_size(int nbtetri);
int					place(t_tetri *start, int square_size, char **tab);
int					test_pos(t_tetri *start, char **tab, int square_size);
int					leftmax(char **tab, char letter);
int					upmax(char **tab, char letter);
char				**tabfinal(char **tab, int square_size);
char				**solve(t_tetri	*start, int square_size, char **tab_solved);
char				**suppr(t_tetri *start, char **tab);
char				**placement(t_tetri *start, char **tab);
char				**rnm_fill(char letter, char *tmp);
char				**ft_shift(char **tab, char letter);
char				**shift_left(char **tab, char letter);
char				**shift_up(char **tab, char letter);
char				**uppiece(char **tab, int up, int i, int j);
char				**leftpiece(char **tab, int left);
char				**createtab(char *tmp);
char				*changeletter(char *tmp, char letter);
void				free_tab(char **tab, int tab_size);
t_tetri				*newtetri(char **tetri, char letter);

#endif
