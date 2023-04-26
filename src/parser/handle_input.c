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

char	*get_first_line(int fd)
{
	char	*res;
	char	*tmp;

	tmp = get_next_line(fd);
	res = ft_strtrim(tmp, " \t\v\r\f");
	free(tmp);
	while (res && !ft_strncmp(res, "#", 1))
	{
		free(res);
		tmp = get_next_line(fd);
		res = ft_strtrim(tmp, " \t\v\r\f");
		free(tmp);
	}
	if (res && (!res[0] || res[0] == '\n'))
		return (free(res), NULL);
	return (res);
}

char	**get_file(int fd)
{
	char	*nl;
	char	*tmp;
	char	*file;
	char	**res;

	file = get_first_line(fd);
	while (file && file[0] && file[ft_strlen(file) - 1] == '\n')
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		nl = ft_strtrim(tmp, " \t\v\r\f");
		free(tmp);
		if (ft_strncmp(nl, "#", 1))
			file = ft_strjoin_gnl(file, nl);
		free(nl);
	}
	res = ft_split(file, '\n');
	return (free(file), close(fd), res);
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
	if (!ft_strncmp(line, "cn", 2) && ft_iswhitespcs(*(line + 2)))
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
		if (!is_identifier(file[i] + j))
			return (0);
		j = 0;
		i++;
	}
	return (1);
}
