#include "minirt.h"

static void	intercept_loop(t_map *map, t_vector hit, int i, double *t)
{
	t_vector	light_dir;

	light_dir = sub_vec(map->lighting->pos, hit);
	if (map->objects[i].type == SPHERE)
		hit_sphere(map->objects[i], new_ray(hit, light_dir), NULL, t);
}

int	is_shaded(t_map *map, int pos, t_vector hit)
{
	int		i;
	double	t;

	i = 0;
	t = INFINITY;
	while ((int)map->obj_count > i)
	{
		if (i != pos)
			intercept_loop(map, hit, i, &t);
		i++;
	}
	if (t < INFINITY && t > ZERO)
		return (1);
	return (0);
}
