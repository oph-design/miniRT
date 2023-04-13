#include "minirt.h"

static int	intercept_loop(t_map *map, t_vector hit, int i)
{
	if (map->objects[i].type == SPHERE)
		if (intercept_sphere(map->objects[i],
				new_ray(hit, normalize(sub_vec(map->lighting->pos, hit)))))
			return (1);
	return (0);
}

int	is_shaded(t_map *map, int pos, t_vector hit)
{
	int	i;

	i = 0;
	while ((int)map->obj_count > i)
	{
		if (i != pos && intercept_loop(map, hit, i))
			return (1);
		i++;
	}
	return (0);
}
