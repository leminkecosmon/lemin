#include "lemin.h"

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
	ft_printf("\n\n%d", start);
	while (--i >= 0)
	{
		ft_printf("->%d->", path[i]);
	}
	ft_printf("%d\n", save);
}

void		bfs(t_lemin *e)
{
	int x;
	int y;
	int stack[e->nb_rooms - 1];
	int	visited[e->nb_rooms];
	int prev[e->nb_rooms - 1];
	int i;

	y = 0;
	x = e->start->nb_rooms;
	i = -1;
	while (++i < e->nb_rooms - 1)
	{
		stack[i] = -1;
		visited[i] = 0;
		prev[i] = 0;
	}
	visited[i] = 0;
	visited[x] = 1;
	while (x != e->end->nb_rooms)
	{
		y = 0;
		while (y < e->nb_rooms)
		{
			if (e->map[x][y] == 1 && !visited[y])
				push_stack(stack, y, e->nb_rooms, prev, x);
			y++;
		}
		ft_printf("\n\n");
		i = -1;
		while (++i < e->nb_rooms - 1)
		{
			ft_printf("%d ", stack[i]);
		}
		x = stack[0];
		if (x == e->end->nb_rooms)
			break ;
		visited[x] = 1;
		pop_stack(stack, e->nb_rooms);
	}
	print_path(prev, e->start->nb_rooms, e->end->nb_rooms, e->nb_rooms);
}