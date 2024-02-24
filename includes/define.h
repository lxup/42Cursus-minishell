/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:03:17 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/24 12:17:50 by lquehec          ###   ########.fr       */
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

/* ************************************************************************** */
/*                           FILE DESCRIPTORS (FD)                            */
/* ************************************************************************** */

# define STDIN 0
# define STDOUT 1
# define STDERR 2

/* ************************************************************************** */
/*                                    EXIT                                    */
/* ************************************************************************** */

# define EXIT_CTRL_D 130
# define EXIT_CMD_NOT_FOUND 127
# define EXIT_SYNTAX_ERROR 258
# define EXEC_PIPE_ERROR 300
# define EXEC_FORK_ERROR 301
# define EXEC_DUP_ERROR 302

/* ************************************************************************** */
/*                                    EXEC                                    */
/* ************************************************************************** */

# ifdef __APPLE__
#  define EXEC_SUCCESS 0
#  define EXEC_FAILURE 1
#  define EXEC_CTRL_D 0
#  define EXEC_CTRL_C 1
#  define EXEC_CTRL_BS 131
#  define EXEC_SYNTAX_ERROR 258
#  define EXEC_CMD_NOT_FOUND 127
# elif __linux__
#  define EXEC_SUCCESS 0
#  define EXEC_FAILURE 1
#  define EXEC_CTRL_D 0
#  define EXEC_CTRL_C 130
#  define EXEC_CTRL_BS 131
#  define EXEC_SYNTAX_ERROR 2
#  define EXEC_CMD_NOT_FOUND 127
# endif

/* ************************************************************************** */
/*                                PERMISSIONS                                 */
/* ************************************************************************** */

# define PERM_RW 0644

/* ************************************************************************** */
/*                                 BUILTINS                                   */
/* ************************************************************************** */

/* MSG */
# ifdef __APPLE__
#  define EXPORT_BUILTIN_PRINT_ENV "export"
# elif __linux__
#  define EXPORT_BUILTIN_PRINT_ENV "export"
# endif

/* CODE */
# ifdef __APPLE__
#  define EXIT_BUILTIN_NONUM 255
# elif __linux__
#  define EXIT_BUILTIN_NONUM 2
# endif

/* ************************************************************************** */
/*                                  ERRORS                                    */
/* ************************************************************************** */

// General errors
# define ERR_MALLOC "Error->Malloc failed\n"
# define ERR_TERM "Error->Failed to get terminal type\n"
# define ERR_DUP "Error->Failed to duplicate file descriptor\n"
// File errors
# define ERR_OPEN_FILE "Error->Failed to open file\n"
// Environment errors
# define ERR_ENV_HOME "Error->HOME not found in env\n"

# define ERR_SYNTAX "syntax error near unexpected token"
# define ERR_PROHIBIDED_CHAR "prohibited character"
# define ERR_UNCLOSE_CHAR "unclosed character"
# define ERR_PWD_NOT_SET "Environment variable PWD not set"

/* ************************************************************************** */
/*                                  PROMPT                                    */
/* ************************************************************************** */

# define NEW_PROMPT 0

/* Fonts */
# define F_BOLD "\1\033[1m\2" /* - Bold font */
# define F_UNDERLINE "\1\033[4m\2" /* - Underline font */
# define F_BLINK "\1\033[5m\2" /* - Blink font */
# define F_REVERSE "\1\033[7m\2" /* - Reverse font */
# define F_CONCEAL "\1\033[8m\2" /* - Conceal font */
# define F_RESET "\1\033[0m\2" /* - Reset font */

/* Colors */
# define C_BLACK "\1\033[30m\2" /* - Black color */
# define C_RED "\1\033[31m\2" /* - Red color */
# define C_GREEN "\1\033[32m\2" /* - Green color */
# define C_YELLOW "\1\033[33m\2" /* - Yellow color */
# define C_BLUE "\1\033[34m\2" /* Blue - color */
# define C_MAGENTA "\1\033[35m\2" /* - Magenta color */
# define C_CYAN "\1\033[36m\2" /* - Cyan color */
# define C_WHITE "\1\033[37m\2" /* - White color */
# define C_GRAY "\1\033[90m\2" /* - Gray color */
# define C_LIGHT_GRAY "\1\033[37m\2" /* - Light gray color */
# define C_BEIGE "\1\033[93m\2" /* - Beige color */
# define C_END "\1\033[0m\2"

/* Backgrounds */
# define BG_BLACK "\1\033[40m\2" /* - Black background */
# define BG_RED "\1\033[41m\2" /* - Red background */
# define BG_GREEN "\1\033[42m\2" /* - Green background */
# define BG_YELLOW "\1\033[43m\2" /* - Yellow background */
# define BG_BLUE "\1\033[44m\2" /* - Blue background */
# define BG_MAGENTA "\1\033[45m\2" /* - Magenta background */
# define BG_CYAN "\1\033[46m\2" /* - Cyan background */
# define BG_WHITE "\1\033[47m\2" /* - White background */
# define BG_TRANSPARENT "\1\033[49m\2" /* - Transparent background */

/* Prompt */
// # define PROMPT_TEMPLATE BG_WHITE C_BLACK " %s " BG_BLUE C_WHITE "  %s "
// 	BG_BLACK C_BLUE ""
// # define PROMPTE_SUCCESS_TEMPLATE BG_BLACK C_GREEN " ✔ "
// 	BG_TRANSPARENT C_BLACK ""
// # define PROMPTE_ERROR_TEMPLATE BG_BLACK C_RED " ✘ "
// 	BG_TRANSPARENT C_BLACK ""

/* ************************************************************************** */
/*                                  HEREDOC                                   */
/* ************************************************************************** */

# define HEREDOC_TEMPLATE_PATH_PREFIX "/tmp/.minishell_heredoc"
# define HEREDOC_TEMPLATE_PATH_SUFFIX ".tmp"

#endif