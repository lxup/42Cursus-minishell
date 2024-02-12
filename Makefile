# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 19:51:48 by lquehec           #+#    #+#              #
#    Updated: 2024/02/12 22:31:56 by lquehec          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                     VARS                                     #
# **************************************************************************** #

# COLORS
END=\x1b[0m
BOLD=\x1b[1m
UNDER=\x1b[4m
REV=\x1b[7m
GREY=\x1b[30m
RED=\x1b[31m
GREEN=\x1b[32m
YELLOW=\x1b[33m
BLUE=\x1b[34m
PURPLE=\x1b[35m
CYAN=\x1b[36m
WHITE=\x1b[37m

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

OBJS			:= $(SRCS:%.c=$(OBJ_PATH)/%.o)

# **************************************************************************** #
#                                     LIBS                                     #
# **************************************************************************** #

LDLIBS				= -lft

ifeq ($(OS), Darwin)
INCL_RDL_LIB	:= -L/opt/homebrew/opt/readline/lib -lncurses
INCL_RDL_HEADER	:= -I/opt/homebrew/opt/readline/include
else
INCL_RDL_LIB	:= -L/Users/${USER}/.linuxbrew/opt/readline/lib -lncurses
INCL_RDL_HEADER	:= -I/Users/${USER}/.linuxbrew/opt/readline/include
endif

LDLIBS				+=  -lreadline $(INCL_RDL_LIB)

# LIBFT
LIBFT_DIR 			=	libft
LIBFT_INC_PATH		=	$(LIBFT_DIR)/includes
LIBFT				=	$(LIBFT_DIR)/libft.a

CFLAGS				+=	-I$(LIBFT_INC_PATH)

LDLIBS				+=	-L$(LIBFT_DIR)


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
# @/bin/echo -n .
# ifeq ($(OS), Darwin)
# 			@printf "${BLUE}>Generating minishell objects... %-33.33s\r" $@
# 			@$(CC) $(CFLAGS) $(INCL_RDL_HEADER) -c $< -o $@
# else
# 			@$(CC) $(CFLAGS) $(INCL_RDL_HEADER) -c $< -o $@
# endif

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