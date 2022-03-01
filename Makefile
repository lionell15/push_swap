NAME	=	push_swap
SRCS	=	push_swap.c \
			src/stacks.c \
			src/checks.c \
			src/quick_sort.c \
			src/utils.c \
			src/utils2.c \
			src/short_solution.c \
			src/sort_stack.c \
			src/print_utils.c \
			src/divide_stack.c \
			src/push_back.c \
			src/command_sort.c \
			src/swap_elements.c \
			src/swap.c \
			src/comb.c \
			src/comb2.c
OBJS	=	${SRCS:.c=.o}
HEADER	=	-Iincludes
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g

.c.o:		%.o : %.c
			@gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all: 		${NAME}

${NAME}:	${OBJS}
			@make re -C ./libft
			@$(CC) ${CFLAGS}  ${OBJS} -Llibft -lft -o ${NAME}
clean:
			@make clean -C ./libft
			@rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
			@make fclean -C ./libft
			@rm -f ${NAME}

re:			fclean all

.PHONY: all clean fclean re
