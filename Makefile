# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 19:51:48 by lquehec           #+#    #+#              #
#    Updated: 2024/02/17 00:09:39 by lquehec          ###   ########.fr        #
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
				
INC_PATH		=	includes
OBJ_PATH		=	.obj

# **************************************************************************** #
#                                    FLAGS                                     #
# **************************************************************************** #

CFLAGS			+=	-I$(INC_PATH)

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

# SYSTEM
SRCS 			=	$(addprefix srcs/system/, $(addsuffix .c, \
					main \
					minishell \
					prompt \
					init \
					sig \
					exit))
# ENV
SRCS			+=	$(addprefix srcs/env/, $(addsuffix .c, \
					env_init \
					env_update))
# ERROR
SRCS			+=	$(addprefix srcs/error/, $(addsuffix .c, \
					p_err_syntax))
# HISTORY
SRCS 			+=	$(addprefix srcs/history/, $(addsuffix .c, \
					history \
					history_utils))
# LEXER
SRCS 			+=	$(addprefix srcs/lexer/, $(addsuffix .c, \
					lexer \
					syntax \
					lexer_token_type))
# LEXER/IS
SRCS 			+=	$(addprefix srcs/lexer/is/, $(addsuffix .c, \
					is_env_var \
					is_greater \
					is_dgreater \
					is_lesser \
					is_dlesser \
					is_pipe \
					is_word \
					is_word_in_quote \
					is_quote \
					is_dquote))
# PARSER
SRCS 			+=	$(addprefix srcs/parser/, $(addsuffix .c, \
					parser \
					parser_check_token_type \
					parser_check_order \
					parser_fix_quote))
# EXPANDER
SRCS 			+=	$(addprefix srcs/expander/, $(addsuffix .c, \
					expander_env_var \
					expander_heredoc))
# EXECUTOR
SRCS 			+=	$(addprefix srcs/executor/, \
						$(addsuffix .c, \
						executor \
						exec_open_file \
						exec_multi_pipeline \
						exec_single_pipeline \
						exec_child))
# EXECUTOR/HEREDOC
SRCS 			+=	$(addprefix srcs/executor/heredoc/, $(addsuffix .c, \
					heredoc \
					heredoc_filename))
# EXECUTOR PIPEX
SRCS 			+=	$(addprefix srcs/executor/pipex/, $(addsuffix .c, \
					pipex \
					pipex_utils))
# EXECUTOR/REDIRECTION
# SRCS 			+=	$(addprefix srcs/executor/redirections/, $(addsuffix .c, \
# 					redirections))

# BUILTINS
SRCS 			+=	$(addprefix srcs/builtins/, $(addsuffix .c, \
					is_builtin \
					cd/cd \
					echo/echo \
					env/env \
					exit/exit \
					export/export \
					pwd/pwd \
					unset/unset))
# TOOLS
SRCS 			+=	$(addprefix srcs/tools/, $(addsuffix .c, \
					fd \
					shell \
					ft_strjoin_bs \
					env_to_str))
# UTILS
SRCS 			+=	$(addprefix srcs/utils/, $(addsuffix .c, \
					utils \
					free))
# UTILS/T_ENV
SRCS 			+=	$(addprefix srcs/utils/t_env/, $(addsuffix .c, \
					ft_lstadd_back_env \
					ft_lstclear_env \
					ft_lstfind_env \
					ft_lstlast_env \
					ft_lstnew_env \
					ft_lstreplace_env \
					ft_lstupsert_env \
					ft_lstinsert_env \
					ft_lstsize_env))
# UTILS/T_TOKEN
SRCS 			+=	$(addprefix srcs/utils/t_token/, $(addsuffix .c, \
					ft_lstadd_back_token \
					ft_lstclear_token \
					ft_lstlast_token \
					ft_lstnew_token \
					ft_lstcount_type_token \
					ft_lstnext_tokentype_token \
					ft_lstprev_cmd_token \
					ft_lstnext_cmd_token \
					ft_lstprev_tokentype_token \
					ft_lstcountprev_tokentype_token \
					ft_lstremove_token))
# UTILS/T_PIPELINE
SRCS 			+=	$(addprefix srcs/utils/t_pipeline/, $(addsuffix .c, \
					create_pipeline \
					ft_lstadd_back_pipeline \
					ft_lstclear_pipeline \
					ft_lstlast_pipeline \
					ft_lstnew_pipeline \
					ft_lstsize_pipeline \
					ft_lstcount_tokentype_pipeline \
					ft_lstnext_tokentype_pipeline \
					ft_lstfind_type_pipeline))
# DEBUG
SRCS 			+=	$(addprefix srcs/debug/, $(addsuffix .c, \
					tools))

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

CFLAGS				+=	-I$(LIBFT_INC_PATH)

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
			@mkdir -p $(dir $@)
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
