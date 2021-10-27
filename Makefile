NAME = bsq

SRCS = main.c ft_filetoarray.c ft_maslen.c ft_final_square.c ft_zeroline1.c ft_zeroline2.c ft_matrix.c ft_output.c

SRCS_D = ./srcs/

CC = gcc

RM = rm -f

OBJS = ${SRCS:.c=.o}

F_OBJS = ${addprefix ${SRCS_D}, ${OBJS}}

F_SRCS = ${addprefix ${SRCS_D}, ${SRCS}}

CFLAGS = -Wall -Wextra -Werror

CCFLAGS = -I./includes/

all:	obj  ${NAME}

obj: ${F_SRCS}

.c.o:
	${CC} ${CFLAGS} ${CCFLAGS} -c $< -o ${<:.c=.o}

${NAME} : ${F_OBJS}
	${CC} ${CFLAGS} ${F_OBJS} -o ${NAME}

clean:
	${RM} ${F_OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re