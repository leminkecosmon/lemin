/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   created_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agesp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 10:08:17 by agesp             #+#    #+#             */
/*   Updated: 2019/03/18 10:09:32 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				generate_hash(char *str, int nb_rooms)
{
	int i;
	int key;

	key = 0;
	i = 0;
	while (str[i])
		key += (key * 22) + str[i++];
	key %= 100 * nb_rooms;
	return (key);
}

static t_hash	*created_lst_hash(t_rooms *r)
{
	t_hash	*new;

	if (!(new = malloc(sizeof(t_hash))))
		exit(-1);
	new->r = r;
	return (new);
}

static void		init_hash(t_lemin *e)
{
	t_rooms		*r;
	int			key;

	key = 0;
	r = e->r;
	while (r)
	{
		key = generate_hash(r->name, e->nb_rooms);
		e->h[key] = created_lst_hash(r);
		r = r->next;
	}
}

void			created_hastable(t_lemin *e)
{
	int i;

	i = 0;
	if (!(e->h = malloc(sizeof(t_hash) * e->nb_rooms * 100)))
		exit(-1);
	while (i < e->nb_rooms * 100)
		e->h[i++] = NULL;
	init_hash(e);
}
