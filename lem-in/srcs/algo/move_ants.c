/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 15:31:29 by kecosmon          #+#    #+#             */
/*   Updated: 2019/04/03 12:14:25 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			ft_alloc(t_lemin *e, t_path *p)
{
	t_ants *save;

	save = e->a;
	while (e->a->p)
		e->a = e->a->next;
	if (!(e->a->p = malloc(sizeof(t_path))))
		lem_in_error(e, 1);
	e->a->p->i = 1;
	e->a->p->size_path = p->size_path;
	e->a->p->next = NULL;
	if (!(e->a->p->path = malloc(sizeof(int) * p->size_path)))
		lem_in_error(e, 1);
	ft_intcpy(e->a->p->path, p->path, p->size_path - 1);
	e->a = save;
}

void	malloc_move(t_lemin *e, t_path *p)
{
	t_ants *a;
	t_path *save;

	a = e->a;
	p = e->p;
	while (a)
	{
		if (a && p->capacity)
		{
			ft_alloc(e, p);
			if (!a->next)
				break ;
			a = a->next;
			save = p->next;
		}
		if (p->capacity > 0)
			p->capacity--;
		if (!p->next)
			p = e->p;
		else
			p = p->next;
	}
}

int		not_all_printed(t_ants *a)
{
	while (a)
	{
		if (a->p->i != a->p->size_path)
			return (1);
		a = a->next;
	}
	return (0);
}

void	move_ants_forward(t_lemin *e)
{
	t_path *p;
	t_ants *a;
	int i;
	i = 0;
	a = e->a;
	p = e->p;
	set_path_capacity(e);
	malloc_move(e, p);
	while (a)
	{
		if (a->p->i < a->p->size_path && e->table_r[a->p->path[a->p->i]]->occuped != 2)
		{
			if (a->p->i + 1 == a->p->size_path)
				e->table_r[a->p->path[a->p->i]]->occuped = 0;
			else
				e->table_r[a->p->path[a->p->i]]->occuped = 2;
			// tmp = ft_strjoin(ft_itoa(a->nb_ants), e->table_r[a->p->path[a->p->i]]->name);
			// if (e->map_v[i])
			// {
			// 	e->map_v[i] = ft_strjoin(e->map_v[i], " ");
			// 	e->map_v[i] = ft_strjoin(e->map_v[i], tmp);
			// }
			// else
			// 	e->map_v[i] = ft_strjoin("", tmp);
			// ft_strdel(&tmp);
			ft_printf("L%d-%s ", a->nb_ants, e->table_r[a->p->path[a->p->i]]->name);
			a->p->i++;
		}
		if (a->next == NULL && not_all_printed(e->a))
		{
			if (a->nb_ants == 4)
				e->table_r[a->p->path[a->p->i]]->occuped = 0;
			ft_putchar('\n');
			zero_vistid(e);
			a = e->a;
		}
		else
			a = a->next;
	}
	// e->map_v[i] = NULL;
	// i = 0;
	// while (e->map_v[i])
	// {
	// 	ft_putendl(e->map_v[i]);
	// 	i++;
	// 	i++;
	// }
}
