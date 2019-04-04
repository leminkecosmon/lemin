/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:37:44 by kecosmon          #+#    #+#             */
/*   Updated: 2019/02/22 15:37:45 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void 		view_coor(t_rooms *r, t_mlx *v)
{
	int i;

	i = -1;
	v->color = 0xfbc531;
	v->d = init_design(r->x, r->y, r->y + 30, r->x + 30);
	function_color(v->d, v);
	v->color = 0x000000;
	v->d = init_design(r->x + 2, r->y + 2, r->y + 28, r->x + 28);
	function_color(v->d, v);
	while (++i < r->nb_links)
	{
		if (r->links[i])
			view_link(r, r->links[i], v);
		else 
			break;
	}
}

void 		view_link(t_rooms *r, t_rooms *r2, t_mlx *v)
{
	int y;
	int x;
	int fy;
	int fx;

	x = r->x;
	y = r->y;
	fx = r2->x;
	fy = r2->y;
	v->color = 0xe1b12c;
	draw_breseham(y, x, fy, fx, v);
}

void 			init_r(t_mlx *v, int size_path, int *path, int spacey)
{
	int i;
	int spacew;

	spacew = WIDTH / size_path;
	i = 1;
	ft_abs(spacew);
	while (i < size_path - 1)
	{
		v->e->table_r[path[i]]->x = spacew * i;
		v->e->table_r[path[i]]->y = spacey;
		i++;
	}
}

int 			init_start(t_mlx *v, int spacew)
{
	v->e->start->y = HEIGHT / 2 + 10;
	v->e->start->x = 50;
	v->e->end->y = HEIGHT / 2;
	v->e->end->x = WIDTH - 100;
	v->tmpspace = HEIGHT / v->e->nb_paths;
	if (v->tmpspace == HEIGHT)
		v->tmpspace = HEIGHT / 2;
	v->hspace = v->tmpspace +  50;
	if (v->e->nb_rooms > 100)
		spacew = WIDTH / 100;
	else
		spacew = WIDTH / 20;
	return (spacew);
}

void 			rooms_links(t_mlx *v, t_rooms *r, int i, int spacew)
{
	while (r)
	{
		if (r->x == 0 && r->y == 0)
		{
			v->e->table_r[r->id_r]->y = 150;
			v->e->table_r[r->id_r]->x = spacew * i; 
		}
		i++;
		r = r->next;
	}
	r = v->e->r;
	while (r)
	{
		view_coor(r, v);
		r = r->next;
	}
}
