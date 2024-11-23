/*
 * ________________________________________________________________________________
 * |  File: builtin2.c
 * |  Project: source
 * |  File Created: Wednesday, 20th November 2024 10:47 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../includes/yosh_i.h"

int	unset(t_cmd *cmd)
{
	if (!cmd->tokens[2])
		if (rm_envv(cmd->tokens[1], cmd) == 0)
			printf("Failed\n");
	return (1);
}

int	env(t_cmd *cmd)
{
	print_list_2d(cmd->environ);
	return (1);
}

void	cd_empty(t_cmd *cmd)
{
	if (chdir(retrv_envv("HOME", cmd)) == 0)
	{
		add_envv(ft_strjoin("OLDPWD=", retrv_envv("PWD", cmd)), cmd);
		add_envv(ft_strjoin("PWD=", retrv_envv("HOME", cmd)), cmd);
	}
}

int	exports(t_cmd *cmd)
{
	if (!cmd->tokens[2])
		if (add_envv(cmd->tokens[1], cmd) == -1)
			printf("Failed\n");
	return (1);
}
