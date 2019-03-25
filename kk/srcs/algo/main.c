/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:37:44 by kecosmon          #+#    #+#             */
/*   Updated: 2019/02/22 15:37:45 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		error_messages(int error)
{
	error == 1 ? write(1, "Error: malloc failure\n", 22) : 0;
	error == 2 ? write(1, "Error: ' ' or '-' before or after ants\n", 39) : 0;
	error == 3 ? write(1, "Error: negative, too many, or no ants\n", 38) : 0;
	error == 4 ? write(1, "Error: comment after ##start or ##end\n", 38) : 0;
	error == 5 ? write(1, "Error: ants badly formatted\n", 28) : 0;
	error == 6 ? write(1, "Error: room starts with 'L' or '#'\n", 35) : 0;
	error == 7 ? write(1, "Error: more than 1 start or end room\n", 37) : 0;
	error == 8 ? write(1, "Error: start or end\n", 23) : 0;
	error == 10 ? write(1, "Error: room links to self\n", 27) : 0;
	error == 11 ? write(1, "Error: no rooms\n", 17) : 0;
	error == 12 ? write(1, "Error: no links or empty map\n", 29) : 0;
	error == 13 ? write(1, "Error: no path\n", 15) : 0;
	error == 14 ? write(1, "Error: link to unknown room\n", 28) : 0;
	error == 15 ? write(1, "Error: coordinates\n", 31) : 0;
	error == 16 ? write(1, "Error: duplicate rooms\n", 23) : 0;
	error == 18 ? write(1, "Error: too many arguments\n", 26) : 0;
}

void			lem_in_error(t_lemin *e, int error)
{
	int i;

	i = -1;
	if (error > 0)
		error_messages(error);
	else
		write(1, "Error\n", 6);
	if (e->i)
		free(e->i);	
	if (e->mat)
	{
		while (++i < e->nb_rooms)
			free(e->mat[i]);
		free(e->mat);
	}
	if (e->r)
		while (e->r && (e->r = e->r->next))
		{
			ft_strdel(&(e->r->name));
			free(e->r->links);
		}
	if (e->p)
		free(e->p);
	if (e->a)
		free(e->a);
	exit(-1);
}

void 		affiche_map(t_lemin *e, int **map)
{
	int i;
	int x;

	x = 0;
	i = 0;
	ft_putstr("    ");
	while (i <= 11)
	{
		ft_putnbr(i);
		ft_putchar(' ');
		i++;
	}
	i = 0;
	ft_putchar('\n');
	while (i < e->nb_rooms)
	{
		ft_putnbr(i);
		if (i < 10)
		ft_putstr("   ");
		else
			ft_putstr("  ");
		x = 0;
		while (x < e->nb_rooms)
		{
			map[x][x] = 0;
			ft_putnbr(map[i][x++]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
		i++;
	}
}

int			main(int ac, char const *av[])
{
	t_lemin *e;

	if ((!(e = ft_memalloc(sizeof(t_lemin)))))
		lem_in_error(e, 1);
	if (ac < 1 && av)
	{
		ft_putstr("usage: lem-in ,[maps...]");
		return (0);
	}
	reader(e);
	if (!(e->nb_paths = bfs_edmonds_karps(e)))
		lem_in_error(e, 13);
	move_ants_forward(e);
	ft_putchar('\n');
	return (0);
}
