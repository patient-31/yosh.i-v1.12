/*
 * ________________________________________________________________________________
 * |  File: exit.c
 * |  Project: source
 * |  File Created: Wednesday, 20th November 2024 10:47 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../includes/yosh_i.h"

void	exitshell(t_cmd *cmd, t_norm *norm)
{
	unlink(cmd->temporary_heredoc);
	unlink(cmd->to_pipe);
	save_history(cmd);
	free_norm(norm);
	free_cmd(cmd);
	exit(0);
}
