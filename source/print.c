/*
 * ________________________________________________________________________________
 * |  File: print.c
 * |  Project: source
 * |  File Created: Wednesday, 20th November 2024 10:47 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../includes/yosh_i.h"

void	print_list_2d(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		printf("%s\n", list[i]);
		i++;
	}
}
