/*
 * ________________________________________________________________________________
 * |  File: free.c
 * |  Project: source
 * |  File Created: Friday, 22nd November 2024 05:16 pm
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

# include "../includes/_emerald_.h"

void	cleanup(t_program *c)
{
	free(c);
}