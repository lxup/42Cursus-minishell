/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:03:17 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/12 11:01:19 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# ifdef __APPLE__
#  define OS "macos"
# elif __linux__
#  define OS "linux"
# endif

/* File descriptors (FD) */
# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define EXIT_CTRL_D 130
# define EXIT_CMD_NOT_FOUND 127
# define EXIT_SYNTAX_ERROR 258

/* Exec status */
# define EXEC_SUCCESS 0
# define EXEC_FAILURE 1
# define EXEC_SYNTAX_ERROR 130

/* Default messages */
# define MSG_EXIT "Bye\n"

/* ================================= ERRORS ================================= */
// General errors
# define ERR_MALLOC "Error->Malloc failed\n"
# define ERR_TERM "Error->Failed to get terminal type\n"
# define ERR_DUP "Error->Failed to duplicate file descriptor\n"
// File errors
# define ERR_OPEN_FILE "Error->Failed to open file\n"
// Environment errors
# define ERR_ENV_HOME "Error->HOME not found in env\n"

/* ================================= PROMPT ================================= */
# define NEW_PROMPT 0

/* Fonts */
# define F_BOLD "\033[1m"
# define F_UNDERLINE "\033[4m"
# define F_BLINK "\033[5m"
# define F_REVERSE "\033[7m"
# define F_CONCEAL "\033[8m"
# define F_RESET "\033[0m"

/* Colors */
# define C_BLACK "\033[30m"
# define C_RED "\033[31m"
# define C_GREEN "\033[32m"
# define C_YELLOW "\033[33m"
# define C_BLUE "\033[34m"
# define C_MAGENTA "\033[35m"
# define C_CYAN "\033[36m"
# define C_WHITE "\033[37m"
# define C_GRAY "\033[90m"
# define C_LIGHT_GRAY "\033[37m"

/* Backgrounds */
# define BG_BLACK "\033[40m"
# define BG_RED "\033[41m"
# define BG_GREEN "\033[42m"
# define BG_YELLOW "\033[43m"
# define BG_BLUE "\033[44m"
# define BG_MAGENTA "\033[45m"
# define BG_CYAN "\033[46m"
# define BG_WHITE "\033[47m"
# define BG_TRANSPARENT "\033[49m"

/* Prompt */
# define PROMPT_TEMPLATE BG_WHITE C_BLACK " %s " BG_BLUE C_WHITE "  %s " \
	BG_BLACK C_BLUE ""
# define PROMPTE_SUCCESS_TEMPLATE BG_BLACK C_GREEN " ✔ " \
	BG_TRANSPARENT C_BLACK ""
# define PROMPTE_ERROR_TEMPLATE BG_BLACK C_RED " ✘ " \
	BG_TRANSPARENT C_BLACK ""

#endif