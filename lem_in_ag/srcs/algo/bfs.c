/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agesp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:59:44 by agesp             #+#    #+#             */
/*   Updated: 2019/03/04 16:36:37 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#include <stdio.h>

void		pop_stack(int *stack, int nb_rooms)
{
	int i;

	i = 1;
	while (i < nb_rooms - 1)
	{
		stack[i - 1] = stack[i];
		i++;
	}
	stack[i - 1] = -1;
}	

void		push_stack(int *stack, int room, int nb_rooms, int *prev, int x)
{
	int i;

	i = 0;
	while (stack[i] != -1 && i < nb_rooms - 1)
	{
		if (stack[i] == room)
			return ;
		i++;
	}
	prev[room] = x;
	stack[i] = room;
}	

void		print_path(int *prev, int start, int end, int nb_rooms)
{
	int i;
	int save;
	int	path[nb_rooms];

	i = 0;
	save = end;
	while (prev[end] != start)
	{
		path[i] = prev[end];
		end = prev[end];
		i++;
	}
	printf("\n\n%d", start);
	while (--i >= 0)
	{
		printf("->%d->", path[i]);
	}
	printf("%d\n", save);
}

void		bfs(t_lemin *e)
{
	int start;
	int end;
	int x;
	int y;
	int stack[e->nb_rooms - 1];
	int	visited[e->nb_rooms];
	int prev[e->nb_rooms - 1];
	int i;

	start = 0;
	end = 9;
	y = 0;
	x = 0;
	i = -1;
	while (++i < e->nb_rooms - 1)
	{
		stack[i] = -1;
		visited[i] = 0;
		prev[i] = 0;
	}
	visited[i] = 0;
	visited[x] = 1;
	while (x != end)
	{
		y = 0;
		while (y < e->nb_rooms)
		{
			if (e->map[x][y] == 1 && !visited[y])
				push_stack(stack, y, e->nb_rooms, prev, x);
			y++;
		}
		printf("\n\n");
		i = -1;
		while (++i < e->nb_rooms - 1)
		{
			printf("%d ", stack[i]);
		}
		x = stack[0];
		if (x == end)
			break ;
		visited[x] = 1;
		pop_stack(stack, e->nb_rooms);
	}
	print_path(prev, start, end, e->nb_rooms);
}
