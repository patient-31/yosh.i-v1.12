/*
 * ________________________________________________________________________________
 * |  File: main.c
 * |  Project: source
 * |  File Created: Friday, 22nd November 2024 04:28 pm
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

# include "../includes/yosh_i.h"

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
		load_history("yosh_history");

		t_program *c;
		c = malloc(sizeof(t_program));
		if (!c) {
			error_exit("Memory Allocation for t_program", MEMORY_ALLOCATION_ERROR, c, cleanup);
		}
		set_variables(c, envp);
		
		char *input;
		while (1)
		{
			input = readline(c->prompt);
			if (input == NULL)
			{
				printf("\nThanks from the developer of yosh.i v2.0!");
				cleanup(c);
				exit(0);
			}
			if (is_whitespace(input))
			{
				free(input);
				continue ;
			}	
			add_history(input);


			char *command = strtok(input, ";");
			while (command)
			{
				if (!process(command, c))
					break ;
				command = strtok(NULL, ";");
			}
			save_history("yosh_history");
			free(input);
		}
		cleanup(c);
	}
}

