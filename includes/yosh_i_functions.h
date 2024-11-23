/*
 * ________________________________________________________________________________
 * |  File: _emerald__functions.h
 * |  Project: includes
 * |  File Created: Friday, 22nd November 2024 04:34 pm
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#pragma once

// BUILTIN_C

bool			check_for_builtin_commands(t_program *c);
int				echo(t_program *c);
int				cd(t_program *c);
int				pwd(void);
int				unset(t_program *c);
int				env(t_program *c);
void			cd_empty(t_program *c);
int				exports(t_program *c);
void			exitshell(t_program * c);

// ENV_C

char			*get_prog_path(char *prog_name, t_program *c);
int				path_attached(char *prog_name);
char			*retrv_envv(char *envvar, t_program *c);
char			*env_grab_value(char *environitem, int len);
int				rm_envv(char *envvar, t_program *c);
int				contract_env(int index, t_program *c);
int				add_envv(char *envvar, t_program *c);
int				error_check_add_envv(char *envvar);
int				update_envv(char *envvar, t_program *c);
int				envvar_len(char *envvar);
int				envv_naming_check(char *envvar);


// FREE_C
void			free_2d_char(char **f);
void			cleanup(t_program *c);
void			error_exit(const char *mess, int error_type, t_program *c, p_cleanup_function cleanup);
void			mem_error_exit(const char *mess, t_program *c);

// HISTORY_C
void			load_history(const char *yosh_history);
void			save_history(const char *yosh_history);

// PRINT_C
void			print_list_2d(char **list);
unsigned int	lstlen(char **list);
char			**tabdup(char **t1);

// PROCESS_C
int				process(char *command, t_program *c);
void 			execute_commands(char *command, t_program *c);

// UTILS_C
bool			is_whitespace(char *s);
void			*malloc_strlen_n(unsigned int c, va_list arg);
char			*strjoin_e(unsigned int c, ...);
char			**split(char const *s, char c);
size_t			wordcount(char const *s, char c);
char			*ft_strjoin(char *s1, char *s2);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
size_t			ft_lstlen(char **list);
bool 			is_quote(char c);
