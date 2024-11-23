/*
 * ________________________________________________________________________________
 * |  File: env3.c
 * |  Project: source
 * |  File Created: Wednesday, 20th November 2024 10:47 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../includes/yosh_i.h"

int	envvar_len(char *envvar)
{
	int	i;

	i = 0;
	while (envvar[i] != '=')
		i++;
	return (i);
}

int	envv_naming_check(char *envvar)
{
	int	i;

	i = 0;
	while (envvar[i] != '=')
	{
		if (envvar[i] != '_' && !ft_isalpha(envvar[i])
			&& !ft_isdigit(envvar[i]))
			return (1);
		i++;
	}
	return (0);
}
