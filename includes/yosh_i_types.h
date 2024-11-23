/*
 * ________________________________________________________________________________
 * |  File: _emerald__types.h
 * |  Project: includes
 * |  File Created: Friday, 22nd November 2024 04:35 pm
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#pragma once

typedef	void					t_cleanup_function;

typedef struct s_emerald
{
	char	**tokens;
    char    *prompt;
	char	*username;
	char	hostname[256];
	char	**env_c;
} t_program;

typedef	void		(*p_cleanup_function)(t_program *);