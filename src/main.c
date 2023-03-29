#include "minirt.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	**file;
	t_map	*map;

	if (check_input(argc, argv))
		return (EXIT_FAILURE);
	file = get_file(argv[1]);
	map = get_map(file);
	free_map(map);
	setup_window();
	return (EXIT_SUCCESS);
}
