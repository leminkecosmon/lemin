/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:38:01 by kecosmon          #+#    #+#             */
/*   Updated: 2019/02/22 15:38:02 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/visual.h"
#include "includes/visual.h"

int		deal_hook(void *param)
{
	t_mlx *e;

	e = (t_mlx *)param;
	mlx_clear_window(e->mlx_ptr, e->win_ptr);
	design_windows(e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->image->img,
	0, 0);
	info(e);
	return (1);
}

void	malloc_struc(t_mlx *e)
{
	if (!(e.image = malloc(sizeof(t_image))) ||\
		!(e.d = malloc(sizeof(t_design))) ||\
		!(e.even = malloc(sizeof(t_event))))
		exit(-1);
}
int		main(void)
{
	t_mlx	e;

	malloc_struc(&e);
	e.mlx_ptr = mlx_init();
	e.win_ptr = mlx_new_window(e.mlx_ptr, WIDTH, HEIGHT, "lem_in");
	e.image->img = mlx_new_image(e.mlx_ptr, WIDTH, HEIGHT);
	e.image->img_data = mlx_get_data_addr(e.image->img, &(e.image->img_bpp),\
	&(e.image->img_size_line), &(e.image->img_endian));
	mlx_key_hook(e.win_ptr, deal_key, &e);
	mlx_expose_hook(e.win_ptr, deal_hook, &e);
	mlx_loop(e.mlx_ptr);
	return (0);
}
