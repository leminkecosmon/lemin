/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agesp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:59:44 by agesp             #+#    #+#             */
/*   Updated: 2019/03/18 10:46:33 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#include <stdio.h>

void		reset_tab(t_lemin *e)
{
	int i;

	i = -1;
	while (++i < e->nb_rooms - 1)
	{
		e->stack[i] = -1;
		e->visited[i] = e->find_new[i];
		e->prev[i] = 0;
	}
	e->visited[i] = e->find_new[i];
	e->visited[e->nb_start] = 1;
}

void		discover_more_paths(t_lemin *e, t_path *s)
{
	int		i;
	t_path	*save;
	int		get_path;
	int		j;

	i = -1;
	get_path = -1;
	save = s;
	while (++i < e->p->size_path - 1)
		if (e->find_new[get_path = e->p->path[i]] == 1)
		{
			while (save)
			{
				j = -1;
				if (save->next && save == e->p)
					save = save->next;
				if (!save->next && save == e->p)
					break ;
				while (++j < save->size_path - 1)
					if (save->path[j] == get_path)
						while (++j < save->size_path - 1)
							e->find_new[save->path[j]] = 0;
				save = save->next;
			}
		}
}

void		create_single(t_lemin *e)
{
	if (e->map[e->nb_start][e->nb_end] == 1)
	{
		if (!(e->p->path = malloc(sizeof(int) * 2)))
			exit(-1);
		e->p->path[0] = e->nb_start;
		e->p->path[1] = e->nb_end;
		e->p->next = NULL;
		e->p->size_path = 2;
	}
}

void		control_stack(t_lemin *e)
{
	e->y = -1;
	while (++e->y < e->nb_rooms)
		if (e->map[e->x][e->y] == 1 && !e->visited[e->y])
			push_stack(e);
	e->x = e->stack[0];
}

void		bfs(t_lemin *e)
{
	t_path *save;

	set_bfs_base_var(e);
	create_single(e);
	save = e->p;
	while (paths_remain(e) && e->map[e->nb_start][e->nb_end] == 0)
	{
		e->x = e->nb_start;
		reset_tab(e);
		while (e->x != e->nb_end)
		{
			control_stack(e);
			if (e->x == e->nb_end || is_stack_empty(e->stack, e->nb_rooms - 1))
				break ;
			e->visited[e->x] = 1;
			pop_stack(e, e->nb_rooms);
		}
		if (is_stack_empty(e->stack, e->nb_rooms - 1))
			break ;
		e->find_new[add_path(e)] = 1;
		discover_more_paths(e, save);
	}
	print_paths(e, save);
	e->p = save;
}
