/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:52:43 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/12 11:21:15 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

// typedef enum e_token_type
// {
// 	TOKEN_WORD,
// 	TOKEN_PIPE,
// 	TOKEN_DPIPE,
// 	TOKEN_AMPERSAND,
// 	TOKEN_DAMPERSAND,
// 	TOKEN_GREATER,
// 	TOKEN_DGREATER,
// 	TOKEN_LESSER,
// 	TOKEN_DLESSER,
// 	TOKEN_UNKNOW,
// 	TOKEN_END,
// }	t_token_type;

typedef enum e_token_type
{
	TOKEN_COMMAND,
	TOKEN_OPERATOR,
	TOKEN_ARGUMENT,
	TOKEN_UNKNOWN,
}	t_token_type;

/* Chained list for tokens */
typedef struct s_token
{
	char				*value;
	t_token_type		type;
	struct s_token		*next;
	struct s_token		*prev;
}	t_token;

/* Chained list for env */
typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
}				t_env;

typedef struct s_shell_prompt
{
	char		*prompt;
	int			prompt_size;
}				t_shell_prompt;

/* Main structure */
typedef struct s_mini
{
	t_env			*env;
	char			**cmd_path;
	char			*prompt;
	char			*prev_prompt;
	t_shell_prompt	shell_prompt;
	int				std_in;
	int				std_out;
	char			*pwd;
	struct termios	term;
	int				last_exec_status;
	int				exec_status;
	int				exit_code;
}	t_mini;

#endif