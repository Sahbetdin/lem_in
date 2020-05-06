#include "../lem_in.h"


//initialize farm variables 
void	farm_init(t_map *f)
{
	f->hash_size = 100;
	f->ants = 0;
	f->flag_ants = false;
	f->flag_start = false;
	f->flag_end = false;
	f->flag_rooms = false;
	f->flag_links = false;
	f->max_order = 0;
	f->fd = 0;
	f->first_raw = hashmap_init(f->first_raw, f->hash_size);
	f->bfs_order = NULL;
}


void	farm_delete(t_map *f)
{
	//очистить весь farm, который содержит hash, который
	//содержит vertex
}

/*
** allocate memory for hash table and initialize it with NULLs
*/
t_hash	**hashmap_init(t_hash **h, int hash_size)
{
	int i;

	h = (t_hash **)malloc(sizeof(t_hash *) * hash_size);
	i = -1;
	while (++i < hash_size)
		h[i] = NULL;
	return (h);
}

/*
alloccate memory for visited order for bfs
and initialize it with -1
*/

int		*visited_init(int *vis, int n)
{
	int i;

	vis = (int *)malloc(sizeof(int) * n);
	i = -1;
	while (++i < n)
		vis[i] = -1;
	return (vis);
}
