
#include "minishell.h"

void	env_builtin(t_mini *mini, t_pipeline *pipeline)
{
	t_env *env;

	ft_printf("env_builtin\n");
	if (pipeline->args[1] != NULL)
	{
		ft_dprintf("%senv: too many arguments\n", SHELL);
		return ;
	}
	env = mini->env;
	while (env)
	{
		if (env->name && env->value)
			ft_printf("%s=%s\n", env->name, env->value);
		else if (env->name && !env->value)
			ft_printf("%s=\n", env->name);
		env = env->next;
		if (env == mini->env)
			break ;
	}
}
