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

int			deal_key(int key, t_mlx *e)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	mlx_clear_window(e->mlx_ptr, e->win_ptr);
	design_windows(e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->image->img,
	0, 0);
	info(e);
	return (0);
}
