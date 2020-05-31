/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 21:35:37 by btrifle           #+#    #+#             */
/*   Updated: 2020/05/31 13:15:18 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "my_libft/libft.h"
# include <string.h>
# include <errno.h>
# include <stdio.h>

/*
** this structure define placement of an ant in a
** given time. way is the chosen paths, loc is index,
** where we currently are.
*/
typedef struct		s_position
{
	int				way;
	int				loc;
}					t_position;

typedef struct		s_linked
{
	int				data;
	struct s_linked	*next;
}					t_linked;

typedef enum
{
	false,
	true
}	t_bool;

typedef enum
{
	begin,
	middle,
	end
}	t_status;

/*
** 'name' is room which we read from file
** neighbour - the adjacent list of a given node
** status - status of each vertice; if start then 0, meduim 1, end 2
** order; information about place in graph
*/
typedef struct		s_vertex
{
	char			*name;
	int				len;
	t_linked		*neighbour;
	t_status		status;
	int				order;
	int				x;
	int				y;
}					t_vertex;

typedef struct		s_hash
{
	t_vertex		*v;
	struct s_hash	*next;
}					t_hash;

/*
** this is global structure which contains
** ants number,
** flags that are responsible for parsing ants, start and end rooms,
** other rooms, links.
** max_order is max number of rooms which indeed is number of vertice.
** hash_size is hash table size
** fd is file descriptir which is 1 (!). Got rid of that in latter days
** start_vertex is the vertex order where start room is located;
** end_vertex is the same
** first_raw is the g[0], thus the very first adj list of graph
** g is graph itsels (which is no more than the t_linked** )
** bfs_order - each node has its own BFS order
*/
typedef struct		s_map
{
	int				ants;
	t_bool			flag_ants;
	t_bool			flag_start;
	t_bool			flag_end;
	t_bool			flag_rooms;
	t_bool			flag_links;
	t_bool			found_shortest_path;
	int				max_order;
	int				hash_size;
	int				start_vertex;
	int				end_vertex;
	t_hash			**first_raw;
	t_linked		**g;
	char			**rooms_ordered;
	int				*bfs_order;
	int				*shortest_path;
	int				current_path;
	int				max_paths;
	int				**paths;
	t_linked		*arc1;
	t_linked		*arc2;
	t_position		*pos;
	int				*len;
	int				*ants_in_paths;
}					t_map;
/*
** paths1.c
*/
void				assign_one_ant(t_map *f, int *j_addr, int *ants_n);
void				count_ants_in_paths(t_map *f, int *ants_n);
void				set_arr_temporarly(t_map *f, int *arr);
void				set_ants_to_paths_tmp(t_map *f, t_bool flag,
					int *arr, int *ants_n);
t_bool				set_and_move_ants(t_map *f, int *ants_n);

/*
** paths2.c
*/
t_bool				init_paths_individually(t_map *f);
t_bool				init_paths(t_map *f);
t_bool				init_bfs_order_short_path_paths(t_map *f);
void				count_paths_length(t_map *f);
void				set_0_ants_in_paths(t_map *f);
/*
** paths3.c
*/
void				copy_paths(int *dest_path, int *src_path, int n);
void				reverse_array(int *arr, int n);
void				path_assign(t_map *f, int *arr);
void				set_all_ant_initial_location(t_map *f);
t_bool				move_one_step(t_map *f);
/*
** paths4.c
*/
t_bool				init_path_lengths(t_map *f);
void				add_start_end_to_paths(t_map *f);
t_bool				caravane_goes_farward(t_map *f);
/*
** find_other_paths.c
*/
void				count_rooms_in_current_path(t_map *f, int *c_addr,
					int *n_elem_addr);
char				find_shortest_path_vertice_in_current_path(t_map *f);
void				b_2(t_map *f);
void				b_1(t_map *f);
void				b_0(t_map *f);
/*
** paths_print.c
*/
void				print_all_paths(int **arr, int n, int m);
void				print_path(int *arr, int n);
void				print_all_positions(t_map *f);
void				print_positions(t_map *f);
/*
** fun_print1.c
*/
void				print_graph(t_linked **g, int n);
void				print_bfs_order(int *arr, int n);
void				print_linked_visited(t_linked *lst, int *vis);
void				print_visited(int *vis, int n);
/*
** fun_print2.c
*/
void				print_during_hash(t_hash *tmp);
void				print_hash(t_hash **h, int hash_size);
void				print_linked_list(t_linked **head);
/*
** fun_init1.c
*/
void				farm_init(t_map *f);
t_hash				**hashmap_init(t_hash **h, int hash_size);
int					*arr_init(int n, int value);
void				arr_fill_in_with_value(int *arr, int n, int value);
/*
** fun_init2.c
*/
t_vertex			*vertex_init(char *name, int len, t_status st, int order);
t_bool				initiate_all_variables(t_map *f);
/*
** fun_del.c
*/
void				delete_trace(t_map *f, int *arr);
t_linked			*del_list_element(t_linked *lst);
t_linked			*delete_arc(t_map *f, int haystack, int needle);
/*
** fun_vertex.c
*/
t_vertex			*find_vertex(t_map *f, char *start_search, int n);
/*
** fun_hash.c
*/
int					hash_calculate(char *str, int len, int hash_size);
void				assign_start_end_status(t_map *f, t_status st);
t_bool				assign_line_to_hashmap(t_map *f, t_status st, char *line);
char				*assign_start_end_to_hashmap(t_map *f, char *line,
					t_status st);
/*
** read_map1.c
*/
t_bool				check_for_digits_in_line(char *line);
t_bool				check_ant_line(t_map *f, char **line);
t_bool				assign_room(t_map *f, char *line);
t_bool				check_flags_assigned_free_last_line(t_map *f, char *line);
t_bool				read_map(t_map *f, char **line);
/*
** read_map2.c
*/
t_bool				is_command(t_map *f, char **line);
t_bool				is_edge(char *line);
t_bool				is_room(char *str);
/*
** read_map3.c
*/
int					count_neighb(t_linked *lst);
int					min_of_two(int a, int b);
t_bool				graph_fill_in(t_map *f);
/*
** read_map4.c
*/
t_bool				compare_src_dest(char *d_n, char *s_n);
t_bool				search_for_duplicate(t_linked *head, int ord,
					char *s_n, char *d_n);
t_bool				link_neighbour(t_vertex *dest, t_vertex *src);
t_bool				parse_links(t_map *f, char *line, char *dash);
/*
** bfs.c
*/
t_bool				is_graph_connected(t_map *f);
int					top_queue(int *arr, int n);
void				print_queue(int *arr, int n, int *j_addr);
void				bfs_main(t_map *f, int *que, int start);
t_bool				bfs(t_map *f, int start);
/*
** work_with_bfs.c
*/
t_bool				work_with_bfs(t_map *f);
/*
** fun_linked_list.c
*/
void				delete_simple_linked_list(t_linked **head);
void				delete_hash_node(t_hash **head);
void				delete_node(t_map *f, int node);
/*
** delete_farm1.c
*/
void				delete_hash_map_with_neighbours_without_graph(t_map *f);
void				delete_hash_map_without_neighbours_with_others(t_map *f);
void				delete_adj_list(t_hash **h, int hash_size);
/*
** delete_farm2.c
*/
void				del_bfs_order(t_map *f);
void				del_shortest_path(t_map *f);
void				del_graph(t_map *f);
void				del_name(char *str);
void				del_vertice(t_map *f);
/*
** delete_farm3.c
*/
void				del_nodes(t_map *f);
void				del_raws(t_map *f);
void				del_rooms(t_map *f);
void				del_ants_in_paths_len_pos(t_map *f);
void				del_paths(t_map *f);
/*
** fun_edges.c
*/
void				delete_edge_temporaly(t_map *f);
void				put_back_removed_arcs(t_map *f);
/*
** visual.c
*/
void	remove_coma(FILE *file);
void		visual(t_map *f);
void		visual2(t_map *f);
#endif
