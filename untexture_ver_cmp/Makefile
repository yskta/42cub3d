# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 11:19:11 by yokitaga          #+#    #+#              #
#    Updated: 2023/11/03 01:25:31 by yokitaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRCS_DIR		= ./srcs/
SRCS 			= $(addprefix $(SRCS_DIR),\
			0_main.c		\
			1_check_arg.c		\
			2_read_map.c		\
			3_1_parse_read_data.c \
			3_2_parse_read_data.c \
			3_3_parse_read_data.c \
			4_1_init_other_data.c \
			4_2_init_other_data.c \
			5_key_draw.c \
			6_key_hook.c \
			7_end_program.c \
			8_free_and_destroy.c \
			9_utils.c)

OBJS = $(SRCS:%.c=%.o)

MLX_DIR = ./minilibx-linux
MLX_LIB = -lmlx_Linux -lXext -lX11
MLX_INCLUDE = $(addprefix -I, $(MLX_DIR))

LIB_DIR = ./libft
LIB_LIB = -lft
LIB_INCLUDE = $(addprefix -I, $(LIB_DIR))

all: mlx lib $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(MLX_DIR) $(MLX_LIB) -L$(LIB_DIR) $(LIB_LIB) -lm

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