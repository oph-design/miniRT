#include "minirt.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	**file;
	t_map	*map;
	int		i;

	if (check_input(argc, argv))
		return (EXIT_FAILURE);
	file = get_file(argv[1]);
	map = get_map(file);
	printf("\nLight POS	 : %f	%f	%f\n\n", map->lighting->pos.x,
		map->lighting->pos.y, map->lighting->pos.z);
	i = -1;
	while (++i < (int)map->obj_count)
	{
		printf("Object POS	%d: %f	%f	%f\n", i + 1, map->objects[i].pos.x,
			map->objects[i].pos.y, map->objects[i].pos.z);
		printf("Color		%d: %f	%f	%f\n\n", i + 1, map->objects[i].color.x,
			map->objects[i].color.y, map->objects[i].color.z);
	}
	setup_window(map);
	free_map(map);
	return (EXIT_SUCCESS);
}
