# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lleiria- <lleiria-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 16:10:22 by lleiria-          #+#    #+#              #
#    Updated: 2022/03/31 12:43:12 by lleiria-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Werror -Wextra -Imlx -g
LMLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -f

$(VERBOSE).SILENT:

LIBFT = ./Libft/libft.a
LIBFT_PATH = ./Libft

FT_PRINTF = ./ft_printf/libftprintf.a
FT_PRINTF_PATH = ./ft_printf

INC = -I ./Libft -I ./includes

SRC_PATH = ./sources

OBJ_PATH = ./objects

SRC_NAME = so_long.c

OBJS = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

all: $(NAME)

$(LIBFT): $(shell make -C $(LIBFT_PATH) -q libft.a || echo force)
	make -C $(LIBFT_PATH)

$(FT_PRINTF): $(shell make -C $(FT_PRINTF_PATH) -q libftprintf.a || echo force)
	make -C $(FT_PRINTF_PATH)

$(NAME) : $(LIBFT) $(FT_PRINTF) $(OBJS)
	make norminette
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) $(LIBFT) $(INC) $(LMLX_FLAGS) -o $(NAME)
	echo "\x1b[36m[SO_LONG COMPILED]\x1b[0m"

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	mkdir -p objects
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

norminette:
	clear
	echo "\x1b[31m[NORMINETTE]\x1b[0m"
	norminette | egrep -B1 'Error|Warning' | sed ''/Error/s//$(printf "\033[31m\033[4mError\033[0m")/'' | sed ''/Warning/s//$(printf "\033[33m\033[4mWarning\033[0m")/''

clean:
	make clean -C $(LIBFT_PATH)
	make clean -C $(FT_PRINTF_PATH)
	rm -rf $(OBJ_PATH)
	echo "\033[33mall $(NAME).o files are removed\033[0m"

fclean: clean
	make fclean -C $(LIBFT_PATH)
	make fclean -C $(FT_PRINTF_PATH)
	rm -f $(NAME)
	echo "\033[31m$(NAME) is deleted\033[0m"

re: fclean all

.PHONY: all clean fclean re force norminette