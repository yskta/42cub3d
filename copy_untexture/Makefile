# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 13:47:31 by snemoto           #+#    #+#              #
#    Updated: 2023/11/19 02:14:32 by yokitaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# Variables																	   #
# **************************************************************************** #

NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRCS_DIR		= ./srcs/
SRCS 			= $(addprefix $(SRCS_DIR),\
			main.c		\
			raycaster_draw.c		\
			raycaster_hook.c)

OBJS = $(SRCS:%.c=%.o)

MLX_DIR = ./minilibx-linux
MLX_LIB = -lmlx_Linux -lXext -lX11
MLX_INCLUDE = $(addprefix -I, $(MLX_DIR))

# **************************************************************************** #
# General Rules																   #
# **************************************************************************** #

all: mlx $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(MLX_DIR) $(MLX_LIB) -lm

%.o:	%.c
	$(CC) $(CFLAGS) -c $(MLX_INCLUDE) $< -o $@

mlx:
	make -C $(MLX_DIR)

clean:
	make clean -C $(LIB_DIR)
	rm -r $(OBJS)

fclean: clean
	rm -r $(NAME)

re: fclean all