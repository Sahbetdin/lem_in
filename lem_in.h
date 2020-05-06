/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 21:35:37 by btrifle           #+#    #+#             */
/*   Updated: 2020/04/14 18:14:01 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "my_libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <errno.h>

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

typedef struct		s_linked
{
	int				data;
	int				in; //after bfs we have in and out links (arcs)
	int				out;
	int				neutral;
	t_status		status; // if start then 0, meduim 1, end 2 // добавил сюда. ниже нажо будет удалить
	struct s_linked	*next;
}					t_linked;

//this stack structure uses array
//and pointer to current element;
//len is the length
//when initialized, ptr = len which means that stack is empty
//if ptr == 0, the stack is full

typedef struct		s_stack
{
	int				*arr;
	int				ptr;
	int				len;
}					t_stack;


typedef struct		s_vertex
{
	char			*name; //name which we read from file
	int				len;
	t_linked		*neighbour; //the adjacent list
	t_status		status; // if start then 0, meduim 1, end 2
	int				order; //info about place in graph
	int				x; //template for filling in the coordinates
	int				y; // ----//----
}					t_vertex;

//v is vertex structure exempliar
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
** max_order is max number of rooms.
** hash_size is hash table size
** fd is file descriptir which is 1
** start_vertex is the vertex order where start room is located;
** end_vertex is the same
** first_raw is the g[0], thus the very first adj list of graph
** g is graph itsels (which is no more than the t_linked** )
** bfs_order - each node has its own BFS order
** 
** 
*/

typedef struct      s_map
{
	int				ants;
	t_bool			flag_ants;
	t_bool			flag_start;
	t_bool			flag_end;
	t_bool			flag_rooms;
	t_bool			flag_links;
	int				max_order; //number of vertice
	int				hash_size;
	int				fd;
	int				start_vertex;
	int				end_vertex;
	t_hash			**first_raw;
	t_linked		**g; //graph itself
	int				*bfs_order; //each node has BFS order
}					t_map;

/*
** queue structure and its functions
*/

typedef struct		s_queue
{
	int 			*front;
	int 			*rear;
	int 			n;
}					t_queue;

void				queue_init(t_queue *Q, int size);
int					queue_is_empty(t_queue *Q);
int					queue_insert(t_queue *Q, int x);
int					queue_is_full(t_queue *Q);
void				queue_print(t_queue *Q);
int					queue_out_first(t_queue *Q);
int					queue_shine_first(t_queue *Q);
void				queue_delete(t_queue *Q);
int					queue_pop(t_queue *Q);

t_vertex			*vertex_init(char *name, int len, t_status st, int order);
int					hash_calculate(char *str, int len, int hash_size);
void				print_hash(t_hash **h, int hash_size);
t_hash				**hashmap_init(t_hash **h, int hash_size);
void				farm_init(t_map *f);
t_bool				assign_line_to_hashmap(t_map *f, t_status st, char *line, int order);
char				*assign_start_end_to_hashmap(t_map *f, char *line, t_status st);
t_vertex			*find_vertex(t_map *f, char *start_search, int n);
t_bool 				link_neighbour(t_vertex *dest, t_vertex *src);
t_bool				parse_links(t_map *f, char *line, char *dash);
t_bool				read_map(t_map *f);
t_bool				graph_fill_in(t_map *f);
void				print_graph(t_linked **g, int n);
t_stack				*initiate_stack(int n);
void				delete_stack(t_stack *stack);
t_bool				is_empty_stack(t_stack *stack);
t_bool				is_full_stack(t_stack *stack);
t_bool				append_to_stack(t_stack *stack, int value);
int					pop_from_stack(t_stack *stack);
int					top_in_stack(t_stack *stack);
void				print_stack(t_stack *stack);
void				print_linked_visited(t_linked *lst, t_bool *vis);
void				farm_delete(t_map *f); //еще не написан
int					*visited_init(int *vis, int n);
void				bfs(t_map *f, int start);
void				init_in_out_neutral(t_linked **g, int n);
#endif
