# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 19:51:48 by lquehec           #+#    #+#              #
#    Updated: 2024/02/08 17:55:49 by lquehec          ###   ########.fr        #
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

OS 			:= $(shell uname)
VPATH		= srcs srcs/main
HEADER_DIR	= includes
OBJ_DIR 	= .obj

SRCS 		= main.c

OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

# LIBFT
LIBFT_DIR 			= libft
LIBFT_HEADER_DIR	= $(LIBFT_DIR)
LIBFT_PATH			= -L $(LIBFT_DIR) -lft

RM			= rm -rf
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3 -I $(HEADER_DIR) -I $(LIBFT_HEADER_DIR)
NAME		= minishell

all: 		$(NAME)

$(NAME):	${OBJ_DIR} $(OBJS)
			@make -C $(LIBFT_DIR)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) 
			@echo "\n${GREEN}> $(NAME) was successfuly compiled 🎉${END}"

$(OBJ_DIR):
			@mkdir -p ${OBJ_DIR}

$(OBJ_DIR)/%.o: %.c
			@/bin/echo -n .
			@$(CC) $(CFLAGS) -c $< -o $@

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