/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 15:31:29 by kecosmon          #+#    #+#             */
/*   Updated: 2019/03/12 16:56:08 by kecosmon 	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft.h"
# define INT_MAX  2147483647

enum pos
{
	ANTS,
	ROOMS,
	START,
	END,
	LINKS
};

typedef	struct 		s_info
{
	char 			*line;
	struct s_info	*next;
}					t_info;

typedef struct 		s_rooms
{
	char			*name;
	long 			dist;
	int 			status;
	int				id_r;
	int 			nb_links;
	int				x;
	int				y;
	struct s_rooms	**links;
	struct s_rooms 	*r_p;
	struct s_rooms	*next;
}					t_rooms;

typedef struct 		s_hash
{
	int				key;
	struct s_rooms	*r;
}					t_hash;

typedef	struct 		s_ants
{
	int				nb_ants;
	int 			color;
	int 			x;
	int 			y;
	struct s_path	*p;
	struct s_ants	*next;
	struct s_ants 	*prev;
}					t_ants;

typedef struct 		s_path
{
	int 			i;	
	int				size_path;
	int 			nb_ants;
	struct s_rooms 	*r;
}					t_path;

typedef struct 		s_lemin
{
	char			*av;
	int 			nb_ants;
	int 			nb_rooms;
	int				nb_paths;
	int				**mat;
	char 			**map_v;
	struct s_rooms  *r;
	struct s_ants	*a;
	struct s_rooms  **table_r;
	struct s_hash	**h;
	struct s_rooms	*start;
	struct s_rooms	*end;
	struct s_info	*i;
	struct s_path	*p;
}					t_lemin;

void 				links_rooms(t_lemin *e);
void				reader(t_lemin *e);
void				add_info(t_lemin *e, char *line);
char				*name_rooms(t_lemin *e, char *line , char c);
t_rooms				*new_rooms(t_lemin *e);
void				parsing_rooms(t_lemin *e, char *line, int i);
void				rooms(char *line, t_lemin *e, enum pos *d);
void				parsing_links(char *line, t_lemin *e);
t_rooms				**table_rooms(t_lemin *e);
void				created_hastable(t_lemin *e);
void				parsing_ants(t_lemin *e, char *line);
int					generate_hash(char *str, int nb_rooms);
int					bfs_edmonds_karps(t_lemin *e);
void				lem_in_error(t_lemin *e, int error);
void				move_ants_forward(t_lemin *e);

// void			created_map(t_lemin *e);

// void 			affiche_map(t_lemin *e, int **map);

// void			created_map(t_lemin *e);
// int				router_links(t_lemin **e, char *line);
// t_rooms			*created_lst(void);
// int				created_links(t_links **tmp, t_rooms *r, char *line, t_lemin *e);
// t_links			*ft_init_links(void);
// void			add_info(t_lemin *e, char *line);
// void			parsing_ants(t_lemin *e, char *line);
// void			parsing_rooms(char *line, t_lemin *e, enum pos *d);
// void			parsing_links(char *line, t_lemin *e);
// void 			parsing_duplicate_rooms(t_rooms *r, t_rooms *v);
// void			parsing_links_unknow(t_links *l, t_rooms *r);
// void			created_hastable(t_lemin *e);
// int				generate_hash(char *str, int nb_rooms);
// void			bfs(t_lemin *e);
// void			pop_stack(t_lemin *e, int nb_rooms);
// int				add_path(t_lemin *e);
// int				get_nb_links(t_lemin *e, int x);
// void			create_path(t_lemin *e, int *path, int len);
// void			push_stack(t_lemin *e);
// void			visu(t_lemin *l);
// void			move_ants_forward(t_lemin *e);
// void 			add_end_start(t_lemin *e);
// t_rooms			*new_rooms(void);
// void			coor_room(char *line, int i);
// int				paths_remain(t_lemin *e);
// int				is_stack_empty(int *stack, int len);
// void			set_bfs_base_var(t_lemin *e);
// void			print_paths(t_lemin *e, t_path *sa);
// int 			set(t_path *p, int **map, int c);
// int 			condition(t_path *p, t_path *ok, int **map, int count);
// void 			zero_vistid(t_lemin *e);
// t_path 			*free_path(t_path *p);

#endif
