#include "minirt.h"

int	main(int argc, char **argv)
{
	if (check_input(argc, argv))
		return (EXIT_FAILURE);
	setup_window();
	return (EXIT_SUCCESS);
}
