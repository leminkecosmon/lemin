#include "lemin.h"

void	connexion_map(t_lemin *e, char *s1, char *s2, int **map)
{
	int key1;
	int key2;

	key2 = generate_hash(s2, e->nb_rooms);
	key1 = generate_hash(s1, e->nb_rooms);
	map[e->h[key1]->r->nb_rooms][e->h[key2]->r->nb_rooms] = 1;	
	map[e->h[key2]->r->nb_rooms][e->h[key1]->r->nb_rooms] = 1;
}

void	created_liasion_map(int **map, t_lemin *e)
{
	int y;
	
	y = 0;
	while (y < e->nb_rooms)
	{
		map[y][y] = 2;
		y++;
	}
}

int		**created_map(t_lemin *e)
{
	int 	**map;
	t_rooms *r;
	t_links *l;
	int 	i;

	i = 0;
	r = e->r;
	l = e->l;
	if (!(map = malloc(sizeof(int *) * e->nb_rooms)))
		exit (-1);
	while (i < e->nb_rooms)
	{
		if (!(map[i] = malloc(sizeof(int) * e->nb_rooms)))
			exit (-1); 
		i++;
	}
				int key1;
	int key2;
	// ft_putnbr(map[1][1]);
	map[e->nb_rooms] = NULL;
	i = 0;
	int x = 0;
	while (i < e->nb_rooms)
	{
		x = 0;
		while (x < e->nb_rooms)
			map[i][x++] = 0;
		i++;
	}
	while (l)
	{
		key2 = generate_hash(l->s2, e->nb_rooms);
		key1 = generate_hash(l->s1, e->nb_rooms);
		map[e->h[key1]->r->nb_rooms][e->h[key2]->r->nb_rooms] = 1;	
		map[e->h[key2]->r->nb_rooms][e->h[key1]->r->nb_rooms] = 1;
		l = l->next;
	}
	return (map);
}
