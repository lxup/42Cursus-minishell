
#include "minishell.h"

static int	is_out_long(char *str, int sign)
{
	if (sign == -1)
	{
		if (ft_strcmp(str, "9223372036854775808") < 0)
			return (1);
	}
	else
	{
		if (ft_strcmp(str, "9223372036854775807") > 0)
			return (1);
	}
	return (0);
}

static int	numeric_arg(char *str)
{
	size_t	i;
	int		sign;

	i = 0;
	if (str == NULL)
		return (i);
	while (str[i] && ft_iswhitespace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (is_out_long(str + i, sign))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_arguments(t_mini *mini, t_pipeline *pipeline)
{
	int	argc;

	argc = ft_2d_strlen(pipeline->args);
	if (argc > 1 && !numeric_arg(pipeline->args[1]))
	{
		ft_dprintf("%s%s: %s: %s\n", SHELL, pipeline->args[0], pipeline->args[1], "numeric argument required");
		mini->exit_code = EXIT_BUILTIN_NONUM;
	}
	else if (argc > 2)
	{
		ft_dprintf("%s%s: %s\n", SHELL, pipeline->args[0], "too many arguments");
		mini->exit_code = 1;
		return (0);
	}
	else if (argc == 2)
	{
		mini->exit_code = ft_atol(pipeline->args[1]) % 256; // CHANGE TO LONG
		if (mini->exit_code < 0)
			mini->exit_code = 256 + mini->exit_code;
	}
	return (1);
}

void	exit_builtin(t_mini *mini, t_pipeline *pipeline)
{
	ft_printf("exit_builtin\n");
	mini->exit_code = 0;
	if (!check_arguments(mini, pipeline))
		return ;
	if (write(STDOUT_FILENO, "exit\n", 5) == -1)
		ft_dprintf("%s%s\n", SHELL, strerror(errno));
	ft_exit(mini);
}