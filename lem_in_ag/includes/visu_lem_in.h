/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_lem_in.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agesp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:25:50 by agesp             #+#    #+#             */
/*   Updated: 2019/03/05 12:43:12 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_LEM_IN_H
# define VISU_LEM_IN_H

# include "lemin.h"
# include "mlx.h"

typedef struct	s_graph
{
	void	*init;
	void	*win;
	int		bpp;
	int		*graph;
	int		s_l;
	int		endian;
}				t_graph;

typedef struct	s_pr_ant
{
	void	*init;
	void	*win;
	int		bpp;
	int		*ant;
	int		s_l;
	int		endian;
}				t_pr_ant;

#endif
