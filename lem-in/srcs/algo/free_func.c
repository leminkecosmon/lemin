/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agesp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:38:39 by agesp             #+#    #+#             */
/*   Updated: 2019/04/03 13:47:42 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_path		*free_path(t_path *p, int realloc, t_lemin *e)
{
	t_path	*save;

	while (p)
	{
		save = p;
		p = p->next;
		if (save->path)
		{
			free(save->path);
			save->path = NULL;
		}
		free(save);
	}
	if (realloc)
	{
		if (!(p = malloc(sizeof(t_path))))
			lem_in_error(e, 1);
		p->next = NULL;
		p->path = NULL;
		return (p);
	}
	return (NULL);
}

void			free_ants(t_lemin *e)
{
	t_ants *a;

	while (e->a)
	{
		a = e->a;
		e->a = e->a->next;
		if (a->p)
			free_path(a->p, 0, e);
		free(a);
	}
}

void			path_fun_free(t_lemin *e)
{
	if (e->p)
		free_path(e->p, 0, e);
	if (e->find_new)
	{
		free(e->stack);
		free(e->map_stack);
		free(e->find_new);
		free(e->map_fn);
		free(e->prev);
		free(e->map_prev);
		free(e->visited);
		free(e->map_visited);
	}
}

void			free_info(t_lemin *e)
{
	t_info *i;

	while (e->i)
	{
		i = e->i;
		e->i = e->i->next;
		if (i->line)
			free(i->line);
		free(i);
	}
}

void			free_rooms(t_rooms *p)
{
	t_rooms *save;

	while (p)
	{
		save = p;
		p = p->next;
		if (save->name)
			free(save->name);
		if (save->links)
			free(save->links); //<< need more freeing
		if (save->r_p)
			free(save->r_p);
		free(save);
	}
}

void			free_hash(t_lemin *e)
{
	int i;

	i = -1;
	while (e->h[++i])
	{
		free_rooms(e->h[i]->r);
		free(e->h[i]);
	}
	free(e->h);
}	
