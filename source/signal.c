/*
 * ________________________________________________________________________________
 * |  File: signal.c
 * |  Project: source
 * |  File Created: Wednesday, 20th November 2024 10:47 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../includes/yosh_i.h"

void	sig_ctrlc(int sig)
{
	if (sig)
	{
		write(2, "\n", 1);
		rl_on_new_line();
    	if (rl_line_buffer)
    	{
			rl_line_buffer[0] = '\0';  // Set the buffer to an empty string
    	}
    	rl_redisplay();  // Redisplay the updated prompt
	}
}

void	sig_sugma(int sig, siginfo_t *info, void *context)
{
	int	i;

	if (sig && info && context)
		if (sig == SIGINT || sig == SIGQUIT)
			i = -90123123;
	(void)i;
}

void	sig_ctrls(int sig)
{
	if (sig)
	{
		rl_on_new_line();
    	if (rl_line_buffer)
    	{
			rl_line_buffer[0] = '\0';  // Set the buffer to an empty string
    	}
    	rl_redisplay();  // Redisplay the updated prompt
	}
}

void	handler(int sig, siginfo_t *info, void *context)
{
	if (sig && info && context)
	{
		if (sig == SIGINT)
			sig_ctrlc(sig);
		if (sig == SIGQUIT)
			sig_ctrls(sig);
	}
}

void	sig_read_handle(t_cmd *cmd)
{
	struct sigaction	srh;

	srh.sa_flags = SA_SIGINFO;
	sigemptyset(&srh.sa_mask);
	if (cmd->rl_yn == 1)
		srh.sa_sigaction = handler;
	if (cmd->rl_yn == 0)
		srh.sa_sigaction = sig_sugma;
	sigaction(SIGINT, &srh, NULL);
	sigaction(SIGQUIT, &srh, NULL);
}
