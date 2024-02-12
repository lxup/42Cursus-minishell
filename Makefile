# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 19:51:48 by lquehec           #+#    #+#              #
#    Updated: 2024/02/12 19:48:05 by lquehec          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

END				:=	\033[0m

# COLORS
BLACK			:=	\033[0;30m
RED				:=	\033[0;31m
GREEN			:=	\033[0;32m
ORANGE			:=	\033[0;33m
BLUE			:=	\033[0;34m
PURPLE			:=	\033[0;35m
CYAN			:=	\033[0;36m
LIGHT_GRAY		:=	\033[0;37m
DARK_GRAY		:=	\033[1;30m
LIGHT_RED		:=	\033[1;31m
LIGHT_GREEN		:=	\033[1;32m
YELLOW			:=	\033[1;33m
LIGHT_BLUE		:=	\033[1;34m
LIGHT_PURPLE	:=	\033[1;35m
LIGHT_CYAN		:=	\033[1;36m
WHITE			:=	\033[1;37m

# FONTS
BOLD			:=	\033[1m
DIM				:=	\033[2m
UNDERLINED		:=	\033[4m
BLINK			:=	\033[5m
REVERSE			:=	\033[7m

OS 				:= $(shell uname)
VPATH			:= srcs \
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
				
HEADER_DIR		:= includes
OBJ_DIR 		:= .obj

ifeq ($(OS), Darwin)
INCL_RDL_LIB	:= -lreadline -L/opt/homebrew/opt/readline/lib -lncurses
INCL_RDL_HEADER	:= -I/opt/homebrew/opt/readline/include
else
INCL_RDL_LIB	:= -lreadline -L/Users/${USER}/.brew/opt/readline/lib -lncurses
INCL_RDL_HEADER	:= -I/Users/${USER}/.brew/opt/readline/include
endif

SRC_SYSTEM	:= main \
					minishell \
					prompt \
					init \
					sig \
					exit
SRC_HISTORY		:= history \
					history_utils
SRC_LEXER		:= lexer \
					syntax
SRC_PARSER		:= parser
SRC_EXECUTOR	:= executor
SRC_TOOLS		:= fd shell
SRC_UTILS		:= utils free
SRC_UTILS_T_ENV	:= ft_lstadd_back_env \
					ft_lstclear_env \
					ft_lstfind_env \
					ft_lstlast_env \
					ft_lstnew_env \
					ft_lstreplace_env
SRC_DEBUG		:= tools
# SRC_CMDS	= cd echo env exit export pwd unset

SRCS 			:= $(addsuffix .c, $(SRC_SYSTEM)) \
					$(addsuffix .c, $(SRC_HISTORY)) \
					$(addsuffix .c, $(SRC_LEXER)) \
					$(addsuffix .c, $(SRC_PARSER)) \
					$(addsuffix .c, $(SRC_EXECUTOR)) \
					$(addsuffix .c, $(SRC_TOOLS)) \
					$(addsuffix .c, $(SRC_UTILS)) \
					$(addsuffix .c, $(SRC_UTILS_T_ENV)) \
					$(addsuffix .c, $(SRC_DEBUG)) \
					# $(addsuffix .c, $(SRC_CMDS))

OBJS			:= $(SRCS:%.c=$(OBJ_DIR)/%.o)

# LIBFT
LIBFT_DIR 			:= libft
LIBFT_HEADER_DIR	:= $(LIBFT_DIR)/includes
LIBFT_PATH			:= -L $(LIBFT_DIR) -lft

RM			:= rm -rf
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g3
# CFLAGS		:= 
FLAGS		:=	$(INCL_RDL_LIB) $(LIBFT_PATH)

CINCLUDES	:= -I $(HEADER_DIR) -I $(LIBFT_HEADER_DIR)
NAME		:= minishell

all: 		$(NAME)

$(NAME):	${OBJ_DIR} $(OBJS)
			@make -C $(LIBFT_DIR)
			@$(CC) $(FLAGS) $(CFLAGS) $(CINCLUDES) -o $(NAME) $(OBJS)
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

$(OBJ_DIR):
			@mkdir -p ${OBJ_DIR}

$(OBJ_DIR)/%.o: %.c
# @/bin/echo -n .
ifeq ($(OS), Darwin)
			@printf "${BLUE}>Generating minishell objects... %-33.33s\r" $@
			@$(CC) $(CFLAGS) $(INCL_RDL_HEADER) $(CINCLUDES) -c $< -o $@
else
			@$(CC) $(CFLAGS) $(CINCLUDES) -c $< -o $@
endif

clean:
			@make clean -C $(LIBFT_DIR)
			@$(RM) $(OBJ_DIR)
			@echo "${YELLOW}> All objects files of $(NAME) have been deleted ❌${END}"

fclean:		clean
			@make fclean -C $(LIBFT_DIR)
			@$(RM) $(NAME)
			@echo "${YELLOW}> Cleaning of $(NAME) has been done ❌${END}"

re:			fclean all

.PHONY: all clean fclean re