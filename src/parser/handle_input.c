#include "parser.h"

int	check_input(int argc, char **argv)
{
	char	*extension;

	if (argc < 2)
		return (ft_putendl_fd("miniRT: too few arguments", 2), 1);
	if (argc > 2)
		return (ft_putendl_fd("miniRT: too many arguments", 2), 1);
	extension = ft_strrchr(argv[1], '.');
	if (!extension)
		return (ft_putendl_fd("miniRT: wrong extension", 2), 1);
	if (ft_strncmp(extension, ".rt", 4))
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
	return (res);
}