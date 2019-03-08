/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_creation_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agesp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:41:53 by agesp             #+#    #+#             */
/*   Updated: 2019/03/08 15:32:14 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		pop_stack(t_lemin *e, int nb_rooms)
{
	int i;

	i = 1;
	while (i < nb_rooms - 1)
	{
		e->stack[i - 1] = e->stack[i];
		i++;
	}
	e->stack[i - 1] = -1;
}	

void		push_stack(t_lemin *e)
{
	int i;

	i = 0;
	while (e->stack[i] != -1 && i < e->nb_rooms - 1)
	{
		if (e->stack[i] == e->y)
			return ;
		i++;
	}
	e->prev[e->y] = e->x;
	e->stack[i] = e->y;
}	

void	create_path(t_lemin *e, int *path, int len)
{
	int j;

	j = 1;
	if (e->p->path)
	{
		if (!(e->p->next = malloc(sizeof(t_path))))
			return ;
		e->p = e->p->next;
	}
	if (!(e->p->path = (int*)ft_memalloc(sizeof(t_path) * len + 2)))
		return ;
	e->p->next = NULL;
	e->p->size_path = len + 2;
	e->p->path[len + 1] = e->nb_end;
	while (--len >= 0)
		e->p->path[j++] = path[len];
	e->p->path[0] = e->nb_start;
	e->nb_paths++;
}

int			get_nb_links(t_lemin *e, int x)
{
	int i;
	int links;

	i = 0;
	links = 0;
	while (i < e->nb_rooms)
	{
		if (e->map[x][i] == 1)
			links++;
		i++;
	}
	return (links);
}

int		add_path(t_lemin *e)
{
	int i;
	int save;
	int	*path;
	int	next_path;

	i = 0;
	path = malloc(sizeof(int) * e->nb_rooms);
	save = e->nb_end;
	next_path = -1;
	while (e->prev[save] != e->nb_start)
	{
		path[i] = e->prev[save];
		save = e->prev[save];
		next_path = next_path == -1 && get_nb_links(e, path[i])
			> 2 ? path[i] : -1;
		i++;
	}
	create_path(e, path, i);
	i = next_path == -1 ? path[0] : next_path;
	ft_printf("to_block : %d\n", i);
	return (next_path == -1 ? path[0] : next_path);
}
