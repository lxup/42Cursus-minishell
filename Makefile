# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 19:51:48 by lquehec           #+#    #+#              #
#    Updated: 2024/02/12 10:25:05 by lquehec          ###   ########.fr        #
#                                                                              #
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
					srcs/utils/libft_enhanced \
					srcs/debug
				
HEADER_DIR		:= includes
OBJ_DIR 		:= .obj

ifeq ($(OS), Darwin)
INCL_RDL_LIB	:= -L/opt/homebrew/opt/readline/lib -lncurses
INCL_RDL_HEADER	:= -I/opt/homebrew/opt/readline/include
else
INCL_RDL_LIB	:= -lreadline -L /home/linuxbrew/.linuxbrew/opt/readline/lib
INCL_RDL_HEADER	:= -I /home/linuxbrew/.linuxbrew/opt/readline/include/readline
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
SRC_UTILS_LIBFT_ENHANCED	:= ft_split
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
					$(addsuffix .c, $(SRC_UTILS_LIBFT_ENHANCED)) \
					$(addsuffix .c, $(SRC_DEBUG)) \
					# $(addsuffix .c, $(SRC_CMDS))

OBJS			:= $(SRCS:%.c=$(OBJ_DIR)/%.o)

# LIBFT
LIBFT_DIR 			:= libft
LIBFT_HEADER_DIR	:= $(LIBFT_DIR)
LIBFT_PATH			:= -L $(LIBFT_DIR) -lft

RM			:= rm -rf
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g3
# CFLAGS		:= 
FLAGS		:=	$(INCL_RDL_LIB) -lreadline -L$(LIBFT_DIR) -lft

CINCLUDES	:= -I $(HEADER_DIR) -I $(LIBFT_HEADER_DIR)
NAME		:= minishell

all: 		$(NAME)

$(NAME):	${OBJ_DIR} $(OBJS)
			@make all bonus -C $(LIBFT_DIR)
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
			@echo "${YELLOW}>Cleaning libft..."
			@make clean -C $(LIBFT_DIR)
			@$(RM) $(OBJ_DIR)
			@echo "${YELLOW}> All objects files of $(NAME) have been deleted ❌${END}"

fclean:		clean
			@echo "${YELLOW}>Cleaning libft..."
			@make fclean -C $(LIBFT_DIR)
			@$(RM) $(NAME)
			@echo "${YELLOW}> Cleaning of $(NAME) has been done ❌${END}"

re:			fclean all

.PHONY: all clean fclean re