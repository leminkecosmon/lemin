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

int 	set(t_path *p, int **map, int c)
{
	int i;

	i = -1;
	while (++i + 1 < p->size_path)
		map[p->path[i]][p->path[i]] = c;
	return (i + 1);
}

int 	take_better_path(t_path *p, t_lemin *e, int **map)
{
	t_path 	*tmpp;
	int 	i;
	t_path 	*ok;
	int 	count;
	
	tmpp = e->p;
	while (tmpp)
	{
		i = 0;
		while (++i + 1 < tmpp->size_path)
			if (tmpp->path[i] == p->path[i] && tmpp->conti == 1)
			{
				ok = tmpp;
				count = set(tmpp, map, 0);
				set(p, map, 4);
			}
			else if (tmpp->path[i] == p->path[i] && tmpp->conti == 0 && i + 1  < p->size_path)
			{
				p->stop = 2;
			}
		tmpp = tmpp->next;
	}
	if (p->stop == 2)
	{
		set(ok, map, 4);
		set(p, map, 0);
		p->stop = 4;
		p->conti = 0;
		return (0);
	}
	else 
	{
		ok->conti = 0;
		ok->stop = 4;
		p->stop = 0;
		p->conti = 1;
		return (count);
	}
}

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
	int count;

	count = 0;
	count_ants = 1;
	i = 1;
	while (i + 1 < p->size_path && (*a)->nb_ants)
	{
		if (e->map[p->path[i]][p->path[i]] == 4 && p->conti == 0)
		{
			if (p->stop == 4)
				break ;
			p->conti = 2;
			// recuperer les vrai chemin si il y a 
			if (!(count = take_better_path(p, e, e->map)))
				break ;
		}
		else
			e->map[p->path[i]][p->path[i]] = 4;
		count_ants++;
		i++;
	}
	count_ants -= count;
	if (i + 1 == p->size_path)
		p->conti = 1;
	if (count_ants > 0)
	while (count_ants)
	{
		if (*a)
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

	tmp = p->next;
	a = e->a;
	while (p)
	{
		if ((a && p->conti == 1))
		{
			ft_alloc(e, p);
			a = a->next;
		}
		// }
		// if (tmp && tmp->size_path > e->nb_ants - a->nb_ants && tmp->conti == 1)
		// 	if (p->size_path * 2 > e->nb_ants - a->nb_ants)
		// 	{
		// 		tmp->conti = 0;
		// 		tmp = e->p;
		// 		p = e->p;
		// 	}
		if (p->next == NULL && a)
			p = e->p;
		else 
			p = p->next;
	}
}

void 	free_path(t_path **p)
{
	t_path *to_free;

	if (*p)
	{	
		if ((*p)->conti == 0)
		{
			to_free = *p;
			*p = (*p)->next;
			free(to_free);
			free_path(p);
		}
		else
			free_path(&(*p)->next);
	}
}

void	move_ants_forward(t_lemin *e)
{
	t_path *p;
	t_ants *a;
	int i;

	i = 0;
	a = e->a;
	p = e->p;
	while (p)
	{
		// recherche de path
		call_paht(e, &a, p);
		if (!a)
			break ;
		if (p->next == NULL && a->next != NULL)
			p = e->p;
		else
			p = p->next;
	}
	p = e->p;
	// free tous les path non valide
	free_path(&p);
	p = e->p;
	// l'endroit ou il faut travaillez pour la repartition des des fourmis
	malloc_move(e, p);
	a = e->a;
	a->p->i = 1;
	while (a)
	{
		if (e->table_r[a->p->path[a->p->i]]->occuped != 2 && a->p->i < a->p->size_path)
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
		if (a->next == NULL && a->p->i < a->p->size_path)
		{
			i++;
			ft_putchar('\n');
			zero_vistid(e);
			a = e->a;
		}
		else
			a = a->next;
	}
	// e->map_v[i] = NULL;
	// i = 0;
	// ft_putchar('\n');
	// while (e->map_v[i])
	// {
	// 	ft_putendl(e->map_v[i]);
	// 	i++;
	// 	i++;
	// }
}