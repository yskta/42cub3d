# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 19:38:29 by yokitaga          #+#    #+#              #
#    Updated: 2023/01/18 10:23:58 by yokitaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a 
SRCS		= ft_atoi.c ft_bzero.c ft_calloc.c \
				ft_isalnum.c ft_isalpha.c ft_isascii.c \
				ft_isdigit.c ft_isprint.c ft_itoa.c \
				ft_memchr.c ft_memcmp.c ft_memcpy.c \
				ft_memmove.c ft_memset.c ft_putchar_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
				ft_split.c ft_strchr.c ft_strdup.c \
				ft_striteri.c ft_strjoin.c ft_strlcat.c \
				ft_strlcpy.c ft_strlen.c ft_strmapi.c \
				ft_strncmp.c ft_strnstr.c ft_strrchr.c  \
				ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
				ft_printf_csdi.c ft_printf_hex.c ft_printf_pointer.c \
				ft_printf_unsigned.c ft_printf.c ft_free_for_gnl.c \
				get_next_line.c

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