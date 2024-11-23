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
	c->tokens = split(command, ' ');
	if (check_for_builtin_commands(c))
		return 1;
	// execute_commands(command, c);
	return 1;
}





void	execute_commands(char *command, t_program *c)
{
	(void)c;
	(void)command;
}
