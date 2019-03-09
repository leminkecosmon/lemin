/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:37:30 by kecosmon          #+#    #+#             */
/*   Updated: 2019/02/22 15:37:31 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int			deal_key(int key, t_mlx *v)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 20)
		v->affiche = 1;
	if (key == 21)
		v->affiche = 0;
	viewer(v);
	mlx_clear_window(v->mlx_ptr, v->win_ptr);
	design_windows(v);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->image->img,
	0, 0);
	info(v);
	return (0);
}