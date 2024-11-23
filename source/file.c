/*
 * ________________________________________________________________________________
 * |  File: file.c
 * |  Project: source
 * |  File Created: Wednesday, 20th November 2024 10:47 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../includes/yosh_i.h"

int	is_valid_filename(char *input)
{
	int	i;

	i = 0;
	if (!input)
		return (0);
	while (input[i])
	{
		if (input[i] == '<'
			|| input[i] == '>'
			|| input[i] == '*'
			|| input[i] == '?'
			|| input[i] == '|')
		{
			printf("\e[1;31mPlease Exclude '<', '>', '|', '?' , '*' From");
			printf(" Filenames.\e[0;32m\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	close_files(t_cmd *cmd)
{
	close(cmd->fd_from_pipe);
	close(cmd->fd_here);
	close(cmd->fd_infile);
	close(cmd->fd_outfile);
	close(cmd->fd_stdin);
	close(cmd->fd_stdout);
	close(cmd->fd_to_pipe);
}
