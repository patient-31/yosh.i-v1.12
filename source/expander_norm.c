/*
 * ________________________________________________________________________________
 * |  File: expander_norm.c
 * |  Project: source
 * |  File Created: Wednesday, 20th November 2024 10:47 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../includes/yosh_i.h"

char	*norm_act(char *cmp, char *s, int index, t_cmd *c)
{
	if (c->n->act)
		c->n->act = append_exist(cmp, s, index, c);
	if (c->n->act == NULL)
		c->n->act = append_init(cmp, s, index);
	return (c->n->act);
}
