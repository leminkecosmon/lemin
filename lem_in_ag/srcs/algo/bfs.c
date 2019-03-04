/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agesp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:59:44 by agesp             #+#    #+#             */
/*   Updated: 2019/03/04 14:15:34 by agesp            ###   ########.fr       */
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

void		push_stack(int *stack, int room, int nb_rooms)
{
	int i;

	i = 0;
	while (stack[i] != -1 && i < nb_rooms - 1)
		i++;
	stack[i] = room;
}	

void		bfs(t_lemin *e)
{
	int start;
	int end;
	int x;
	int y;
	int stack[e->nb_rooms - 1];
	int i;

	start = 0;
	end = 9;
	y = 0;
	x = 0;
	i = -1;
	while (++i < e->nb_rooms - 1)
		stack[i] = -1;
	while (x != end)
	{
		y = 0;
		while (y < e->nb_rooms)
		{
			if (e->map[x][y] == 1)
				push_stack(stack, y, e->nb_rooms);
				i = -1;
			y++;
		}
		printf("\nin x\n");
		while (++i < e->nb_rooms - 1)
		{
			printf("%d ", stack[i]);
		}
		x = stack[0];
		if (x == end)
			break ;
		pop_stack(stack, e->nb_rooms);
		i = -1;
	}
	printf("start %d end %d\n", e->nb_rooms, e->end->etage);
}
