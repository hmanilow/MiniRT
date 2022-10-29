NAME := libgnl.a

HDRS = get_next_line.h
SRCS := get_next_line.c get_next_line_utils.c
OBJS = 	${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

.PHONY: gnl clean fclean re norm

gnl: ${NAME}

$(NAME): ${OBJS}
	ar rcs ${NAME} $?

${OBJS}:${HDRS}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
