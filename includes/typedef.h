/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:52:43 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/13 00:10:04 by lquehec          ###   ########.fr       */
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

// typedef enum e_token_type
// {
// 	TOKEN_COMMAND,
// 	TOKEN_OPERATOR,
// 	TOKEN_ARGUMENT,
// 	TOKEN_UNKNOWN,
// }	t_token_type;

typedef enum e_token_type
{
	TOKEN_ID,
	TOKEN_STR,
	TOKEN_INT,
	TOKEN_DOUBLE,
	TOKEN_MAYBE_DOUBLE,
	TOKEN_PLUS,
	TOKEN_PLUS_PLUS,
	TOKEN_MINUS,
	TOKEN_MINUS_MINUS,
	TOKEN_MULTIPLY,
	TOKEN_LT,
	TOKEN_GT,
	TOKEN_EQ,
	TOKEN_EQ_EQ,
	TOKEN_NOT_EQ,
	TOKEN_PLUS_EQ,
	TOKEN_MINUS_EQ,
	TOKEN_MULTIPLY_EQ,
	TOKEN_DIVIDE_EQ,
	TOKEN_MODULO_EQ,
	TOKEN_LT_EQ,
	TOKEN_GT_EQ,
	TOKEN_DIVIDE,
	TOKEN_MODULO,
	TOKEN_L_PARAN,
	TOKEN_R_PARAN,
	TOKEN_L_BRACKET,
	TOKEN_R_BRACKET,
	TOKEN_L_CURLY,
	TOKEN_R_CURLY,
	TOKEN_L_ARROW,
	TOKEN_R_ARROW,
	TOKEN_PIPE,
	TOKEN_PIPE_PIPE,
	TOKEN_COMMA,
	TOKEN_PERIOD,
	TOKEN_SEMICOLON,
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