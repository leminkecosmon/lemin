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

#include "includes/visual.h"

void		function_color(t_design *d, t_mlx *e)
{
	int tmp;

	tmp = d->x;
	while (d->y < d->fy)
	{
		d->x = tmp;
		while (d->x < d->fx)
		{
			img_pixel_put(e, d->x, d->y);
			d->x++;
		}
		d->y++;
	}
}

void		info(t_mlx *e)
{
	// mlx_string_put(e->mlx_ptr, e->win_ptr\
	// 	, 5, 500, 0x00a8ff, e->player1);
	mlx_string_put(e->mlx_ptr, e->win_ptr\
		, 500, 30, 0xC7DBFF, "Lem-in");
	// mlx_string_put(e->mlx_ptr, e->win_ptr\
	// 	, 1000, 500, 0xe1b12c, e->player2);
	// mlx_string_put(e->mlx_ptr, e->win_ptr\
	// 	, 55, 910, 0x00FFFFFF, "< = arriere");
	// mlx_string_put(e->mlx_ptr, e->win_ptr\
	// 	, 300, 910, 0x00FFFFFF, "> = avant");
	// mlx_string_put(e->mlx_ptr, e->win_ptr\
	// 	, 300, 930, 0x00FFFFFF, "1 = start");
	// mlx_string_put(e->mlx_ptr, e->win_ptr\
	// 	, 55, 930, 0x00FFFFFF, "2 = end");
}

t_design	init_design(int x, int y, int fy, int fx)
{
	return ((t_design) {fx, fy, x, y});
}

void		design_windows(t_mlx *e)
{
	int y;
	int x;

	y = 0;
	x = 0;
	e->color = 0x4A0404;
	*(e->d) = init_design(0, 0, 100, 1200);
	function_color(e->d, e);
	e->color = 0x3B3B3B;
	*(e->d) = init_design(0, 100, 103, 1200);
	function_color(e->d, e);
	*(e->d) = init_design(0, 897, 900, 1200);
	function_color(e->d, e);
	e->color = 0x4A0404;
	*(e->d) = init_design(0, 900, 1000, 1200);
	function_color(e->d, e);
	e->color = 0x2f3640;
}
