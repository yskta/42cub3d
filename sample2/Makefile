# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 13:47:31 by snemoto           #+#    #+#              #
#    Updated: 2023/10/23 18:25:46 by snemoto          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# Variables																	   #
# **************************************************************************** #

NAME	= cub3d
SRCS	= $(shell echo *.c)
OBJDIR	= obj/
OBJS	= $(SRCS:%.c=$(OBJDIR)%.o)

CC		= cc
RM		= rm -f
RMD		= rm -rf

CFLAGS	= -Wall -Wextra -Werror -I include -I/usr/X11/include
MLX_PATH = minilibx-linux
MLX_INCLUDE = libmlx_Darwin.a

X11_PATH = -L/usr/X11/include/../lib
X11_INCLUDE = -lX11 -lXext

# **************************************************************************** #
# General Rules																   #
# **************************************************************************** #

all:	$(OBJDIR) $(NAME)

$(OBJDIR):
		mkdir -p obj

$(OBJDIR)%.o: %.c
		$(CC) $(CFLAGS) -c -o $@ $<

# $(NAME): $(OBJS)
# 		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(NAME): ${OBJS}
		cd "$(PWD)/${MLX_PATH}" && make
		${CC} ${CFLAGS} \
			${X11_PATH} ${X11_INCLUDE} \
			$(PWD)/${MLX_PATH}/${MLX_INCLUDE} \
			$(OBJS) \
			-o $(NAME)

clean:
		${RMD} $(OBJDIR)

fclean:	clean
		${RM} ${NAME}

re:		fclean all

bonus:	all

.PHONY: all clean fclean re bonus