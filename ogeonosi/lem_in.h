#ifndef LEM_IN_H
# define LEM_IN_H
# include "my_libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <errno.h>

# define TRUE	1
# define FALSE	0

typedef struct	s_stack
{
	int			*arr;
	int			ptr;
	int			len;
}				t_stack;

typedef		enum
{
			false,
			true
}			t_bool;

typedef struct		s_linked
{
	int				data;
	struct s_linked	*next;
}					t_linked;

typedef enum
{
	begin,
	middle,
	end
}	t_status;

typedef struct	s_vertex
{
	char		*name;
	int			len;
	int			bfs_order;
	t_linked	*neighbour;
	t_status	status;
	int			in;
	int			out;
	int			order;
	int			x;
	int			y;
}				t_vertex;

typedef struct		s_hash
{
	t_vertex		*v;
	struct s_hash	*next;
}					t_hash;

typedef struct      s_map
{
	int				ants;
	t_bool			flag_ants;
	t_bool			flag_start;
	t_bool			flag_end;
	t_bool			flag_rooms;
	t_bool			flag_links;
	int				max_order;
	int				hash_size;
	int				fd;
	int				start_vertex;
	int				end_vertex;
	t_hash			**first_raw;
	t_linked		**g;
}					t_map;

t_vertex *vertex_init(char *name, int len, t_status st, int order);
void	farm_init(t_map *f);
t_hash	**hashmap_init(t_hash **h, int hash_size);
t_bool	assign_line_to_hashmap(t_map *f, t_status st, char *line, int order);
char	*assign_start_end_to_hashmap(t_map *f, char *line, t_status st);
t_bool	read_map(t_map *f);
void	print_graph(t_linked **g, int n);
t_bool	graph_fill_in(t_map *f);
t_stack	*initiate_stack(int n);
void	delete_stack(t_stack *stack);
t_bool	is_empty_stack(t_stack *stack);
t_bool	is_full_stack(t_stack *stack);
t_bool	append_to_stack(t_stack *stack, int value);
int		pop_from_stack(t_stack *stack);
int	top_in_stack(t_stack *stack);
void	print_stack(t_stack *stack);
void	dfs(t_map *f);
void	dfs1(t_map *f);
int		hash_calculate(char *str, int len, int hash_size);
void	print_hash(t_hash **h, int hash_size);
t_bool	parse_links(t_map *f, char *line, char *dash);
t_bool link_neighbour(t_vertex *dest, t_vertex *src);
t_vertex	*find_vertex(t_map *f, char *start_search, int n);

#endif