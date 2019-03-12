/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:35:51 by kecosmon          #+#    #+#             */
/*   Updated: 2019/02/22 15:35:52 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		function_color(t_design *d, t_mlx *v)
{
	int tmp;

	tmp = d->x;
	while (d->y < d->fy)
	{
		d->x = tmp;
		while (d->x < d->fx)
		{
			img_pixel_put(v, d->x, d->y);
			d->x++;
		}
		d->y++;
	}
}

void		write_name_rooms(t_mlx *v)
{
	t_rooms *r;

	r = v->e->r;
	while (r)
	{
		mlx_string_put(v->mlx_ptr, v->win_ptr\
		, r->x,  r->y, 0x00FFFFFF, r->name);
		r = r->next;
	}
}

void		info(t_mlx *v)
{
	mlx_string_put(v->mlx_ptr, v->win_ptr\
		, (WIDTH / 2) - 30 ,  30, 0xC7DBFF, "Lem-in");
	mlx_string_put(v->mlx_ptr, v->win_ptr\
		, 55, HEIGHT - 100, 0x00FFFFFF, "< = arriere");
	mlx_string_put(v->mlx_ptr, v->win_ptr\
		, 300, HEIGHT - 100, 0x00FFFFFF, "> = avant");
	mlx_string_put(v->mlx_ptr, v->win_ptr\
		, 300, HEIGHT - 60, 0x00FFFFFF, "1 = start");
	mlx_string_put(v->mlx_ptr, v->win_ptr\
		, 55, HEIGHT - 70, 0x00FFFFFF, "2 = pause");
	mlx_string_put(v->mlx_ptr, v->win_ptr\
		, 600, HEIGHT - 50, 0x00FFFFFF, "3 = affiche name_rooms");
	mlx_string_put(v->mlx_ptr, v->win_ptr\
		, 55, HEIGHT - 50, 0x00FFFFFF, "nombre fourmis = ");
	mlx_string_put(v->mlx_ptr, v->win_ptr\
		, 230, HEIGHT - 50, 0x00FFFFFF, ft_itoa(v->e->nb_ants));
	if (v->affiche == 1)
		write_name_rooms(v);
}

t_design	init_design(int x, int y, int fy, int fx)
{
	return ((t_design) {fx, fy, x, y});
}

void		design_windows(t_mlx *v)
{
	int y;
	int x;

	y = 0;
	x = 0;
	v->color = 0x4A0404;
	*(v->d) = init_design(0, 0, 100, WIDTH);
	function_color(v->d, v);
	v->color = 0x3B3B3B;
	*(v->d) = init_design(0, 100, 103, WIDTH);
	function_color(v->d, v);
	*(v->d) = init_design(0, HEIGHT - 103, HEIGHT - 100, WIDTH);
	function_color(v->d, v);
	v->color = 0x4A0404;
	*(v->d) = init_design(0, HEIGHT - 100, HEIGHT, WIDTH);
	function_color(v->d, v);
	v->color = 0x2f3640;
}