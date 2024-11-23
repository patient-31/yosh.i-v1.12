/*
 * ________________________________________________________________________________
 * |  File: process.c
 * |  Project: source
 * |  File Created: Saturday, 23rd November 2024 02:02 pm
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

# include "../includes/yosh_i.h"

int	process(char *command, t_program *c)
{
	command = handle_quotes(command);
	command = expand_environment_variables(command, c);
	if (check_for_builtin_commands(command, c))
		return 1;
	execute_commands(command, c);
	return 1;
}

char	*handle_quotes(char *command)
{
	return command;
}

char	*expand_environment_variables(char *command, t_program *c)
{
	(void)c;
	return command;
}

bool	check_for_builtin_commands(char *command, t_program *c)
{
	(void)c;
	(void)command;
	return true;
}

void	execute_commands(char *command, t_program *c)
{
	(void)c;
	(void)command;
}