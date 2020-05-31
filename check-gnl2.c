#include "my_libft/libft.h"


int main()
{
	char *line;
	int ret;

	ret = get_next_line(0, &line);
	if (ft_strcmp(line, "d") != 0)
	{
		free(line);
		return (0);
	}
	free(line);
	ft_printf("HERE\n");
	// while ((ret = get_next_line(0, &line)))
	// {
	// 	ft_printf("h_line:%s\n", line);
	// 	free(line);
	// }
	// free(line);

	return (0);
}
