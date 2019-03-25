/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 15:31:29 by kecosmon          #+#    #+#             */
/*   Updated: 2019/03/21 13:59:15 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void 	add_ants_path(t_lemin *e)
{
	t_path 	*p;
	t_ants 	*a;
	int  	i;

	a = e->a;
	i = 0;
	p = e->p;
	while (i < e->nb_paths)
	{
		a->p = &p[i];
		a = a->next;
		i++;
		if (i == e->nb_paths && a)
			i = 0;
	}
}

void	move_ants_forward(t_lemin *e)
{
	t_ants *a;
	int i;

	i = 1;
	a = e->a;
	add_ants_path(e);
	while (a)
	{
		i = 0;
		while (++i < e->nb_paths + 1)
			ft_printf("L%d-%s ", a->nb_ants, e->table_r[e->p[0].chemin[i]]->name);
		a = a->next;
	}
	// while (b)
	// {
	// 	cur = init_best(cur, e);
	// 	p = b;
	// 	b = b->next;
	// }
	// p = e->p;

	// i = -1;


	// p = e->p;
	// malloc_move(e, p);
	// a = e->a;
	// while (a)
	// {
	// 	if (a->p->i < a->p->size_path && e->table_r[a->p->path[a->p->i]]->occuped != 2)
	// 	{
	// 		if (a->p->i + 1 == a->p->size_path)
	// 			e->table_r[a->p->path[a->p->i]]->occuped = 0;
	// 		else
	// 			e->table_r[a->p->path[a->p->i]]->occuped = 2;
	// 		tmp = ft_strjoin("L", ft_itoa(a->nb_ants));
	// 		tmp = ft_strjoin(tmp, "-");
	// 		tmp = ft_strjoin(tmp, e->table_r[a->p->path[a->p->i]]->name);
	// 		if (e->map_v[i])
	// 		{
	// 			e->map_v[i] = ft_strjoin(e->map_v[i], " ");
	// 			e->map_v[i] = ft_strjoin(e->map_v[i], tmp);
	// 		}
	// 		else
	// 			e->map_v[i] = ft_strjoin("", tmp);
	// 		ft_strdel(&tmp);
	// 		ft_printf("L%d-%s ", a->nb_ants, e->table_r[a->p->path[a->p->i]]->name);
	// 		a->p->i++;
	// 	}
	// 	if (a->next == NULL && not_all_printed(e->a))
	// 	{
	// 		i++;
	// 		if (a->nb_ants == 4)
	// 			e->table_r[a->p->path[a->p->i]]->occuped = 0;
	// 		ft_putchar('\n');
	// 		zero_vistid(e);
	// 		a = e->a;
	// 	}
	// 	else
	// 		a = a->next;
	// }
	// e->map_v[i] = NULL;
	// i = 0;
	// while (e->map_v[i])
	// {
	// 	ft_putendl(e->map_v[i]);
	// 	i++;
	// }
}
