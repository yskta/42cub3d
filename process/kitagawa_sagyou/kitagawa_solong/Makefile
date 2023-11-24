# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 22:44:52 by yokitaga          #+#    #+#              #
#    Updated: 2023/01/21 15:45:23 by yokitaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR		= ./srcs/
SRCS 			= $(addprefix $(SRCS_DIR),\
			0_main.c		\
			1_check_arg.c		\
			2_read_map.c		\
			3_init_map.c	\
			4_1_parse_map.c	\
			4_2_parse_map.c		\
			4_3_parse_map.c	\
			5_init_other_data.c		\
			6_render_map.c		\
			7_key_action.c		\
			8_end_game.c 		\
			9_free.c			\
			10_put_error_and_exit.c)

OBJS = $(SRCS:%.c=%.o)

MLX_DIR = ./minilibx-linux
MLX_LIB = -lmlx_Linux -lXext -lX11
MLX_INCLUDE = $(addprefix -I, $(MLX_DIR))

LIB_DIR = ./library
LIB_LIB = -lft
LIB_INCLUDE = $(addprefix -I, $(LIB_DIR))

all: mlx lib $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(MLX_DIR) $(MLX_LIB) -L$(LIB_DIR) $(LIB_LIB)

%.o:	%.c
	$(CC) $(CFLAGS) -c $(MLX_INCLUDE) $(LIB_INCLUDE) $< -o $@

mlx:
	make -C $(MLX_DIR)

lib:
	make -C $(LIB_DIR)

clean:
	make clean -C $(LIB_DIR)
	rm -r $(OBJS)

fclean: clean
	rm -r $(NAME)

re: fclean all
