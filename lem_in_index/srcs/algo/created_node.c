#include "lemin.h"


// t_path		**find_start_and_init_p(t_path **p, t_lemin *e)
// {
// 	int y;
// 	int i;
// 	int key;
// 	t_path **tmp;

// 	p = e->p;
// 	tmp = p;
// 	i = 0;
// 	y = 0;
// 	key = generate_hash(e->start->name, e->nb_rooms);
// 	e->nb_start = e->h[key]->r->nb_rooms;
// 	key = generate_hash(e->end->name, e->nb_rooms);
// 	e->nb_end = e->h[key]->r->nb_rooms;
// 	if (!(tmp = (t_path **)malloc(sizeof(t_path) * e->nb_links)))
// 		exit(-1);
// 	while (i < e->nb_links)
// 		(tmp)[i++] = malloc(sizeof(t_path));
// 	return (tmp);
// }

void	created_path(t_lemin *e, int y, int back)
{
	t_path **p;
	int x;
	int i;
	int b;

	b = 0;
	i = 0;
	x = 0;
	p = NULL;
	back = 0;
	if (e)
y = 0;

	// p = find_start_and_init_p(p, e);
	// p[i]->size_path = 2;
	// y = e->nb_start;
	// if (!(p[i]->co = malloc(sizeof(int *) * e->nb_rooms + 1)))
	// 	exit(-1);
	// p[i]->co[e->nb_rooms + 1] = 0;
	// while (y < e->nb_rooms)
	// {
	// 	x = 0;
	// 	while (x < e->nb_rooms)
	// 	{
	// 		ft_putnbr(x);
	// 		if (y == e->nb_end)
	// 		{
	// 			b--;
	// 			x = p[i]->co[b];
	// 			e->map[y][x] = 2;
	// 			i++;
	// 			ft_putchar('b');
	// 			if (!(p[i]->co = malloc(sizeof(int *) * e->nb_rooms + 1)))
	// 				exit(-1);
	// 			ft_putchar('a');
	// 			p[i]->co[e->nb_rooms + 1] = 0;
	// 			y = e->nb_start;
	// 			break ; 
	// 		}
	// 		else if (e->map[y][x] != 2)
	// 		{
	// 			ft_putchar('e');
	// 			p[i]->co[b] = x;
	// 			b++;
	// 			break ;
	// 		}
	// 		else if (e->map[y][x] == 2)
	// 		{
	// 							ft_putchar('d');

	// 			x = -1;
	// 			break ;
	// 		}
	// 		else if (e->map[y][x] == 2)
	// 		{
	// 											ft_putchar('i');

	// 			x++;
	// 		}
	// 	}
	// 	if (x == -1)
	// 		break ;
	// 	y++;
	// }
	// ft_putchar('c');
	// i = 0;
	// while (p[i] != NULL)
	// {
	// 	b = 0;
	// 	while (p[i]->co[b])
	// 	{
	// 		ft_putnbr(p[i]->co[b]);
	// 		ft_putchar('-');
	// 		b++;
	// 	}
	// 	ft_putchar('\n');
	// 	i++;
	// }
}