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
	if(ft_strncmp(extension, ".rt", 4))
		return (ft_putendl_fd("miniRT: wrong extension", 2), 1);
	return (0);
}
