
#include "my_libft/libft.h"

/*
int main()
{
	char *line;
	int ret;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		ft_printf("h_line:%s\n", line);
		free(line);
	}
	
	return (0);
}
*/


/*
takes residue and looks for \n there.
if found, then returns line(malloc)
else returns NULL.
*/
char	*get_line_from_res(char **res, char **line)
{
	char *s;
	size_t len;

	if (*res == NULL)
		return (NULL);
	s = ft_strchr(*res, 10);
	if (s)
	{
		*s = '\0';
		s++;
		len = ft_strlen(s);
		*line = ft_strdup(*res);
		*res = ft_memmove(*res, s, len);
		return (s);
	}
	else
	{
		*line = ft_strdup(*res);
		free(*res);
	}
	return (s);
}

/*
first of all look up in residue if some newline left there.
if not left we start reading stdin. IN case found, the first part goes
to line, the other to res;
*/
int		get_next_line_fd_1(char **line)
{
	static char *res;
	size_t ret;
	char buf[BUFF_SIZE];
	char *s;
	char *tmp;

	s = get_line_from_res(&res, line);
	ret = 1;
	while (!s && (ret = read(0, buf, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		if ((s = ft_strchr(buf, 10)))
		{
			*s = '\0';
			s++;
			*line = ft_strdup(buf);
			tmp = ft_strjoin(res, s);
			if (res)
				free(res);
			res = tmp;
			return (1);
		}
		else
		{
			tmp = ft_strjoin(res, s);
			if (res)
				free(res);
			res = tmp;
		}
	}
	return ((ft_strlen(*line) || (res && ft_strlen(res)) || ret) ? 1 : 0);
}

int main()
{
	char *line;
	int ret;


	while ((ret = get_next_line(0, &line)))
	{
		ft_printf("h_line:%s\n", line);
		free(line);
	}
	free(line);

	return (0);
}



/*

int main()
{
	char buf[BUFF_SIZE + 1];
	static char *res;
	int ret;
	char *s;
	char *tmp;
	char *line;
	size_t n;

	while ((ret = read(0, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		ft_printf("in while:%s\n", buf);

		s = ft_strchr(buf, 10);
		if (s)
		{
			s++;
			line = ft_strjoin(res, buf);
			if (res)
				free(res);
			n = ft_strlen(s);
			res = ft_memmove(res, s, n);

			ft_printf("h_line:%s\n", line);
			free(line);
		}
		else
		{
			tmp = ft_strjoin(res, buf);
			if (res)
				free(res);
			res = tmp;
		}
	}

	return (0);
}

*/