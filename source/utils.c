/*
 * ________________________________________________________________________________
 * |  File: utils.c
 * |  Project: source
 * |  File Created: Wednesday, 20th November 2024 10:47 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

# include "../includes/yosh_i.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*out;
	size_t	i;

	out = malloc(n + 1);
	if (!out)
		return (0);
	i = 0;
	while (i < n && s[i])
	{
		out[i] = s[i];
		i++;
	}
	while (i <= n)
		out[i++] = 0;
	return (out);
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

unsigned int	ft_numlen(int n)
{
	unsigned int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len += 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	num;
	unsigned int	len;

	len = ft_numlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		num = -n;
	}
	else
		num = n;
	if (num == 0)
		str[0] = '0';
	str[len] = '\0';
	while (num != 0)
	{
		str[len - 1] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (str);
}

size_t	ft_lstlen(char **list)
{
	size_t	i;

	i = 0;
	while (list[i])
		i++;
	return (i);
}


static size_t	ft_wordcnt(char const *s, char c)
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

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s)
		return (0);
	k = ft_wordcnt(s, c);
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
		split[i++] = ft_strndup(s, j);
	}
	split[i] = 0;
	return (split);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strdup(const char *s1)
{
	char			*ptr;
	unsigned int	i;

	i = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}


char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	j;

	j = 0;
	if (dstsize != 0)
	{
		while ((src[j] != '\0') && (j < dstsize - 1))
		{
			dst[j] = src[j];
			j++;
		}
		dst[j] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}


char	**ft_tabdup(char **in)
{
	int		i;
	char	**out;

	i = 0;
	out = malloc (sizeof(char *) * (ft_lstlen(in) + 1));
	if (!out)
		return (NULL);
	while (in[i])
	{
		out[i] = ft_strdup(in[i]);
		i++;
	}
	out[i] = NULL;
	return (out);
}

bool	is_whitespace(char *s)
{
	int	i;
	int	len;

	len = ft_strlen(s);
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
	unsigned int			size;
	va_list		arg_copy;
	char			*out;

	va_copy(arg_copy, arg);
	size = 0;
	while (c)
	{
		size += ft_strlen(va_arg(arg_copy, char *));
		c--;
	}
	va_end(arg_copy);
	out = malloc(sizeof(char) * (size + 1));
	return (out);
}

char	*strjoin_e(unsigned int c, ...)
{
	va_list		arg;
	char			*dcse2;
	char			*tmp;
	unsigned int			i;
	unsigned int			j;

	va_start(arg, c);
	dcse2 = malloc_strlen_n(c, arg);
	j = 0;
	if (!dcse2)
	{
		va_end(arg);
		free(dcse2);
		return (NULL);
	}
	while (c)
	{
		i = 0;
		tmp = va_arg(arg, char *);
		while (tmp[i])
			dcse2[j++] = tmp[i++];
		c--;
	}
	dcse2[j] = '\0';
	va_end(arg);
	return (dcse2);
}
