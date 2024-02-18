
#include "minishell.h"

static int is_valid_identifier(const char *str)
{
	int	i;

	i = 0;
    if (!ft_isalpha(str[i]) && str[i] != '_')
        return (0);
    i++;
	while (str[i] != '\0')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
    return (1);
}

static void	print_export(t_mini *mini)
{
	t_env	*env;

	env = mini->env;
	while (env)
	{
		if (env->name && env->value)
			ft_printf("%s %s=\"%s\"\n", EXPORT_BUILTIN_PRINT_ENV, \
				env->name, env->value);
		else if (env->name && !env->value)
			ft_printf("%s %s\n", EXPORT_BUILTIN_PRINT_ENV, \
				env->name);
		env = env->next;
		if (env == mini->env)
			break ;
	}
}

static int	is_valid_env(char **env)
{
	int	i;

	if (ft_2d_strlen(env) == 0 || ft_2d_strlen(env) > 2)
		return (0);
	if (!is_valid_identifier(env[0]))
		return (0);
	i = 0;
	print_2d_array(env);
	while (env[1] && env[1][i])
	{
		if (env[1][i] == '=')
			return (0);
		i++;
	}
	return (1);
}

static void	add_env(t_mini *mini, t_pipeline *pipeline)
{
	int		i;
	char	**env;

	i = 1;
	while (pipeline->args[i])
	{
		env = ft_split(pipeline->args[i], "=");	
		if (!env)
			return ; // TODO handle error EXIT !!!!!
		if (!is_valid_env(env))
		{
			mini->exec_status = 1;
			ft_dprintf("%sexport: `%s': not a valid identifier\n", SHELL, \
				pipeline->args[i]);
			ft_free_array((void **)env);
		}
		else
		{
			// ft_lstadd_back_env(&mini->env, ft_lstnew_env(env[0], env[1]));
			ft_free_array((void **)env);
		}
		i++;
	}
}

void	export_builtin(t_mini *mini, t_pipeline *pipeline)
{
	ft_printf("export_builtin\n");
	if (pipeline->args[1] == NULL)
		print_export(mini);
	else if (pipeline->args[1] != NULL && pipeline == ft_lstlast_pipeline(mini->pipeline))
		add_env(mini, pipeline);
}
