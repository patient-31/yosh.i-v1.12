/*
 * ________________________________________________________________________________
 * |  File: env.c
 * |  Project: source
 * |  File Created: Sunday, 24th November 2024 03:57 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../includes/yosh_i.h"


char	*get_prog_path(char *prog_name, t_program *c)
{
	char	**paths;
	char	*fallback;
	int		i;

	fallback = strdup(ft_strjoin("/usr/bin/", prog_name));
	if (path_attached(prog_name))
		return (prog_name);
	i = 0;
	paths = split(retrv_envv("PATH", c), ':');
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		paths[i] = ft_strjoin(paths[i], prog_name);
		if (access(paths[i], F_OK) == 0)
			return (paths[i]);
		i++;
	}
	return (fallback);
}

int	path_attached(char *prog_name)
{
	if (access(prog_name, F_OK) == 0)
		return (1);
	else
		return (0);
}

char	*retrv_envv(char *envvar, t_program *c)
{
	int		len;
	char	*out;
	int		e;

	e = 0;
	out = NULL;
	len = strlen(envvar);
	while (c->env_c[e])
	{
		if (strncmp(c->env_c[e], envvar, len) == 0)
			out = env_grab_value(c->env_c[e], len);
		e++;
	}
	if (!out)
		return ("\0");
	return (out);
}

char	*env_grab_value(char *environitem, int len)
{
	char	*out;
	int		item_len;
	int		i;
	int		o;

	item_len = strlen(environitem);
	i = len + 1;
	o = 0;
	out = malloc(sizeof(char) * (item_len - len + 1));
	while (environitem[i])
	{
		out[o] = environitem[i];
		o++;
		i++;
	}
	out[o] = '\0';
	return (out);
}


int	rm_envv(char *envvar, t_program *c)
{
	int	i;

	i = 0;
	while (c->env_c[i])
	{
		if (strncmp(envvar, c->env_c[i], strlen(envvar)) == 0)
			if (c->env_c[i][strlen(envvar)] == '=')
				return (contract_env(i, c));
		i++;
	}
	return (0);
}

int	contract_env(int index, t_program *c)
{
	int		i;
	int		q;
	char	**copy;

	i = 0;
	q = 0;
	if (c->env_c[index + 1] == NULL)
		c->env_c[index] = NULL;
	copy = malloc(sizeof(char *) * (ft_lstlen(c->env_c) + 1));
	if (!copy)
		return (0);
	while (c->env_c[q])
	{
		if (i == index)
			q++;
		copy[i] = strdup(c->env_c[q]);
		i++;
		q++;
	}
	copy[i] = NULL;
	c->env_c = tabdup(copy);
	free_2d_char(copy);
	return (1);
}

int	add_envv(char *envvar, t_program *c)
{
	int		i;
	char	**temp;

	i = 0;
	if (error_check_add_envv(envvar))
		return (-1);
	if (update_envv(envvar, c))
		return (1);
	temp = tabdup(c->env_c);
	c->env_c = malloc(sizeof(char *) * (ft_lstlen(temp) + 2));
	while (temp[i])
	{
		c->env_c[i] = strdup(temp[i]);
		i++;
	}
	c->env_c[i++] = strdup(envvar);
	c->env_c[i] = NULL;
	free_2d_char(temp);
	return (1);
}

int	error_check_add_envv(char *envvar)
{
	int	i;
	int	q;

	q = 0;
	i = 0;
	if (envvar[0] == '?' && envvar[1] == '=')
		return (0);
	if (envvar[0] >= '0' && envvar[0] <= '9')
		return (1);
	while (envvar[i])
	{
		if (envvar[i] == '=')
			q++;
		i++;
	}
	if (q != 1)
		return (1);
	if (envv_naming_check(envvar))
		return (1);
	return (0);
}

int	update_envv(char *envvar, t_program *c)
{
	int	i;
	int	len;

	len = envvar_len(envvar);
	i = 0;
	while (c->env_c[i])
	{
		if (strncmp(envvar, c->env_c[i], len) == 0
			&& c->env_c[i][len] == '=')
		{
			c->env_c[i] = strdup(envvar);
			return (1);
		}
		i++;
	}
	return (0);
}


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
