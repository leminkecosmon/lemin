/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agesp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 15:31:29 by agesp             #+#    #+#             */
/*   Updated: 2019/03/08 17:05:58 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		int_chr(int *tab1, int *tab2, int len)
{
	int x;
	int y;

	x = 1;
	while (x < len)
	{
		y = 1;
		while (y < (len - 1))
		{
			if (tab1[x] == tab2[y])
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int		is_ok_path(t_lemin *e, t_path *save, int p[e->nb_paths][e->p->size_path])
{
	int x;

	if (e->x == 0)
		return (1);
	x = 0;
	while (x < e->x)
	{
		if (!int_chr(p[x], save->path, e->p->size_path))
			return (0);
		x++;
	}
	return (1);
}

void	add_npath(t_lemin *e, int p[e->nb_paths][e->p->size_path], t_path *save)
{
	e->y = 0;
	if (is_ok_path(e, save, p))
	{
		while (e->y < e->p->size_path)
		{
			p[e->x][e->y] = save->path[e->y];
			e->y++;
		}
	}
}

int	select_good_paths(t_lemin *e)
{
	t_path *save;
	int	nb_of_sp;
	int	shortest;
	int get_best_path[e->nb_paths][e->p->size_path];
	
	nb_of_sp = 0;
	save = e->p;
	e->x = 0;
	shortest = e->p->size_path;
	while (save && save->size_path == shortest && nb_of_sp < e->nb_ants)
	{
		nb_of_sp++;
		add_npath(e, get_best_path, save);
		save = save->next;
		e->x++;
	}
	e->x = 0;
	while (e->x < nb_of_sp)
	{
		e->y = 0;
		while (e->y < e->p->size_path)
		{
			ft_printf("%d ", get_best_path[e->x][e->y]);
			e->y++;
		}
		ft_printf("\n");
		e->x++;
	}
	return (1);
}

void	move_ants_forward(t_lemin *e)
{
	int		short_path;
//	int		nb_of_sp;
	t_path	*save;

	short_path = e->p->size_path;
	save = e->p;
	select_good_paths(e);
}
