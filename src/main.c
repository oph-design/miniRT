#include "minirt.h"

int	main(int argc, char **argv)
{
	char	**file;
	size_t	i;
	t_map	*map;

	i = 0;
	if (check_input(argc, argv))
		return (EXIT_FAILURE);
	file = get_file(argv[1]);
	map = get_map(file);
	//setup_window();
	return (EXIT_SUCCESS);
}
