#include "minirt.h"

static void	intercept_loop(t_map *map, t_vector hit, int *i, double *t)
{
	if (map->objects[i[INDEX]].type == SPHERE)
	{
		hit_sphere(map->objects[i[INDEX]],
			new_ray(hit, sub_vec(map->lighting->pos, hit)), NULL, &t[0]);
		hit_sphere(map->objects[i[INDEX]],
			new_ray(hit, sub_vec(hit, map->lighting->pos)), NULL, &t[1]);
	}
}

int	is_shaded(t_map *map, int pos, t_vector hit)
{
	int		i[2];
	double	t[2];

	i[INDEX] = 0;
	i[INDEX_HIT] = pos;
	t[0] = INFINITY;
	t[1] = INFINITY;
	while ((int)map->obj_count > i[INDEX])
	{
		if (i[INDEX] != pos)
			intercept_loop(map, hit, i, t);
		i[INDEX]++;
	}
	if (t[0] > t[1] && t[0] < INFINITY)
		return (1);
	return (0);
}
