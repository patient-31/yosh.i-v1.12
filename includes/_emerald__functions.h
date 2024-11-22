/*
 * ________________________________________________________________________________
 * |  File: _emerald__functions.h
 * |  Project: includes
 * |  File Created: Friday, 22nd November 2024 04:34 pm
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#pragma once


// FREE_C
void	cleanup(t_program *c);

// STRJOIN_E_C
unsigned int	ft_strlen(char *s);
void			*malloc_strlen_n(unsigned int c, va_list arg);
char			*strjoin_e(unsigned int c, ...);