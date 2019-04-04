/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 15:31:29 by kecosmon          #+#    #+#             */
/*   Updated: 2019/04/04 14:32:49 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			zero_vistid(t_lemin *e)
{
	t_path	*p;
	int		i;

	p = e->p;
	while (p)
	{
		i = -1;
		while (++i < p->size_path)
			e->table_r[p->path[i]]->occuped = 0;
		p = p->next;
	}
}

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

void			malloc_move(t_lemin *e, t_path *p)
{
	t_ants *a;
	t_path *save;

	a = e->a;
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

int				not_all_printed(t_ants *a)
{
	while (a)
	{
		if (a->p->i != a->p->size_path)
			return (1);
		a = a->next;
	}
	return (0);
}

void			map_v_realloc_2(t_lemin *e, int i, char *tmp)
{
	char *tmp2;

	if (e->map_v[i])
	{
		if (!(tmp2 = ft_strjoin(e->map_v[i], " ")))
		{
			free(tmp);
			lem_in_error(e, 1);
		}
		free(e->map_v[i]);
		if (!(e->map_v[i] = ft_strjoin(tmp2, tmp)))
		{
			free(tmp2);
			free(tmp);
			lem_in_error(e, 1);
		}
		free(tmp2);
	}
	else
	{
		e->map_v[i] = ft_strjoin("", tmp);
		!e->map_v[i] ? free(tmp) : 0;
		!e->map_v[i] ? lem_in_error(e, 1) : 0;
	}
}

void			map_v_realloc(t_lemin *e, t_ants *a, int i)
{
	char	*tmp;
	char	*tmp2;

	if (!(tmp2 = ft_itoa(a->nb_ants)))
		lem_in_error(e, 1);
	if (!(tmp = ft_strjoin("L", tmp2)))
	{
		free(tmp2);
		lem_in_error(e, 1);
	}
	free(tmp2);
	if (!(tmp2 = ft_strjoin(tmp, "-")))
	{
		free(tmp);
		lem_in_error(e, 1);
	}
	free(tmp);
	if (!(tmp = ft_strjoin(tmp2, e->table_r[a->p->path[a->p->i]]->name)))
	{
		free(tmp2);
		lem_in_error(e, 1);
	}
	free(tmp2);
	map_v_realloc_2(e, i, tmp);
	free(tmp);
}

void			do_print(t_lemin *e, t_ants *a, int i)
{
	if (a->p->i < a->p->size_path
			&& e->table_r[a->p->path[a->p->i]]->occuped != 2)
	{
		if (a->p->i + 1 == a->p->size_path)
			e->table_r[a->p->path[a->p->i]]->occuped = 0;
		else
			e->table_r[a->p->path[a->p->i]]->occuped = 2;
		map_v_realloc(e, a, i);
		ft_printf("L%d-%s ", a->nb_ants, e->table_r[a->p->path[a->p->i]]->name);
		a->p->i++;
	}
}

void			move_ants_forward(t_lemin *e, t_path *p, t_ants *a)
{
	int i;

	i = 0;
	set_path_capacity(e);
	malloc_move(e, p);
	e->map_v = ft_memalloc(sizeof(char *) * e->nb_ants * e->nb_rooms);
	while (a)
	{
		do_print(e, a, i);
		if (a->next == NULL && not_all_printed(e->a))
		{
			if (a->nb_ants == 4)
				e->table_r[a->p->path[a->p->i]]->occuped = 0;
			ft_putchar('\n');
			i++;
			zero_vistid(e);
			a = e->a;
		}
		else
			a = a->next;
	}
	e->map_v[i] = 0;
	i = 0;
}
