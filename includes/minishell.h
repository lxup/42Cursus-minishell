/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:31:59 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/14 20:50:27 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* Includes */
# include "lib.h"
# include "typedef.h"
# include "define.h"

/* Global variables */
extern pid_t	g_pid;

/* ================================= SYSTEM ================================= */

int			test(t_mini *mini);

/* Initialization */
void		init(t_mini *mini, char **env);

/* Minishell */
void		minishell(t_mini *mini);

/* Sig */
void		sig_handler(int sig);

/* Prompt */
void		get_shell_prompt(t_mini *mini);

/* Exit */
int			ft_exit(t_mini *mini, int status, char *error);

/* ================================ HISTORY ================================ */
/* History */
void		*init_history(t_mini *mini);
void		*add_to_history(t_mini *mini);

/* History Utils */
int			is_new_prompt(t_mini *mini);
int			is_only_space(char *str);

/* ================================= LEXER ================================= */

/*
** Lexer
** Allowing to split the prompt into tokens
** ./lexer/lexer.c
*/
int			lexer(t_mini *mini);

/*
** Define the token type
** ./lexer/lexer_token_type.c
*/
int			define_token_type(char *prompt, t_token_type *type, int *i);

/*
** Complete the token type for each token
** ./lexer/lexer_token_type.c
*/
void		adjust_token_type(t_token *tokens);

/*
** Check if the syntax is valid
** ./lexer/is_valid_syntax.c
*/
int			is_valid_syntax(char *str);

/*
** Check if the token is a greater '>'
** ./lexer/lexer_is_1.c
*/
int			is_greater(char *prompt);

/*
** Check if the token is a double greater '>>'
** ./lexer/lexer_is_1.c
*/
int			is_dgreater(char *prompt);

/*
** Check if the token is a lesser '<'
** ./lexer/lexer_is_1.c
*/
int			is_lesser(char *prompt);

/*
** Check if the token is a double lesser '<<'
** ./lexer/lexer_is_1.c
*/
int			is_dlesser(char *prompt);

/*
** Check if the token is a word
** ./lexer/lexer_is_2.c
*/
int			is_word(char *prompt, int *i);

/* ================================= PARSER ================================= */

/*
** Parser
** Allowing to parse the tokens
** ./parser/parser.c
*/
int			parser(t_mini *mini);

/*
** Fix the quote for tokens
** ./parser/parser_quote_fix.c
*/
int			parser_quote_fix(t_mini *mini);

/* =============================== EXECUTOR ================================ */

int			expander(t_mini *mini);

int			expander_env_var(t_mini *mini);

/* =============================== EXECUTOR ================================ */

int			executor(t_mini *mini);

int			handle_heredoc(t_mini *mini);

/* ================================= TOOLS ================================= */

/* Shell */

/*
** Get the OS
** ./tools/shell/get_os.c
*/
char		*get_os(void);

/*
** Get the pwd
** ./tools/shell/get_path.c
*/
char		*get_path(t_mini *mini);

/*
** Build the left side of the prompt
** ./tools/shell/build_left_side.c
*/
void		build_left_side(t_mini *mini, char *os, char *path);

/*
** Get the terminal width
** ./tools/shell/get_terminal_width.c
*/
int			get_terminal_width(void);

/* FD */
// void	reset_fds(t_mini *mini);
// void	ft_close_fd(int fd);
// void	close_fds(t_mini *mini);
void		reset_stds(t_mini *mini);

/* ================================= UTILS ================================= */

/* t_token */
void		ft_lstadd_back_token(t_token **lst, t_token *new);
void		ft_lstclear_token(t_token **lst);
t_token		*ft_lstlast_token(t_token *lst);
t_token		*ft_lstnew_token(char *value, t_token_type type);
int			ft_lstcount_type_token(t_token *lst, t_token_type type);
t_token		*ft_lstnext_tokentype_token(t_token *lst, t_token_type type, \
			t_token *current);

/* t_pipeline */
void		ft_lstadd_back_pipeline(t_pipeline **lst, t_pipeline *new);
void		ft_lstclear_pipeline(t_pipeline **lst);
t_pipeline	*ft_lstlast_pipeline(t_pipeline *lst);
t_pipeline	*ft_lstnew_pipeline(char *prompt);
int			ft_lstsize_pipeline(t_pipeline *lst);
int			ft_lstcount_tokentype_pipeline(t_pipeline *lst, t_token_type type);
t_token		*ft_lstnext_tokentype_pipeline(t_pipeline *lst, \
			t_token_type type, t_token *current);
/* t_env */
void		ft_lstadd_back_env(t_env **lst, t_env *new);
void		ft_lstclear_env(t_env **lst);
char		*ft_lstfind_env(t_env **env, char *name);
t_env		*ft_lstlast_env(t_env *lst);
t_env		*ft_lstnew_env(char *name, char *value);
int			ft_lstreplace_env(t_env **env, char *name, char *value);

/* free */
void		ft_free_array(void **array);

/* ================================= DEBUG ================================= */
void		print_env(t_mini *mini);
void		print_history(t_list *history);
void		print_2d_array(char **str);
void		print_pipeline(t_mini *mini);
void		print_tokens(t_token *token);

#endif