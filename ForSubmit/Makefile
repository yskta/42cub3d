# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 11:19:11 by yokitaga          #+#    #+#              #
#    Updated: 2023/12/03 17:08:50 by yokitaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRCS_DIR		= ./srcs/
SRCS 			= $(addprefix $(SRCS_DIR),\
			0_main.c		\
			1_check_arg.c		\
			2_read_map.c		\
			3_0_parse_read_data.c \
			3_1_parse_read_data.c \
			3_2_parse_read_data.c \
			3_3_parse_read_data.c \
			3_4_parse_read_data.c \
			3_5_parse_read_data.c \
			3_6_parse_read_data.c \
			3_7_parse_read_data.c \
			4_1_init_other_data.c \
			4_2_init_other_data.c \
			5_raycaster_draw.c \
			5_raycaster_draw_calc.c \
			5_raycaster_draw_tex.c \
			6_key_hook.c \
			7_end_program.c \
			8_1_free_and_destroy.c \
			8_2_free_and_destroy.c \
			9_utils.c)

OBJS = $(SRCS:%.c=%.o)
OS := $(shell uname -s)

ifeq ($(OS),Linux)
	MLX_DIR = ./minilibx-linux
	MLX_LIB = -lmlx_Linux -lXext -lX11
	MLX_INCLUDE = $(addprefix -I, $(MLX_DIR))
endif

ifeq ($(OS),Darwin)
	CFLAGS += -I/usr/X11/include
	MLX_DIR = ./minilibx-linux
	MLX_LIB = minilibx-linux/libmlx_Darwin.a
	X11_DIR = /usr/X11/include/../lib
	X11_LIB = -lXext -lX11
	X11_INCLUDE = $(addprefix -I, $(X11_DIR))
endif

LIB_DIR = ./libft
LIB_LIB = -lft
LIB_INCLUDE = $(addprefix -I, $(LIB_DIR))

all: mlx lib $(NAME)

$(NAME): $(OBJS)
ifeq ($(OS),Linux)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(MLX_DIR) $(MLX_LIB) -L$(LIB_DIR) $(LIB_LIB) -lm
else
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(X11_DIR) $(X11_LIB) -L$(MLX_DIR) $(MLX_LIB) -L$(LIB_DIR) $(LIB_LIB) -lm
endif

%.o:	%.c
	$(CC) $(CFLAGS) -c $(X11_INCLUDE) $(MLX_INCLUDE) $(LIB_INCLUDE) $< -o $@

mlx:
	make -C $(MLX_DIR)

lib:
	make -C $(LIB_DIR)

clean:
	make fclean -C $(LIB_DIR)
	rm -r $(OBJS)

fclean: clean
	rm -r $(NAME)

re: fclean all