/*
 * ________________________________________________________________________________
 * |  File: strjoin_e.c
 * |  Project: source
 * |  File Created: Saturday, 23rd November 2024 01:37 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

# include "../includes/_emerald_.h"

unsigned int	ft_strlen(char *s)
{
	unsigned int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*malloc_strlen_n(unsigned int c, va_list arg)
{
	unsigned int size;
	va_list arg_copy;

	va_copy(arg_copy, arg);
	size = 0; 
	while (c)
	{
		size += ft_strlen(va_arg(arg_copy, char *));
		c--;
	}
	va_end(arg_copy);
	return (malloc(sizeof(char) * (size + 1)));
}

char	*strjoin_e(unsigned int c, ...)
{
	va_list arg;
	char	*out;
	char	*tmp;
	int		i;
	int		j;

	va_start(arg, c);
	out = malloc_strlen_n(c, arg);
	j = 0;
	if (!out)
	{
		va_end(arg);
		return (0);
	}
	while (c)
	{
		i = 0;
		tmp = va_arg(arg, char *);
		while (tmp[i])
		{
			out[j] = tmp[i];
			j++;
			i++;
		}
		c--;
	}
	out[j] = '\0';
	va_end(arg);
	return (out);
}


