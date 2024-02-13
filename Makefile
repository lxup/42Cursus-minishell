# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 19:51:48 by lquehec           #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2024/02/13 11:53:00 by lquehec          ###   ########.fr        #
=======
#    Updated: 2024/02/13 03:30:58 by lquehec          ###   ########.fr        #
>>>>>>> e6cb0d4dfe0de2379eccbf5a6ad6141660ddbc63
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                     VARS                                     #
# **************************************************************************** #

END				=	\033[0m

# COLORS
BLACK			=	\033[0;30m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
ORANGE			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
CYAN			=	\033[0;36m
LIGHT_GRAY		=	\033[0;37m
DARK_GRAY		=	\033[1;30m
LIGHT_RED		=	\033[1;31m
LIGHT_GREEN		=	\033[1;32m
YELLOW			=	\033[1;33m
LIGHT_BLUE		=	\033[1;34m
LIGHT_PURPLE	=	\033[1;35m
LIGHT_CYAN		=	\033[1;36m
WHITE			=	\033[1;37m

# FONTS
BOLD			=	\033[1m
DIM				=	\033[2m
UNDERLINED		=	\033[4m
BLINK			=	\033[5m
REVERSE			=	\033[7m

# OS
OS				=	$(shell uname)

# **************************************************************************** #
#                                   PROGRAM                                    #
# **************************************************************************** #

NAME			=	minishell

# **************************************************************************** #
#                                   COMPILER                                   #
# **************************************************************************** #

CC				=	cc
RM				=	rm -rf
CFLAGS			+=	-Wall -Wextra -Werror -g3

# **************************************************************************** #
#                                    PATHS                                     #
# **************************************************************************** #

VPATH			=	srcs \
					srcs/system \
					srcs/history \
					srcs/lexer \
					srcs/parser \
					srcs/executor \
					srcs/cmds \
					srcs/tools \
					srcs/utils \
					srcs/utils/t_env \
					srcs/debug
				
INC_PATH		=	includes
OBJ_PATH		=	.obj

# **************************************************************************** #
#                                    FLAGS                                     #
# **************************************************************************** #

CFLAGS			+=	-I$(INC_PATH)

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

SRC_SYSTEM		=	main \
					minishell \
					prompt \
					init \
					sig \
					exit
SRC_HISTORY		=	history \
					history_utils
SRC_LEXER		=	lexer \
					syntax
SRC_PARSER		=	parser
SRC_EXECUTOR	=	executor
SRC_TOOLS		=	fd shell
SRC_UTILS		=	utils free
SRC_UTILS_T_ENV	=	ft_lstadd_back_env \
					ft_lstclear_env \
					ft_lstfind_env \
					ft_lstlast_env \
					ft_lstnew_env \
					ft_lstreplace_env
SRC_DEBUG		=	tools

SRCS 			=	$(addsuffix .c, $(SRC_SYSTEM)) \
					$(addsuffix .c, $(SRC_HISTORY)) \
					$(addsuffix .c, $(SRC_LEXER)) \
					$(addsuffix .c, $(SRC_PARSER)) \
					$(addsuffix .c, $(SRC_EXECUTOR)) \
					$(addsuffix .c, $(SRC_TOOLS)) \
					$(addsuffix .c, $(SRC_UTILS)) \
					$(addsuffix .c, $(SRC_UTILS_T_ENV)) \
					$(addsuffix .c, $(SRC_DEBUG)) \

OBJS			=	$(SRCS:%.c=$(OBJ_PATH)/%.o)

# **************************************************************************** #
#                                     LIBS                                     #
# **************************************************************************** #

LDLIBS			=	-lft

ifeq ($(OS), Darwin)
INCL_RDL_LIB	=	-L/opt/homebrew/opt/readline/lib -lncurses
INCL_RDL_HEADER	=	-I/opt/homebrew/opt/readline/include
else
INCL_RDL_LIB	=	-L/Users/${USER}/.linuxbrew/opt/readline/lib -lncurses
INCL_RDL_HEADER	=	-I/Users/${USER}/.linuxbrew/opt/readline/include
endif

LDLIBS			+=	-lreadline $(INCL_RDL_LIB)

# LIBFT
LIBFT_DIR 		=	libft
LIBFT_INC_PATH	=	$(LIBFT_DIR)/includes
LIBFT			=	$(LIBFT_DIR)/libft.a

<<<<<<< HEAD
CFLAGS				+=	-I$(LIBFT_INC_PATH)
# CFLAGS				+=	-I$(LIBFT_DIR)/srcs/gnl
# CFLAGS				+=	-I$(LIBFT_DIR)/srcs/ft_printf
=======
CFLAGS			+=	-I$(LIBFT_INC_PATH)
CFLAGS			+=	-I libft/srcs/gnl
CFLAGS			+=	-I libft/ft_printf/includes
>>>>>>> e6cb0d4dfe0de2379eccbf5a6ad6141660ddbc63

LDLIBS			+=	-L$(LIBFT_DIR)


# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: 		$(NAME)

$(NAME):	${OBJ_PATH} $(OBJS)
			@make -C $(LIBFT_DIR)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDLIBS)
			@echo "\n${GREEN}> $(NAME) was successfuly compiled 🎉${END}"
			@echo ""
			@echo "$(RED) ████▒░▒████▒░██▒░███▒░  █▒░██▒░ ████▒░ ██▒░░▒██▒░██████▒░██▒░    ██▒░"
			@echo " ██▒██▒██▒██▒░██▒░█▒██▒░ █▒░██▒░█▒░ ██▒░██▒░░▒██▒░██▒░    ██▒░    ██▒░"
			@echo " ██▒░███▒░██▒░██▒░█▒░██▒░█▒░██▒░  ██▒░  ████████▒░████▒░  ██▒░    ██▒░"
			@echo " ██▒░░█▒░ ██▒░██▒░█▒░ ██▒█▒░██▒░██▒░ █▒░██▒░░▒██▒░██▒░    ██▒░    ██▒░"
			@echo " ██▒░░░   ██▒░██▒░█▒░  ███▒░██▒░ ████▒░ ██▒░░▒██▒░██████▒░██████▒░██████▒░"
			@echo " ▓▓▒░░     ▓░▒▓▓▒░    ░▒▓▓▒░▓▒░ ░▒▓▓▒░   ▓▒░░▒▓▒░░▒▓▓▒░░░░░░▒▓▓▒░░░▒▓▓▒░"
			@echo " ▓▒░░       ░▒▓▒░     ░▒▓▒░      ░▒▓     ▒░   ▒░  ░▒▓▒░   ░░▒▓▒░  ░░▒▓▒░"
			@echo " ▒░░          ▒░        ▒░        ░░     ░    ░    ░▒░     ░▒▒░    ░▒▒░"
			@echo " ░░           ░         ░          ░                ░       ░░      ░░"
			@echo " ░                                                           ░       ░$(END)"	

$(OBJ_PATH):
			@mkdir -p ${OBJ_PATH}

$(OBJ_PATH)/%.o: %.c
			@printf "${BLUE}>Generating minishell objects... %-33.33s\r" $@
			@$(CC) $(CFLAGS) $(INCL_RDL_HEADER) -c $< -o $@

clean:
			@make clean -C $(LIBFT_DIR)
			@$(RM) $(OBJ_PATH)
			@echo "${YELLOW}> All objects files of $(NAME) have been deleted ❌${END}"

fclean:		clean
			@make fclean -C $(LIBFT_DIR)
			@$(RM) $(NAME)
			@echo "${YELLOW}> Cleaning of $(NAME) has been done ❌${END}"

re:			fclean all

.PHONY: all clean fclean re
