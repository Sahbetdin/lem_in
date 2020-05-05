#include "lem_in.h"

int main(int argc, char **argv)
{
	t_map farm;
	int res;
	int order;
	int k, j, n;
	char *line;


	farm_init(&farm);
	if (read_map(&farm) == false)
	{
		ft_printf("ERROR in map");
		exit(0);
	}
	graph_fill_in(&farm);
	print_graph(farm.g, farm.max_order);
	return (0);
}