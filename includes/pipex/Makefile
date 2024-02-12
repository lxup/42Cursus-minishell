NAME	= pipex

BONUS	= pipex_bonus

CC	= clang

CFLAGS  = -Wall -Wextra -Werror -g3

RM	= rm -f

LIBFT          = libft

FT_LIBFT	= libft/libft.a

SRC     = srcs/mandatory/main.c srcs/mandatory/utils.c

BONUS_SRC	=  srcs/bonus/main.c srcs/bonus/utils.c srcs/bonus/heredoc.c

OBJ_BONUS	= ${BONUS_SRC:.c=.o}

OBJ     = ${SRC:.c=.o}

all : ${NAME}

${NAME} : ${OBJ}
	${MAKE} -C ${LIBFT}
	${CC} ${OBJ} -o ${NAME} ${FT_LIBFT}

bonus : ${BONUS}

${BONUS} : ${OBJ_BONUS}
	${MAKE} -C ${LIBFT}
	${CC} ${OBJ_BONUS} -o ${BONUS} ${FT_LIBFT}

clean :
	${RM} ${OBJ} ${OBJ_BONUS}

fclean : clean
	${RM} ${NAME} ${BONUS}

re : fclean all

.PHONY : all clean fclean re