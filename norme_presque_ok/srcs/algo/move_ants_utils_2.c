/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agesp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 11:34:17 by agesp             #+#    #+#             */
/*   Updated: 2019/04/05 11:36:39 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			map_v_realloc_2(t_lemin *e, int i, char *tmp)
{
	char *tmp2;

	if (e->map_v[i])
	{
		if (!(tmp2 = ft_strjoin(e->map_v[i], " ")))
		{
			ft_strdel(&tmp);
			lem_in_error(e, 1);
		}
		ft_strdel(&(e->map_v[i]));
		if (!(e->map_v[i] = ft_strjoin(tmp2, tmp)))
		{
			ft_strdel(&tmp2);
			ft_strdel(&tmp);
			lem_in_error(e, 1);
		}
		ft_strdel(&tmp2);
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
