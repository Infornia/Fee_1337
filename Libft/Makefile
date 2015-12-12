# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/09 16:17:56 by mwilk             #+#    #+#              #
#    Updated: 2015/06/03 15:56:31 by mwilk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NASM = ~/.brew/Cellar/nasm/2.11.08_1/bin/nasm
NASM_FLAGS = -f macho64
INC_PATH = includes/
OBJ_PATH = obj/
FILES = ft_bzero \
	  ft_atoi ft_itoa ft_cat\
	  ft_isalnum ft_isalpha ft_isascii ft_isblank ft_isdigit \
	  ft_isgraph ft_islower ft_isprint ft_isspace ft_isupper \
	  ft_lstadd ft_lstaddq ft_lstdel ft_lstdelone \
	  ft_lstiter ft_lstlast ft_lstmap ft_lstnew \
	  ft_memalloc ft_memccpy ft_memchr ft_memcmp \
	  ft_memcpy ft_memdel ft_memmove ft_memset \
	  ft_putchar ft_putchar_fd ft_putendl ft_putendl_fd \
	  ft_putnbr ft_putnbr_fd ft_putstr ft_putstr_fd ft_puts \
	  ft_strcat ft_strchr ft_strclr ft_strcmp ft_strcpy \
	  ft_strgroupchar ft_strchartrim \
	  ft_strdel ft_strdup ft_strequ ft_striter ft_striteri \
	  ft_strjoin ft_strlcat ft_strlen ft_strmap ft_strmapi \
	  ft_strncat ft_strncmp ft_strncpy ft_strnequ ft_strnew \
	  ft_strnjoin ft_strnstr ft_strsub \
	  ft_strrchr ft_strsplit ft_strstr \
	  ft_strtrim ft_realloc \
	  ft_tolower ft_toupper \
	  get_next_line \
	  tt_tree_new tt_tree_del tt_tree_h tt_tree_add \
	  tt_tree_iter_ord tt_tree_iter_rev \
	  tt_intlen
OBJ = $(patsubst %, $(OBJ_PATH)%.o, $(FILES))

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "\033[35m <(^.^<) WOW ! Such Library ! Amaze ! (>^o^)> \033[0m"

$(OBJ_PATH)%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_PATH)

$(OBJ_PATH)%.o: %.s
	@$(NASM) $(NASM_FLAGS) $< -o $@

clean:
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\033[36mT.T Miss you object files T.T \033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[36m X.x Bye Bye compiled files >_< \033[0m"

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

re: fclean all

.PHONY: all clean fclean re
