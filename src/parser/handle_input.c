#include "parser.h"

int	check_input(int argc, char **argv)
{
	char	*extension;

	if (argc != 2)
		return (ft_putendl_fd("Error: input: wrong number of files", 2), 1);
	extension = ft_strrchr(argv[1], '.');
	if (!extension || ft_strncmp(extension, ".rt", 4))
		return (ft_putendl_fd("miniRT: wrong extension", 2), 1);
	return (0);
}

char	**get_file(char	*name)
{
	int		fd;
	char	*nl;
	char	*file;
	char	**res;

	fd = open(name, 0);
	if (fd == -1)
	{
		ft_putendl_fd("Error: file: not accessable", 2);
		exit(EXIT_FAILURE);
	}
	file = get_next_line(fd);
	while (file && file[0] && file[ft_strlen(file) - 1] == '\n')
	{
		nl = get_next_line(fd);
		if (nl == NULL)
			break ;
		file = ft_strjoin_gnl(file, nl);
		free(nl);
	}
	res = ft_split(file, '\n');
	free(file);
	close(fd);
	return (res);
}

char	*stra_iteri(char **arr, char *set, int id)
{
	size_t			j;
	static size_t	i[6] = {0, 0, 0, 0, 0, 0};

	j = 0;
	while (arr[i[id]] != NULL)
	{
		while (arr[i[id]][j] && ft_iswhitespcs(arr[i[id]][j]))
			j++;
		if (!ft_strncmp(arr[i[id]] + j, set, ft_strlen(set))
			&& ft_iswhitespcs(arr[i[id]][j + ft_strlen(set)]))
			return (arr[(i[id])++]);
		j = 0;
		(i[id])++;
	}
	return (NULL);
}
