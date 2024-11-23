/*
 * ________________________________________________________________________________
 * |  File: utils.c
 * |  Project: source
 * |  File Created: Saturday, 23rd November 2024 07:33 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

# include "../includes/yosh_i.h"

bool	is_whitespace(char *s)
{
	int	i;
	int	len;

	len = strlen(s);
	i = 0;
	while (s[i])
	{
		if (i != len)
		{
			if (s[i] != ' ')
				return (false);
			i++;
		}
	}
	return (true);
}

void	*malloc_strlen_n(unsigned int c, va_list arg)
{
	unsigned int size;
	va_list arg_copy;

	va_copy(arg_copy, arg);
	size = 0; 
	while (c)
	{
		size += strlen(va_arg(arg_copy, char *));
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

bool is_quote(char c)
{
	return (c == '\'' || c == '"');
}

char	**split(char const *s, char c) // splits strings into 2d array using delimiter c
{
	char	**split;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s)
		return (0);
	k = wordcount(s, c);
	split = malloc(sizeof(char *) * (k + 1));
	if (!split)
		return (0);
	i = 0;
	j = 0;
	while (i < k)
	{
		while (s[j] == c)
			j++;
		s = &s[j];
		j = 0;
		while (s[j] != c && s[j])
			j++;
		split[i++] = strndup(s, j);
	}
	split[i] = 0;
	return (split);
}

size_t	wordcount(char const *s, char c) // counts words in strings using delimiter c
{
	size_t	word_count;
	size_t	trigger;

	trigger = 0;
	word_count = 0;
	while (*s)
	{
		if (*s != c && trigger == 0)
		{
			trigger = 1;
			word_count++;
		}
		else if (*s == c)
			trigger = 0;
		s++;
	}
	return (word_count);
}

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	str = (char *)malloc(strlen(s1) + strlen(s2) + 1);
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

int	ft_isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

size_t	ft_lstlen(char **list)
{
	size_t	i;

	i = 0;
	while (list[i])
		i++;
	return (i);
}