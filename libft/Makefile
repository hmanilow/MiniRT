#***************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmanilow <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 14:57:32 by hmanilow          #+#    #+#              #
#    Updated: 2021/10/25 13:18:06 by hmanilow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
#
SRCS =	ft_atoi.c		ft_isalnum.c	ft_isalpha.c	ft_isascii.c	ft_isdigit.c \
		ft_isprint.c	ft_strlen.c		ft_tolower.c	ft_toupper.c    ft_bzero.c \
		ft_memset.c		ft_memcpy.c		ft_memmove.c	ft_memchr.c		ft_memcmp.c \
		ft_strchr.c		ft_strrchr.c	ft_strdup.c		ft_strncmp.c	ft_strlcat.c \
		ft_strlcpy.c	ft_strnstr.c	ft_calloc.c		ft_substr.c		ft_strjoin.c \
		ft_strtrim.c	ft_strmapi.c	ft_striteri.c	ft_putchar_fd.c	ft_putstr_fd.c \
		ft_putendl_fd.c	ft_putnbr_fd.c	ft_itoa.c		ft_split.c
#
HEADER = libft.h
OBJ = $(SRCS:%.c=%.o)
#
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(HEADER)
#
%.o	:	%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@
#
.PHONY	:	all clean fclean re 
#
all	: 	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
		ar rcs $(NAME) $?

clean	:
		@rm -f $(OBJ)

fclean	:	clean
		@$(RM) $(NAME)

re	:	fclean all

norm :
	@norminette -R CheckForbiddenSourceHeader | grep ERROR

