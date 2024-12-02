/*
 * ________________________________________________________________________________
 * |  File: history.c
 * |  Project: source
 * |  File Created: Wednesday, 20th November 2024 10:47 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../includes/yosh_i.h"

void	load_history(t_cmd *cmd)
{
	if (read_history(cmd->yosh_history) != 0)
		printf("Unable to load history file\n");
}

void	save_history(t_cmd *cmd)
{
	if (write_history(cmd->yosh_history) != 0)
		printf("Unable to save history file\n");
}
