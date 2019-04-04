/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:37:44 by kecosmon          #+#    #+#             */
/*   Updated: 2019/02/22 15:37:45 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		draw_breseham(int y, int x, int yf, int xf, t_mlx *v)
{
	int dx,dy,i,xinc,yinc,cumul;

	dx = xf - x ;
	dy = yf - y ;
	xinc = ( dx > 0 ) ? 1 : -1 ;
	yinc = ( dy > 0 ) ? 1 : -1 ;
	dx = ft_abs(dx) ;
	dy = ft_abs(dy) ;
	img_pixel_put(v, x,y);
	i = -1;
	if ( dx > dy ) 
	{
		cumul = dx / 2 ;
		while (++i < dx) 
		{
			x += xinc ;
			cumul += dy ;
			if ( cumul >= dx ) 
			{
				cumul -= dx ;
				y += yinc ; 
			}
			img_pixel_put(v, x, y) ; 
		} 
	}
	else 
	{
		i = -1;
		cumul = dy / 2 ;
		while (++i < dy) 
		{
			y += yinc ;
			cumul += dx ;
			if ( cumul >= dy ) 
			{
				cumul -= dy ;
				x += xinc ; 
			}
			img_pixel_put(v, x, y) ; 
		} 
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

void 		view_coor(t_rooms *r, t_mlx *v)
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

int 		max(t_lemin *e)
{
	t_path *p;
	int i;

	i = 0;
	p = e->p;
	while (p)
	{
		i = p->size_path;
		p = p->next;
	}
	return (i);
}

void 		move_ants(t_mlx *v, t_lemin *e)
{
	size_t i;
	int key;
	char *str;
	int len;
	int nb;

	i = 0;
	while (i < ft_strlen(e->map_v[e->n]))
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
		v->d = init_design(e->h[key]->r->x + 10, e->h[key]->r->y + 10,\
		e->h[key]->r->y + 20, e->h[key]->r->x + 20);
		function_color(v->d, v);
		i++;
	}
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
void 			viewer(t_mlx *v)
{
	t_path	*p;
	t_rooms	*r;
	int		i;
	int 	spacew;

	r = v->e->r;
	i = 1;
	p = v->e->p;
	spacew = 0;
	spacew = init_start(v, spacew);
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
	move_ants(v, v->e);
	mlx_clear_window(v->mlx_ptr, v->win_ptr);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->image->img,
	0, 0);
	design_windows(v);
	info(v);
}
