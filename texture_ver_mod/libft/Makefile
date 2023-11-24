# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/14 15:28:41 by yokitaga          #+#    #+#              #
#    Updated: 2023/10/20 11:34:38 by yokitaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a 
SRCS		=  ft_split.c ft_strchr.c ft_strdup.c \
				ft_strlcpy.c ft_strlen.c ft_substr.c \
				ft_atoi.c ft_strncmp.c ft_isdigit.c get_next_line.c

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
OBJS		= $(SRCS:%.c=%.o)

all:		$(NAME)
$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)
%.o : %.c
			$(CC) $(CFLAGS) -c $?
		
clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re