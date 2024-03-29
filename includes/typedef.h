/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:52:43 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/23 12:32:54 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef enum e_token_type
{
	TOKEN_LESSER,
	TOKEN_DLESSER,
	TOKEN_GREATER,
	TOKEN_DGREATER,
	TOKEN_PIPE,
	TOKEN_FILE,
	TOKEN_ENV_VAR,
	TOKEN_TILDE,
	TOKEN_QUOTE,
	TOKEN_DQUOTE,
	TOKEN_CMD,
	TOKEN_ARGS,
	TOKEN_WORD,
	TOKEN_UNKNOWN,
	TOKEN_NOT_SET,
}	t_token_type;

/* Chained list for tokens */
typedef struct s_token
{
	char				*value;
	t_token_type		type;
	int					index;
	struct s_token		*next;
	struct s_token		*prev;
}	t_token;

/* Chained list for pipeline */
typedef struct s_pipeline
{
	t_token				*tokens;
	char				*heredoc;
	char				**args;
	pid_t				pid;
	int					pipefd[2];
	int					prevpipe;
	char				*infile;
	char				*outfile;
	int					redir_append;
	int					exec_status;
	struct s_pipeline	*next;
	struct s_pipeline	*prev;
}	t_pipeline;

/* Chained list for env */
typedef struct s_env
{
	char			*name;
	char			*value;
	int				equal_sign;
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
	char			**env_array;
	t_token			*tokens;
	t_pipeline		*pipeline;
	char			**cmd_path;
	char			*prompt;
	char			*prev_prompt;
	t_shell_prompt	shell_prompt;
	int				std_in;
	int				std_out;
	struct termios	term;
	int				exec_only_heredoc;
	int				exit_code;
	int				pipefd[2];
	int				prevpipe;
}	t_mini;

#endif