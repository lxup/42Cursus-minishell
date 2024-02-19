/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:03:17 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/19 22:34:56 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# ifdef __APPLE__
#  define OS "macos"
# elif __linux__
#  define OS "linux"
# endif

// # define SHELL "\033[31m" "➜ minishell: "
# define SHELL "minishell: "

/* **************************************************************************** */
/*                            FILE DESCRIPTORS (FD)                             */
/* **************************************************************************** */

# define STDIN 0
# define STDOUT 1
# define STDERR 2

/* **************************************************************************** */
/*                                     EXIT                                     */
/* **************************************************************************** */

# define EXIT_CTRL_D 130
# define EXIT_CMD_NOT_FOUND 127
# define EXIT_SYNTAX_ERROR 258
# define EXEC_PIPE_ERROR 300
# define EXEC_FORK_ERROR 301
# define EXEC_DUP_ERROR 302


/* **************************************************************************** */
/*                                     EXEC                                     */
/* **************************************************************************** */

# define EXEC_SUCCESS 0
# define EXEC_FAILURE 1
# define EXEC_CTRL_D 130
# define EXEC_SYNTAX_ERROR 258
# define EXEC_CMD_NOT_FOUND 127


/* **************************************************************************** */
/*                                     MSG                                      */
/* **************************************************************************** */

# define MSG_EXIT "Bye"

/* **************************************************************************** */
/*                                 PERMISSIONS                                  */
/* **************************************************************************** */

# define PERM_RW 0644

/* **************************************************************************** */
/*                                  BUILTINS                                    */
/* **************************************************************************** */

/* MSG */
# ifdef __APPLE__
#  define EXPORT_BUILTIN_PRINT_ENV "export"
# elif __linux__
#  define EXPORT_BUILTIN_PRINT_ENV "declare -x"
# endif

/* CODE */
# ifdef __APPLE__
#  define EXIT_BUILTIN_NONUM 255
# elif __linux__
#  define EXIT_BUILTIN_NONUM 2
# endif

/* **************************************************************************** */
/*                                   ERRORS                                     */
/* **************************************************************************** */

// General errors
# define ERR_MALLOC "Error->Malloc failed\n"
# define ERR_TERM "Error->Failed to get terminal type\n"
# define ERR_DUP "Error->Failed to duplicate file descriptor\n"
// File errors
# define ERR_OPEN_FILE "Error->Failed to open file\n"
// Environment errors
# define ERR_ENV_HOME "Error->HOME not found in env\n"

# define ERR_SYNTAX "syntax error near unexpected token"
# define ERR_PWD_NOT_SET "Environment variable PWD not set"

/* **************************************************************************** */
/*                                   PROMPT                                     */
/* **************************************************************************** */

# define NEW_PROMPT 0

/* Fonts */
# define F_BOLD "\033[1m" /* - Bold font */
# define F_UNDERLINE "\033[4m" /* - Underline font */
# define F_BLINK "\033[5m" /* - Blink font */
# define F_REVERSE "\033[7m" /* - Reverse font */
# define F_CONCEAL "\033[8m" /* - Conceal font */
# define F_RESET "\033[0m" /* - Reset font */

/* Colors */
# define C_BLACK "\033[30m" /* - Black color */
# define C_RED "\033[31m" /* - Red color */
# define C_GREEN "\033[32m" /* - Green color */
# define C_YELLOW "\033[33m" /* - Yellow color */
# define C_BLUE "\033[34m" /* Blue - color */
# define C_MAGENTA "\033[35m" /* - Magenta color */
# define C_CYAN "\033[36m" /* - Cyan color */
# define C_WHITE "\033[37m" /* - White color */
# define C_GRAY "\033[90m" /* - Gray color */
# define C_LIGHT_GRAY "\033[37m" /* - Light gray color */
# define C_END "\033[0m"

/* Backgrounds */
# define BG_BLACK "\033[40m" /* - Black background */
# define BG_RED "\033[41m" /* - Red background */
# define BG_GREEN "\033[42m" /* - Green background */
# define BG_YELLOW "\033[43m" /* - Yellow background */
# define BG_BLUE "\033[44m" /* - Blue background */
# define BG_MAGENTA "\033[45m" /* - Magenta background */
# define BG_CYAN "\033[46m" /* - Cyan background */
# define BG_WHITE "\033[47m" /* - White background */
# define BG_TRANSPARENT "\033[49m" /* - Transparent background */

/* Prompt */
# define PROMPT_TEMPLATE BG_WHITE C_BLACK " %s " BG_BLUE C_WHITE "  %s " \
	BG_BLACK C_BLUE ""
# define PROMPTE_SUCCESS_TEMPLATE BG_BLACK C_GREEN " ✔ " \
	BG_TRANSPARENT C_BLACK ""
# define PROMPTE_ERROR_TEMPLATE BG_BLACK C_RED " ✘ " \
	BG_TRANSPARENT C_BLACK ""

/* **************************************************************************** */
/*                                   HEREDOC                                    */
/* **************************************************************************** */

# define HEREDOC_TEMPLATE_PATH_PREFIX "/tmp/.minishell_heredoc"
# define HEREDOC_TEMPLATE_PATH_SUFFIX ".tmp"

#endif