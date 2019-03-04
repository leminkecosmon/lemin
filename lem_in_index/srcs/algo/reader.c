#include "lemin.h"

static void 	verif_start(t_lemin *e, enum pos *d)
{
	char *line;

	if (e->start != NULL || e->end != NULL)
		exit(-1);
	while (get_next_line(0, &line) > 0) 
	{
		if (line[0] != '#')
			break;
		ft_strdel(&line);
	}
	if (line[0] == 'L'|| line[0] == '#')
		exit (-1);
	e->st = 1;
	parsing_rooms(line, e, d);
	ft_strdel(&line);
}

static void		verif_end(t_lemin *e, enum pos *d)
{
	char *line;

	if (e->start == NULL ||  e->end != NULL)
		exit(-1);
	while (get_next_line(0, &line) > 0) 
	{
		if (line[0] != '#')
			break;
		ft_strdel(&line);
	}
	if (line[0] == 'L'|| line[0] == '#')
		exit(-1);
	e->nd = 1;
	parsing_rooms(line, e, d);
	ft_strdel(&line);
}

void	parsing_glob(t_lemin *e, char *line, enum pos *d, int n)
{
	if (line[0] == '#' && line[1] != '#')
		n = 1;
	else if (!ft_strcmp(line, "##start"))
		verif_start(e, d);
	else if (!ft_strcmp(line, "##end"))
 		verif_end(e, d);
	else if (*d == ANTS && n != 1)
	{
		parsing_ants(e, line);
		*d = ROOMS;
	}
	else if (*d == ROOMS && n != 1)
		parsing_rooms(line, e, d);
	else if (*d == LINKS)
		parsing_links(line, e);
}

t_rooms	 **table_rooms(t_lemin *e)
{
	t_rooms **r;
	int i;

	i = 0;
	if (!(r = (t_rooms **)malloc(sizeof(t_rooms) * e->nb_rooms)))
		exit(-1);
	while (i < e->nb_rooms)
	{
		r[i] = e->r;
		e->r = e->r->next;
		i++;
	}
	return (r);
}

int					reader(t_lemin *e)
{
	char 	*line;
	enum 	pos d;
	t_info 	*info;

	d = ANTS;
	e->end = NULL;
	e->start = NULL;
	while (get_next_line(0, &line) > 0)
	{
		add_info(e, &info, line);
		parsing_glob(e, line, &d, 0);
		ft_strdel(&line);
	}
	if (e->nb_ants <= 0 || !e->end || !e->start || !e->l)
		exit(-1);
	parsing_duplicate_rooms(e->r, e->r);
	parsing_links_unknow(e->l, e->r);
	e->table_r = table_rooms(e);
	ft_printf("{RED}%d{EOC}", e->end->nb_rooms);
	ft_printf("%s",e->table_r[9]->name);
	e->nb_start = e->start->nb_rooms;
	e->nb_end = e->end->nb_rooms; 
	return (0);
}
