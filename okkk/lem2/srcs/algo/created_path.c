/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agesp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:59:44 by agesp             #+#    #+#             */
/*   Updated: 2019/03/06 17:04:29 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"


void		reset_tab(int *stack, int *visited, int *prev, t_lemin *e, int *s)
{
	int i;

	i = -1;
	while (++i < e->nb_rooms - 1)
	{
		stack[i] = -1;
		visited[i] = s[i];
		prev[i] = 0;
	}
	visited[i] = s[i];
}

int			paths_remain(t_lemin *e, int *find_new)
{
	int i;

	i = 0;
	while (i < e->nb_rooms)
	{
		if (e->map[e->nb_start][i] == 1 && !find_new[i])
			return (1);
		i++;
	}
	return (0);
}

int			is_stack_empty(int *stack, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (stack[i] != -1)
			return (0);
		i++;
	}
	return (1);
}

void		set_bfs_base_var(int *find_new, t_lemin *e)
{
	int i;

	i = -1;
	if (!(e->p = malloc(sizeof(t_path))))
		return ;
	e->p->next = NULL;
	while (++i < e->nb_rooms)
		find_new[i] = 0;
	e->head_to_p = e->p;
}

void		print_paths(t_lemin *e)
{
	int i;

	e->p = e->head_to_p;
	while (e->p)
	{
		ft_printf("\npath_len : %d\n", e->p->size_path);
		i = -1;
		while (++i < e->p->size_path - 1)
			ft_printf("%d->", e->p->path[i]);
		ft_printf("%d\n", e->p->path[e->p->size_path - 1]);
		i = -1;
		while (++i < e->p->size_path - 1)
			ft_printf("%s->", e->table_r[e->p->path[i]]->name);
		ft_printf("%s\n\n", e->table_r[e->p->path[e->p->size_path - 1]]->name);
		if (!e->p->next)
			break ;
		e->p = e->p->next;
	}
}

void		discover_more_paths(int *find_new, t_lemin *e)
{
	int		i;
	t_path	*save;
	int		get_path;
	int		j;

	i = -1;
	get_path = -1;
	save = e->head_to_p;
	while (++i < e->p->size_path - 1)
		if (find_new[get_path = e->p->path[i]] == 1)
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
							find_new[save->path[j]] = 0;
				save = save->next;
			}
		}
}


void		bfs(t_lemin *e)
{
	int stack[e->nb_rooms - 1];
	int	visited[e->nb_rooms];
	int prev[e->nb_rooms - 1];
	int	find_new[e->nb_rooms];

	set_bfs_base_var(find_new, e);
	while (paths_remain(e, find_new))
	{
		e->x = e->nb_start;
		reset_tab(stack, visited, prev, e, find_new);
		visited[e->x] = 1;
		while (e->x != e->nb_end)
		{
			e->y = 0;
			while (e->y < e->nb_rooms)
			{
				if (e->map[e->x][e->y] == 1 && !visited[e->y])
					push_stack(stack, e, prev);
				e->y++;
			}
			e->x = stack[0];
			if (e->x == e->nb_end || is_stack_empty(stack, e->nb_rooms - 1))
				break ;
			visited[e->x] = 1;
			pop_stack(stack, e->nb_rooms);
		}
		if (is_stack_empty(stack, e->nb_rooms - 1))
			break ;
		find_new[add_path(prev, e)] = 1;
		discover_more_paths(find_new, e);
		ft_putnbr(e->map[0][4]);
	}
	print_paths(e);
}