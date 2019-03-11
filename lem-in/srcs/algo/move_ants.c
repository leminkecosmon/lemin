/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agesp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 15:31:29 by agesp             #+#    #+#             */
/*   Updated: 2019/03/11 14:23:00 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		int_chr(int *tab1, int *tab2, int len)
{
	int x;
	int y;

	x = 1;
	while (x < len)
	{
		y = 1;
		while (y < (len - 1))
		{
			if (tab1[x] == tab2[y])
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int		is_ok_path(t_lemin *e, t_path *save, t_path *select)
{
	int x;

	if (e->x == 0)
		return (1);
	x = 0;
	while (x < e->x)
	{
		if (!int_chr(select->path, save->path, e->p->size_path))
			return (0);
		if (!select->next)
			break ;
		select = select->next;
		x++;
	}
	return (1);
}

void	add_npath(t_lemin *e, t_path *select, t_path *save, int *nb_of_sp)
{
	e->y = 0;
	if (is_ok_path(e, save, select))
	{
		if (select->path)
		{
			while (select->next)
				select = select->next;
			if (!(select->next = malloc(sizeof(t_path))))
				exit(-1);
			select = select->next;
		}
		if (!(select->path = malloc(sizeof(int) * e->p->size_path)))
			exit(-1);
		select->next = NULL;
		while (e->y < e->p->size_path)
		{
			select->path[e->y] = save->path[e->y];
			e->y++;
		}
		e->x++;
		select->size_path = e->p->size_path;
		*nb_of_sp += 1;
	}
}

int	select_good_paths(t_lemin *e)
{
	t_path *save;
	int	nb_of_sp;
	int	shortest;
	t_path *select_p;
	
	nb_of_sp = 0;
	save = e->p;
	e->x = 0;
	shortest = e->p->size_path;
	if (!(select_p = malloc(sizeof(t_path))))
		exit(-1);
	select_p->path = NULL;
	select_p->next = NULL;
	while (save && save->size_path == shortest && nb_of_sp < e->nb_ants)
	{
		add_npath(e, select_p, save, &nb_of_sp);
		save = save->next;
	}
	e->x = 0;
	e->select_p = select_p;
	while (e->x < nb_of_sp)
	{
		e->y = 0;
		while (e->y < e->p->size_path)
		{
			ft_printf("%d ", select_p->path[e->y]);
			e->y++;
		}
		ft_printf("\n");
		select_p = select_p->next;
		e->x++;
	}
	return (1);
}

int		nbr_len(int nbr)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*create_mask(t_lemin *e, int pos_ant, t_path *p, char ****saa)
{
	int			i;
	char		*tmp;

	i = 0;
	ft_printf("%d\n", p->path[1]);
	while (i < p->size_path)
	{
		ft_printf("%d\n", p->path[1]);
		if (!(*saa[pos_ant][i] = malloc(sizeof(char) * (2 + nbr_len(12) + nbr_len(pos_ant)))))
			exit(-1);
		ft_printf("%d\n", p->path[1]);
		ft_strcat(*saa[pos_ant][i], "L");
		ft_strcat(*saa[pos_ant][i], tmp = ft_itoa(pos_ant));
	//	free(tmp);
		ft_strcat(*saa[pos_ant][i], "-");
		ft_strcat(*saa[pos_ant][i], tmp = ft_itoa(p->path[i]));
		free(tmp);
		ft_printf("L%d-%d\n", pos_ant, p->path[i]);
		i++;
	}
	return (NULL);
}

void	move_ants_forward(t_lemin *e)
{
	int		short_path;
	int		nb_of_sp;
	int		pos_ant;
	t_path	*save;
	char	***super_array_of_array;

	pos_ant = 1;
	if (!(super_array_of_array = malloc(sizeof(char**) * e->nb_ants)))
		exit(-1);
	e->x = 0;
	while (e->x < e->nb_ants)
	{
		if (!(super_array_of_array[e->x] = malloc(sizeof(char*) * e->p->size_path)))
			exit(-1);
		e->x++;
	}
	short_path = e->p->size_path;
	select_good_paths(e);
	ft_printf("%d\n", e->select_p->path[1]);
	e->x = 0;
	save = e->select_p;
	while (e->x < e->nb_ants)
	{
		create_mask(e, pos_ant, save, &super_array_of_array);
		if (!save->next)
			save = e->select_p;
		else
			save = save->next;
		pos_ant++;
		e->x++;
	}
}
