/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:31:59 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/23 12:47:55 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* Includes */
# include "define.h"
# include "lib.h"
# include "typedef.h"

/* Global variables */
extern int		g_status;

/* ************************************************************************** */
/*                                  SYSTEM                                    */
/* ************************************************************************** */

/* Initialization */
void			init(t_mini *mini, char **env);

/* Minishell */
void			minishell(t_mini *mini);

/* Prompt */
void			get_shell_prompt(t_mini *mini);

/* Exit */
int				ft_exit(t_mini *mini);
// int			ft_exit(t_mini *mini, int status, char *error);

/* ************************************************************************** */
/*                                  SIGNALS                                   */
/* ************************************************************************** */

/*
** Signals
** ./signals/signals.c
*/
void			signals(t_mini *mini);

/*
** Signals for heredoc
** ./signals/signals_heredoc.c
*/
void			signals_heredoc(int sig);

/*
** Signals for heredoc process
** ./signals/signals_heredoc.c
*/
void			signals_heredoc_parents(int sig);

/*
** Signals for the parent
** ./signals/signals_parent.c
*/
void			signals_parent(void);

/*
** Signals for the child
** ./signals/signals_child.c
*/
void			signals_child(void);

/* ************************************************************************** */
/*                                    ENV                                     */
/* ************************************************************************** */

/*
** Init env variable
** ./env/env_init.c
*/
void			*env_init(t_mini *mini, char **env);

/*
** Update env variable (at initialization and after each command)
** ./env/env_update.c
*/
int				env_update(t_mini *mini);

/* ************************************************************************** */
/*                                  HISTORY                                   */
/* ************************************************************************** */

/*
** Initialize the history
** If ./.minishell_history doesn't exit, this step is skipped
** ./history/history.c
*/
void			*init_history(t_mini *mini);

/*
** Add the command to the history
** Try to create ./.minishell_history to save history for next session (optional)
** ./history/history.c
*/
void			*add_to_history(t_mini *mini);

/* History Utils */
int				is_new_prompt(t_mini *mini);
int				is_only_space(char *str);

/* ************************************************************************** */
/*                                   LEXER                                    */
/* ************************************************************************** */

/*
** Lexer
** Allowing to split the prompt into tokens
** ./lexer/lexer.c
*/
int				lexer(t_mini *mini);

int				create_tokens(t_mini *mini);

int				lexer_define_token_type(t_mini *mini, int *i, int arg_index);

/*
** Complete the token type for each token
** ./lexer/lexer_token_type.c
*/
int				adjust_token_type(t_token *tokens);

/*
** Check if the syntax is valid
** ./lexer/is_valid_syntax.c
*/
int				is_valid_syntax(t_mini *mini, char *str);

/*
** Check if the token is a greater '|'
** ./lexer/is/is_pipe.c
*/
int				is_pipe(char *prompt);

/*
** Check if the token is a greater '>'
** ./lexer/is/is_greater.c
*/
int				is_greater(char *prompt, t_token_type *type);

/*
** Check if the token is a double greater '>>'
** ./lexer/is/is_dgreater.c
*/
int				is_dgreater(char *prompt, t_token_type *type);

/*
** Check if the token is a lesser '<'
** ./lexer/is/is_lesser.c
*/
int				is_lesser(char *prompt, t_token_type *type);

/*
** Check if the token is a double lesser '<<'
** ./lexer/is/is_dlesser.c
*/
int				is_dlesser(char *prompt, t_token_type *type);

/*
** Check if the token is a quote
** ./lexer/is/is_quote.c
*/
int				is_quote(char *prompt, char *quote, t_token_type *type);

/*
** Check if the token is a double quote
** ./lexer/is/is_dquote.c
*/
int				is_dquote(char *prompt, char *quote, t_token_type *type);

/*
** Check if the token is env variable
** ./lexer/is/is_env_var.c
*/
int				is_env_var(char *prompt, int *i);

/*
** Check if the token is a tilde
** ./lexer/is/is_tilde.c
*/
int				is_tilde(char *prompt, int *i);

/*
** Check if the token is a word in quote
** ./lexer/lexer_is_2.c
*/
int				is_word_in_quote(char *prompt, int *i, char quote);

/*
** Check if the token is a word
** ./lexer/lexer_is_2.c
*/
int				is_word(char *prompt, int i);

/* ************************************************************************** */
/*                                   PARSER                                   */
/* ************************************************************************** */

/*
** Parser
** Allowing to parse the tokens
** ./parser/parser.c
*/
int				parser(t_mini *mini);

/*
** Check the token type
** ./parser/parser_checker_token_type.c
*/
int				parser_check_token_type(t_mini *mini);

/*
** Check the order of the tokens
** ./parser/parser_check_order.c
*/
int				parser_check_order(t_mini *mini);

/*
** Fix the quote for tokens
** ./parser/parser_fix_quote.c
*/
int				parser_fix_quote(t_mini *mini);

/* ************************************************************************** */
/*                                  EXPANDER                                  */
/* ************************************************************************** */

/*
** Expand the env variable by replacing the $ by the value
** ./expander/expander_env_var.c
*/
int				expander_env_var(t_mini *mini);
int				expander_env_var_split(t_mini *mini, t_token *token,
					int space_at_end);

/*
** Expand the tilde by replacing the ~ by the value
** ./expander/expander_tilde.c
*/
int				expander_tilde(t_mini *mini);

/* ********** HEREDOC ********** */
/*
** Expand the env variable inside heredoc by replacing the $ by the value
** ./expander/expander_env_var_heredoc.c
*/
char			*expander_heredoc(t_mini *mini, char *str);
int				expander_heredoc_get_env_var_name_len(char *str);
char			*expander_heredoc_get_env_var(t_mini *mini, char *str);
int				expander_heredoc_set_new_value(t_mini *mini, char **str,
					char *prev_str);

/* ************************************************************************** */
/*                                  EXECUTOR                                  */
/* ************************************************************************** */

int				executor(t_mini *mini);

int				clear_heredoc_after_exec(t_mini *mini);

int				handle_heredoc(t_mini *mini);
char			*heredoc_filename(t_pipeline *pipeline);

/* ************************************************************************** */
/*                                    PIPEX                                   */
/* ************************************************************************** */

/*
** Execute pipelines
** ./executor/pipex/pipex.c
*/
int				pipex(t_mini *mini);

/*
** Execute init redirections
** ./executor/pipex/pipex_redirections.c
*/
void			init_redir(t_mini *mini, t_pipeline *pipeline);

/*
** Handle the command with the path
** ./executor/pipex/pipex_cmd_with_path.c
*/
int				handle_cmd_with_path(t_pipeline *pipeline, t_mini *mini);

/* PIPEX UTILS */

/*
** Open files
** ./executor/pipex/pipex_utils.c
*/
void			*open_files(t_pipeline *pipeline);

/*
** Get the path of the command
** ./executor/pipex/pipex_utils.c
*/
char			*get_path_pipex(t_mini *mini, char *cmd);

/*
** Wait for the child process
** ./executor/pipex/pipex_utils.c
*/
void			ft_waitpid(t_mini *mini, t_pipeline *pipeline);

/* ************************************************************************** */
/*                                   BUILTINS                                 */
/* ************************************************************************** */

/*
** Check if the command is a builtin
** ./builtins/is_builtins.c
*/
int				is_builtin(t_mini *mini, t_pipeline *pipeline);

/*
** Cd builtin
** ./builtins/cd/cd.c
*/
void			cd_builtin(t_mini *mini, t_pipeline *pipeline);

/*
** Echo builtin
** ./builtins/echo/echo.c
*/
void			echo_builtin(t_mini *mini, t_pipeline *pipeline);

/*
** Env builtin
** ./builtins/env/env.c
*/
void			env_builtin(t_mini *mini, t_pipeline *pipeline);

/*
** Exit builtin
** ./builtins/exit/exit.c
*/
void			exit_builtin(t_mini *mini, t_pipeline *pipeline);

/*
** Export builtin
** ./builtins/export/export.c
*/
void			export_builtin(t_mini *mini, t_pipeline *pipeline);
void			export_add(t_mini *mini, t_pipeline *pipeline);
int				export_is_valid_env(t_pipeline *pipeline, char **env);
void			export_print(t_mini *mini);

/*
** Pwd builtin
** ./builtins/pwd/pwd.c
*/
void			pwd_builtin(t_mini *mini, t_pipeline *pipeline);

/*
** Unset builtin
** ./builtins/unset/unset.c
*/
void			unset_builtin(t_mini *mini, t_pipeline *pipeline);

/* ************************************************************************** */
/*                                   ERRORS                                   */
/* ************************************************************************** */

int				p_err_syntax(t_mini *mini, char c);
int				p_err_prohibited_char(t_mini *mini, char c);
int				p_err_unclose_char(t_mini *mini, char c);

/* ================================= TOOLS ================================= */

/* Shell */

char			*ft_strjoin_bs(char const *s1, char const *s2);
char			**env_to_str(t_env *env);
int				ft_count_chars_outside_quotes(char *str, char c);

/* ************************************************************************** */
/*                                    SHELL                                   */
/* ************************************************************************** */

/*
** Get the OS
** ./shell/get_os.c
*/
char			*get_os(void);

/*
** Get the pwd
** ./shell/get_path.c
*/
char			*get_path(t_mini *mini);

/*
** Build the left side of the prompt
** ./shell/build_left_side.c
*/
void			build_left_side(t_mini *mini, char *os, char *path);

/*
** Build the separator
** ./shell/shell_separator.c
*/
void			*build_separator(t_mini *mini);

/*
** Get the terminal width
** ./tools/shell/get_terminal_width.c
*/
int				get_terminal_width(void);

/* ************************************************************************** */
/*                                    UTILS                                   */
/* ************************************************************************** */

/* t_token */
void			ft_lstadd_back_token(t_token **lst, t_token *new);
void			ft_lstclear_token(t_token **lst);
t_token			*ft_lstlast_token(t_token *lst);
t_token			*ft_lstnew_token(char *value, t_token_type type, int index);
int				ft_lstcount_type_token(t_token *lst, t_token_type type);
t_token			*ft_lstnext_tokentype_token(t_token *lst, t_token_type type,
					t_token *current);
t_token			*ft_lstprev_cmd_token(t_token *current);
t_token			*ft_lstnext_cmd_token(t_token *current);
t_token			*ft_lstprev_tokentype_token(t_token *current,
					t_token_type type);
int				ft_lstcountprev_tokentype_token(t_token *current,
					t_token_type type);
int				ft_lstremove_token(t_token **lst, t_token *token);
int				ft_lstinsertafter_token(t_token **lst, t_token *target,
					t_token *new, int space_at_end);
/* t_pipeline */
int				create_pipeline(t_mini *mini);
void			ft_lstadd_back_pipeline(t_pipeline **lst, t_pipeline *new);
void			ft_lstclear_pipeline(t_pipeline **lst);
t_pipeline		*ft_lstlast_pipeline(t_pipeline *lst);
t_pipeline		*ft_lstnew_pipeline(void);
int				ft_lstsize_pipeline(t_pipeline *lst);
int				ft_lstcount_tokentype_pipeline(t_pipeline *lst,
					t_token_type type);
t_token			*ft_lstnext_tokentype_pipeline(t_pipeline *lst,
					t_token_type type, t_token *current, t_pipeline **pipeline);
char			*ft_lstfind_type_pipeline(t_pipeline *pipeline,
					t_token_type type);
/* t_env */
void			ft_lstadd_back_env(t_env **lst, t_env *new);
void			ft_lstclear_env(t_env **lst);
t_env			*ft_lstfind_env(t_env **env, char *name);
t_env			*ft_lstlast_env(t_env *lst);
t_env			*ft_lstnew_env(char *name, char *value, int equal_sign);
int				ft_lstreplace_env(t_env **env, char *name, char *value);
int				ft_lstsize_env(t_env *lst);
int				ft_lstremove_env(t_env **lst, t_env *env);

/*
** Update env variable or add it if it doesn't exist
** ./utils/t_env/ft_lstupsert_env.c
*/
int				ft_lstupsert_env(t_env **env, char *name, char *value,
					int equal_sign);

/*
** Insert env variable and if it already exists, do nothing
** ./utils/t_env/ft_lstinsert_env.c
*/
int				ft_lstinsert_env(t_env **env, char *name, char *value,
					int equal_sign);

/* utils */
int				ft_2d_strlen(char **array);
void			ft_free_array(void **array);

void			ft_free_mini(t_mini *mini);

/* ================================= DEBUG ================================= */
void			print_env(t_mini *mini);
void			print_history(t_list *history);
void			print_2d_array(char **str);
void			print_pipeline(t_mini *mini);
void			print_tokens(t_token *token);

#endif