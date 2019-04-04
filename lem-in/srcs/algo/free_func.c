/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agesp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:38:39 by agesp             #+#    #+#             */
/*   Updated: 2019/04/04 11:36:41 by agesp            ###   ########.fr       */
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
	if (e->h)
	{
		while (e->h[++i])
		{
			free_rooms(e->h[i]->r);
			free(e->h[i]);
		}
		free(e->h);
	}
}	
