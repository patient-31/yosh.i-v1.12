/*
 * ________________________________________________________________________________
 * |  File: _emerald__functions.h
 * |  Project: includes
 * |  File Created: Friday, 22nd November 2024 04:34 pm
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#pragma once


// FREE_C
void			free_2d_list(char **f);
void			cleanup(t_program *c);
void			error_exit(const char *mess, int error_type, t_program *c, p_cleanup_function cleanup);
void			mem_error_exit(const char *mess, t_program *c);

// HISTORY_C
void			load_history(const char *emsh_history);
void			save_history(const char *emsh_history);

// PRINT_C
void			print_list_2d(char **list);
unsigned int	lstlen(char **list);
char			**tabdup(char **t1);

// UTILS_C
bool			is_whitespace(char *s);
void			*malloc_strlen_n(unsigned int c, va_list arg);
char			*strjoin_e(unsigned int c, ...);