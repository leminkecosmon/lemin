/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agesp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 15:31:29 by agesp             #+#    #+#             */
/*   Updated: 2019/03/08 16:04:14 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	add_good_path(

int		**select_good_paths(t_lemin *e)
{
	t_paths *save;
	int	nb_of_sp;
	int	shortest;
	int get_best_path[e->nb_paths][e->p->size_path];
	
	nb_of_sp = 0;
	save = e->p;
	shortest = e->p->size_path;
	while (save && save->size_path == shortest)
	{
		nb_of_sp++;
		save = save->next;
	}
	




void	move_ants_forvard(t_lemin *e)
{
	int		short_path;
	int		nb_of_sp;
	t_paths	*save;

	short_path = e->p->size_path;
	save = e->p;
	if (nb_ants <= nb_paths)
	{


