/*
 * ________________________________________________________________________________
 * |  File: setup.c
 * |  Project: source
 * |  File Created: Wednesday, 20th November 2024 10:47 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../includes/yosh_i.h"

void	entry_message(void)
{
	printf("⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥ yosh.i    Your Shell  ");
	printf(" ⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤\n");
	printf("___________________________interactive");
	printf("__________________________\n");
	sleep(1);
}

int	check_4_semi_bslash(char *check)
{
	int	i;

	i = 0;
	while (check[i])
	{
		if (check[i] == 0134 || check[i] == 073)
		{
			printf("'%c' Cannot be Interpreted\n", check[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	cmd_input(t_cmd *cmd, t_norm *norm)
{
	char	*buffer;

	cmd->rl_yn = 1;
	sig_read_handle(cmd);
	set_prompt(cmd);
	buffer = readline(cmd->prompt->prompt);
	if (buffer)
	{
		if (is_whitespace(buffer))
			return (0);
		add_history(buffer);
		ft_strlcpy(cmd->input, buffer, INLEN);
		free(buffer);
		if (check_4_semi_bslash(cmd->input))
			return (0);
		return (ft_strlen(cmd->input));
	}
	else if (!buffer)
	{
		save_history(cmd);
		printf("exiting\n");
		exitshell(cmd, norm);
	}
	return (0);
}
