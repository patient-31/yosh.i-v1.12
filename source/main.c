/*
 * ________________________________________________________________________________
 * |  File: main.c
 * |  Project: source
 * |  File Created: Friday, 22nd November 2024 04:28 pm
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

# include "../includes/_emerald_.h"

void	set_variables(t_program *c, char **envp)
{
	c->env_c = tabdup(envp); // move
	if (!c->env_c)
		mem_error_exit("memory allocation for c->env", c);
	c->prompt = strjoin_e(2, "patient", " >");
	if (!c->prompt)
		mem_error_exit("memory allocation for c->prompt", c);

}

int	main(int argc, char **argv, char **envp)
{
	(void)argv;
	if (argc == 1)
	{
		using_history();
		load_history("emsh_history");

		t_program *c;
		c = malloc(sizeof(t_program));
		if (!c) {
			error_exit("Memory Allocation for t_program struct", MEMORY_ALLOCATION_ERROR, c, cleanup);
		}
		set_variables(c, envp);
		
		char *line_read;
		while (1)
		{
			line_read = readline(c->prompt);
			add_history(line_read);
			save_history("emsh_history");
			break ;
		}
		cleanup(c);
	}

}