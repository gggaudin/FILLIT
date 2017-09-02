# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcaron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/01 11:55:44 by fcaron            #+#    #+#              #
#*   Updated: 2017/01/18 19:14:22 by ggaudin-         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_PATH = SOURCES/

SRC = main.c\
      piece1.c\
	  visu2.c\
	  visu3.c\
	  visu4.c\
	  visu5.c\
	  piece2.c\
	  piece3.c\
	  piece4.c\
	  checks.c\
	  arrange.c\
	  rename_create.c\
	  solve.c\
	  fillit.c\
	  visu.c

FLAGS = -Wall -Wextra -Werror -Ofast -O2 -O3

OBJ = $(SRC:.c=.o)

RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

INC = -I ./INCLUDE -I ./LIBFT/

LIB = -L MINILIBX -lmlx -framework OpenGL -framework Appkit -L ./LIBFT/ -lft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C LIBFT/
	@$(CC) $(OBJ) $(INC) $(LIB) -o $(NAME)
	@echo "$(GREEN)[✓] FILLIT: READY!$(NC)"

%.o: $(SRC_PATH)%.c
	@gcc -c  $(FLAGS) $< -o $@ $(INC)

clean:
	@rm -f $(OBJ)
	@echo "$(RED)[-] FILLIT:	SUPPRESSION DES FICHIERS OBJETS.$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)[-] FILLIT:	SUPPRESSION DE LA LIBRAIRIE.$(NC)"
	@make fclean -C ./LIBFT/

re: fclean all

.PHONY : all re clean fclean
