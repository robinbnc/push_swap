SRCS	=	algo_utils.c clean_instruction_list.c dc_list_utils_2.c dc_list_utils.c\
			division_insertion_algo.c ft_main_functions.c indexation.c ft_split.c\
			main.c parsing.c short_stack_algo.c sort_first_el_list.c

OBJS	=	${SRCS:.c=.o}

NAME	=	push_swap

CC	=		gcc

CFLAGS	=	-Wall -Wextra -Werror

RM	=		rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o push_swap

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean
