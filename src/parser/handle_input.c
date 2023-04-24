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

int	is_identifier(char *line)
{
	if (!ft_strncmp(line, "A", 1) && ft_iswhitespcs(*(line + 1)))
		return (1);
	if (!ft_strncmp(line, "C", 1) && ft_iswhitespcs(*(line + 1)))
		return (1);
	if (!ft_strncmp(line, "L", 1) && ft_iswhitespcs(*(line + 1)))
		return (1);
	if (!ft_strncmp(line, "sp", 2) && ft_iswhitespcs(*(line + 2)))
		return (1);
	if (!ft_strncmp(line, "cy", 2) && ft_iswhitespcs(*(line + 2)))
		return (1);
	if (!ft_strncmp(line, "cb", 2) && ft_iswhitespcs(*(line + 2)))
		return (1);
	if (!ft_strncmp(line, "pl", 2) && ft_iswhitespcs(*(line + 2)))
		return (1);
	return (0);
}

int	find_invalid_ids(char **file)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (file[i] != NULL)
	{
		while (file[i][j] && ft_iswhitespcs(file[i][j]))
			j++;
		if (!is_identifier(file[i] + j))
			return (0);
		j = 0;
		i++;
	}
	return (1);
}

int	is_object(char *str)
{
	return (!ft_strncmp(str, "A", 1) || !ft_strncmp(str, "C", 1)
		|| !ft_strncmp(str, "L", 1));
}
