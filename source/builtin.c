/*
 * ________________________________________________________________________________
 * |  File: builtin.c
 * |  Project: source
 * |  File Created: Sunday, 24th November 2024 03:48 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

# include "../includes/yosh_i.h"


bool	check_for_builtin_commands(t_program *c)
{
	if (strcmp(c->tokens[0], "exit") == 0)
		exitshell(c);
	else if (strcmp(c->tokens[0], "cd") == 0)
		return (cd(c));
	else if (strcmp(c->tokens[0], "pwd") == 0)
		return (pwd());
	else if (strcmp(c->tokens[0], "export") == 0)
		return (exports(c));
	else if (strcmp(c->tokens[0], "unset") == 0)
		return (unset(c));
	else if (strcmp(c->tokens[0], "env") == 0)
		return (env(c));
	else if (strcmp(c->tokens[0], "echo") == 0)
		return (echo(c));
	return (true);
}

int	echo(t_program *c)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (!c->tokens[1])
		return (printf("\n"));
	if (strcmp(c->tokens[1], "-n") == 0)
	{
		i = 2;
		flag = 1;
	}
	while (c->tokens[i])
	{
		printf("%s", c->tokens[i]);
		if (c->tokens[i + 1])
			printf(" ");
		i++;
	}
	if (!flag)
		printf("\n");
	return (1);
}

int	cd(t_program *c)
{
	char	cwd[1024];

	getcwd(cwd, sizeof(cwd));
	if (!c->tokens[1])
		cd_empty(c);
	else if (!c->tokens[2])
	{
		if (chdir(c->tokens[1]) == 0)
		{
			getcwd(cwd, sizeof(cwd));
			add_envv(ft_strjoin("OLDPWD=", retrv_envv("PWD", c)), c);
			add_envv(ft_strjoin("PWD=", cwd), c);
		}
	}
	return (1);
}

int	pwd(void)
{
	char	cwd[1024];

	getcwd(cwd, sizeof(cwd));
	printf("%s\n", cwd);
	return (1);
}



int	unset(t_program *c)
{
	if (!c->tokens[2])
		if (rm_envv(c->tokens[1], c) == 0)
			printf("Failed\n");
	return (1);
}

int	env(t_program *c)
{
	print_list_2d(c->env_c);
	return (1);
}

void	cd_empty(t_program *c)
{
	if (chdir(retrv_envv("HOME", c)) == 0)
	{
		add_envv(ft_strjoin("OLDPWD=", retrv_envv("PWD", c)), c);
		add_envv(ft_strjoin("PWD=", retrv_envv("HOME", c)), c);
	}
}

int	exports(t_program *c)
{
	if (!c->tokens[2])
		if (add_envv(c->tokens[1], c) == -1)
			printf("Failed\n");
	return (1);
}

void	exitshell(t_program * c)
{

	save_history("yosh_history");
	cleanup(c);
	exit(0);
}
