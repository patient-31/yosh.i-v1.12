/*
 * ________________________________________________________________________________
 * |  File: main.c
 * |  Project: source
 * |  File Created: Friday, 22nd November 2024 04:28 pm
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

# include "../includes/_emerald_.h"

int main (int argc, char **argv, char **env)
{
    (void)env;
    (void)argv;
    (void)argc;

    t_program *c;
    c = malloc(sizeof(t_program));
    
    if (!c) {
        fprintf(stderr, "Memory Allocation Failed");
        return (1);
    }
    c->prompt = "> ";
    char *line_read;
    while (1)
    {
        line_read = readline(c->prompt);
        printf("%s", line_read);
        break ;
    }
    cleanup(c);
}