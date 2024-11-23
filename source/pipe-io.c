/*
 * ________________________________________________________________________________
 * |  File: pipe-io.c
 * |  Project: source
 * |  File Created: Wednesday, 20th November 2024 10:47 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../includes/yosh_i.h"

int	out_command(t_cmd *cmd)
{
	if (cmd->io_dup_out)
		return (0);
	cmd->fd_stdout = dup(STDOUT_FILENO);
	cmd->fd_to_pipe = open(cmd->to_pipe,
			O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (cmd->fd_to_pipe == -1)
		perror("Error: to_pipe !open");
	dup2(cmd->fd_to_pipe, STDOUT_FILENO);
	cmd->pump = 0;
	return (1);
}

int	in_command(t_cmd *cmd)
{
	cmd->io_cross_in = 1;
	reset_io(cmd);
	cmd->fd_stdin = dup(STDIN_FILENO);
	cmd->fd_from_pipe = open(cmd->to_pipe, O_RDONLY);
	if (cmd->fd_from_pipe == -1)
		perror("Error: from_pipe !open");
	dup2(cmd->fd_from_pipe, STDIN_FILENO);
	cmd->pump = 1;
	return (1);
}
