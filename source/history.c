/*
 * ________________________________________________________________________________
 * |  File: history.c
 * |  Project: source
 * |  File Created: Saturday, 23rd November 2024 06:14 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */


#include "../includes/_emerald_.h"

void	load_history(const char *emsh_history)
{
	if (read_history(emsh_history) != 0)
		printf("Unable to load history file\n");
}

void	save_history(const char *emsh_history)
{
	if (write_history(emsh_history) != 0)
		printf("Unable to save history file\n");
}
