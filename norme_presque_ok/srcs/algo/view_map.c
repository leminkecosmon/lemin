/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:37:44 by kecosmon          #+#    #+#             */
/*   Updated: 2019/04/05 11:49:19 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int			max(t_lemin *e)
{
	t_path	*p;
	int		i;

	i = 0;
	p = e->p;
	while (p)
	{
		i = p->size_path;
		p = p->next;
	}
	return (i);
}

void		move_ants(t_mlx *v, t_lemin *e, size_t i)
{
	int		key;
	char	*str;
	int		len;
	int		nb;

	while (i++ < ft_strlen(e->map_v[e->n]))
	{
		len = 0;
		if (e->map_v[e->n][i] == 'L')
			i++;
		nb = ft_atoi(&e->map_v[e->n][i]);
		while (e->map_v[e->n][i] != '-')
			i++;
		if (e->map_v[e->n][i] == '-')
			i++;
		while (e->map_v[e->n][i + len] != ' ' && e->map_v[e->n][i + len])
			len++;
		str = ft_strsub(e->map_v[e->n], i, len);
		i += len;
		key = generate_hash(str, e->nb_rooms);
		while (0 != ft_strcmp(e->h[key]->r->name, str))
			key++;
		ft_strdel(&str);
		if (nb % 2)
			nb *= 10;
		else
			nb *= 20;
		v->color = (nb * 10) * 1000 * 255;
		v->d = init_design(e->h[key]->r->x + 10, e->h[key]->r->y + 10,
		e->h[key]->r->y + 20, e->h[key]->r->x + 20);
		function_color(v->d, v);
	}
}

void		viewer(t_mlx *v)
{
	t_path	*p;
	t_rooms	*r;
	int		i;
	int		spacew;

	i = 1;
	r = v->e->r;
	p = v->e->p;
	spacew = init_start(v, 0);
	while (p)
	{
		init_r(v, p->size_path, p->path, v->hspace);
		if (i % 2 != 0)
			v->hspace += ((v->tmpspace * i) - 200);
		else
			v->hspace -= ((v->tmpspace * i) + 200);
		p = p->next;
	}
	rooms_links(v, v->e->r, i, spacew);
	move_ants(v, v->e, 0);
	mlx_clear_window(v->mlx_ptr, v->win_ptr);
	design_windows(v);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->image->img, 0, 0);
	info(v);
}
