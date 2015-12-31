# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/09 16:17:56 by mwilk             #+#    #+#              #
#    Updated: 2015/12/12 17:32:44 by mwilk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fillit

CFLAGS = -Wall -Wextra -Werror

OBJ_PATH = ./obj/
SRC_PATH = ./

OBJ = $(SRC:.c=.o)
SRC = main.c fee_1337.c fee_error.c fee_utils.c fee_blocks_get.c fee_tetri.c \
		tt_functions.c fee_tetri_help.c fee_pattern.c fee_check.c fee_write.c \
		check_pattern.c \

OBJS = $(addprefix $(OJB_PATH),$(OBJ))
SRCS = $(addprefix $(SRC_PATH),$(SRC))

FEE_H = -I ./

LIB_H = -I Libft/includes/
LIB_L = -LLibft -lft

all: ml normal

ml:
		@make -C Libft

mrl:
		@make -C libft re

mcl:
		@make -C libft clean

mfl:
		@make -C libft fclean

normal: clean $(NAME)

$(NAME):
	@gcc -g $(CFLAGS) $(LIB_H) $(FEE_H) -c $(SRCS) 
	@mkdir $(OBJ_PATH)
	@gcc -o $(NAME) $(OBJ) $(LIB_L)
	@mv $(OBJ) $(OBJ_PATH)
	@echo "\033[35m <(O.O<) WOW ! Very Fee_1337 ! Amaze ! (>^o^)> \033[0m"

clean:
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\033[36mT.T Miss you object files T.T \033[0m"

fclean: clean
	@/bin/rm $(NAME)
	@echo "\033[36m X.x Bye Bye compiled files >_< \033[0m"

re: fclean all

.PHONY: all normal clean fclean re ml mrl mcl mfl

