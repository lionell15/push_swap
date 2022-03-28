NAME	=	push_swap
SRCS	=	push_swap.c \
			src/structs.c \
			src/utils.c \
			src/ft_split.c \
			src/ft_atoi.c \
			src/sort_stacks.c \
			src/ft_putnbr_fd.c \
			src/ft_strlen.c \
			src/ft_isdigit.c \
			src/short_sort.c \
			src/large_sort.c \
			src/commands.c \
			src/commands2.c \
			src/commands3.c \
			src/ft_putstr_fd.c \
			src/checks.c

OBJS	=	${SRCS:.c=.o}
HEADER	=	-Iincludes
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g

.c.o:		%.o : %.c
			@gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all: 		${NAME}

${NAME}:	${OBJS}
			@$(CC) ${CFLAGS}  ${OBJS} -o ${NAME}
clean:
			@rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
			@rm -f ${NAME}

re:			fclean all

.PHONY: all clean fclean re
