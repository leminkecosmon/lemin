/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agesp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:18:51 by agesp             #+#    #+#             */
/*   Updated: 2019/03/05 13:09:00 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_lem_in.h"

int		is_max(int *tab, int len)
{
	int i;
	int max;

	i = 0;
	max = tab[i++];
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

int		main(void)
{
	t_graph *graph;
	t_pr_ant *ants;
	int x[] = {12, 3 , 6, 8};
	int y[] = {2, 1, 4, 9};

	if (!(graph = malloc(sizeof(t_graph))))
		return (NULL);
	if (!(ants = malloc(sizeof(t_pr_ant))))
		return (NULL);
	graph->init = mlx_init();
	ants->init = graph->init;
	ft_printf("%d %d\n", max(x), max(y));
}
