/*
 * ________________________________________________________________________________
 * |  File: free.c
 * |  Project: source
 * |  File Created: Friday, 22nd November 2024 05:16 pm
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

# include "../includes/yosh_i.h"

void	error_exit(const char *mess, int error_type, t_program *c, p_cleanup_function cleanup)
{
	fprintf(stderr, "\e[1;31mError; Explicit: %s\n", mess);
	cleanup(c);
	fprintf(stderr, "Program has exited with an error code <%d>\e[0m\n", error_type);
	exit(error_type);
}

void	mem_error_exit(const char *mess, t_program *c)
{
	error_exit(mess, MEMORY_ALLOCATION_ERROR, c, cleanup);
}

void	free_2d_char(char **f)
{
	unsigned int	i;

	i = 0;
	while (f[i])
	{
		if (f[i])
			free(f[i++]);
	}
	if (f)
		free(f);
}

void	cleanup(t_program *c)
{
	if (c->prompt)
		free(c->prompt);
	if (c->env_c)
		free_2d_char(c->env_c);
	free(c);
}