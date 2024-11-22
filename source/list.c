/*
 * ________________________________________________________________________________
 * |  File: list.c
 * |  Project: source
 * |  File Created: Saturday, 23rd November 2024 06:33 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */


# include "../includes/_emerald_.h"

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


unsigned int	lstlen(char **list)
{
	unsigned int	i;

	i = 0;
	while (list[i])
		i++;
	return (i);
}

char	**tabdup(char **t1)
{
	unsigned int	i;
	char			**t2;

	i = 0;
	t2 = malloc(sizeof(char *) * (lstlen(t1) + 1));
	if (!t2)
		return (NULL);
	while (t1[i])
	{
		t2[i] = strdup(t1[i]);
		i++;
	}
	t2[i] = NULL;
	return (t2);
}