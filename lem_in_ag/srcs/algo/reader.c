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
	created_hastable(e);
	return (0);
}
