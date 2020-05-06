#include "../lem_in.h"


int main(int argc, char **argv)
{
	t_map farm;
	int res;
	int order; //counts number of vertice
	int k, j, n;
	char *line;

	if (argc != 1)
		return (0);
	farm_init(&farm);
	farm_delete(&farm);
	if (read_map(&farm) == false)
	{
		ft_printf("ERROR in map");
		exit(0);
	}
	print_hash(farm.first_raw,farm.hash_size);
	// ft_printf("max_order = %d\n", farm.max_order);
	graph_fill_in(&farm);
	bfs(&farm, farm.start_vertex);

	// dfs(&farm);
//	print_graph(farm.g, farm.max_order);

	return (0);
}