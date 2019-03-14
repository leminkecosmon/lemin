/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agesp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 15:31:29 by agesp             #+#    #+#             */
/*   Updated: 2019/03/12 16:56:08 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
// #include <stdio.h>
// void 	better_path(t_path *p, t_lemin *e)
// {
// 	t_path *tmpp;

// 	tmpp = e->p;
// 	while (tmpp)
// 	{
// 		if (path_collision(p->path, tmpp->path))
// 			take_better_path(p->path, tmpp->path, e->p);
// 		tmpp = tmpp->next;
// 	}
// }

void			ft_alloc(t_lemin *e, t_path *p)
{
	t_ants	*tmp;

	tmp = e->a;
	if (!e->a->p)
	{
		e->a->p = malloc(sizeof(t_path));
		e->a->p->i = 1;
		e->a->p->size_path = p->size_path;
		e->a->p->path = malloc(sizeof(int) * p->size_path);
		ft_intcpy(e->a->p->path, p->path, p->size_path);
		e->r->next = NULL;
	}
	else
	{
		while (tmp->p)
		{
			tmp = tmp->next;
		}
		tmp->p = malloc(sizeof(t_path));
		tmp->p->i = 1;
		tmp->p->size_path = p->size_path;
		tmp->p->path = malloc(sizeof(int) * p->size_path);
		ft_intcpy(tmp->p->path, p->path, p->size_path);
	}
}

void 	call_paht(t_lemin *e, t_ants **a, t_path *p)
{
	int i;
	int count_ants;

	count_ants = 1;
	i = 1;
	while (p->path[i] && i + 1 < p->size_path && (*a)->nb_ants)
	{
		if (e->map[p->path[i]][p->path[i]] == 4 && p->conti == 0)
		{
			p->stop = 1;
			break ;
		}
		else
			e->map[p->path[i]][p->path[i]] = 4;
		count_ants++;
		i++;
	}
	if (i + 1 == p->size_path)
	{
		p->conti = 1;
	}
	while (count_ants)
	{
		(*a) = (*a)->next;
		count_ants--;
	}
}

void 	zero_vistid(t_lemin *e)
{
	t_path *p;
	int i;

	i = -1;
	p = e->p;
	while (p)
	{
			if (p->conti == 1)
				while (++i < p->size_path)
					e->table_r[p->path[i]]->occuped = 0;
			i = 0;
			p = p->next;
	}
}

void 	malloc_move(t_lemin *e, t_path *p)
{
	t_ants *a;
	t_path *tmp;

	tmp = e->p;
	a = e->a;
	while (p)
	{
		if (p->conti == 1 && p->size_path < tmp->size_path)
			tmp = p;
		p = p->next;
	}
	p = tmp;
	while (p)
	{
		if ((a && p->conti == 1))
		{
			ft_alloc(e, p);
			a = a->next;
		}
		if (p->next == NULL && a)
			p = e->p;
		else 
			p = p->next;
	}
}
void	move_ants_forward(t_lemin *e)
{
	t_path *p;
	t_ants *a;

	a = e->a;
	p = e->p;
	while (p)
	{
		call_paht(e, &a, p);
		if (!a)
			break ;
		if (p->next == NULL && a->next != NULL)
			p = e->p;
		else
			p = p->next;
	}
	malloc_move(e, p);
	a = e->a;
	while (a)
	{
		if (e->table_r[a->p->path[a->p->i]]->occuped != 2 && a->p->i < a->p->size_path)
		{
			ft_printf("L%d-%s ", a->nb_ants, e->table_r[a->p->path[a->p->i]]->name);
			e->table_r[a->p->path[a->p->i]]->occuped = 2;
			a->p->i++;
		}
		else if (a->p->i == a->p->size_path)
		{
			ft_printf("L%d-%s ", a->nb_ants, e->table_r[a->p->path[a->p->i]]->name);
			a->p->i++;
		}
		if (a->next == NULL && a->p->i < a->p->size_path)
		{
			ft_putnbr(a->nb_ants);
			ft_putchar('\n');
			zero_vistid(e);
			a = e->a;
		}
		else
			a = a->next;
	}
}