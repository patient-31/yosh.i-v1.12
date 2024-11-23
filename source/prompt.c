/*
 * ________________________________________________________________________________
 * |  File: prompt.c
 * |  Project: source
 * |  File Created: Wednesday, 20th November 2024 10:47 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../includes/yosh_i.h"

void	set_prompt(t_cmd *cmd)
{
	cmd->prompt->exitstatus = ft_itoa(WEXITSTATUS(cmd->estatus));
	cmd->prompt->prompt = malloc(INLEN);
	cmd->prompt->cwd = retrv_envv("PWD", cmd);
	if (ft_strcmp(cmd->prompt->cwd, cmd->home) == 0)
		cmd->prompt->cwd = ft_strdup("~");
	gethostname(cmd->prompt->hostname, sizeof (cmd->prompt->hostname));
	cmd->prompt->username = retrv_envv("USER", cmd);
	cmd->prompt->red = strdup("\001\e[1;31m\002");
	cmd->prompt->cyan = strdup("\001\e[0;36m\002");
	cmd->prompt->green = strdup("\001\e[0;32m\002");
	cmd->prompt->white = strdup("\001\e[1;37m\002");
	cmd->prompt->out = strdup(">");
	store_prompt(cmd->prompt);
	cmd->exitstatuskey = ft_strjoin("?=", cmd->prompt->exitstatus);
	if (add_envv(cmd->exitstatuskey, cmd) == -1)
		printf("$? Not Assigned\n");
}

void	store_prompt(t_prompt *prompt)
{
	prompt->prompt = strjoin_e(16,
			prompt->cyan,
			prompt->username,
			prompt->white,
			"@",
			prompt->cyan,
			prompt->hostname,
			prompt->white,
			" :: ",
			prompt->cyan,
			basename(prompt->cwd),
			prompt->red,
			" [",
			prompt->exitstatus,
			"] ",
			prompt->out,
			prompt->green);
}
