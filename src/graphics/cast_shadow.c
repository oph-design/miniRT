#include "minirt.h"

double	degrees(t_vector nrml, t_vector light_dir)
{
	double		tmp;
	double		tmp2;
	double		tmp3;

	tmp = dot(nrml, light_dir);
	tmp2 = sqrt(vec_length_squared(nrml));
	tmp3 = sqrt(vec_length_squared(light_dir));
	return (acos(tmp / (tmp2 * tmp3)) * 180.0 / M_PI);
}

static int	intercept_obj(t_map *map, t_hit hit, size_t i)
{
	t_vector	light_dir;
	double		t;

	t = INFINITY;
	light_dir = normalize(sub_vec(map->lighting->pos, hit.hitpoint));
	if (map->objects[i].type == SPHERE)
		hit_sphere(map->objects[i],
			new_ray(add_vec(mult_double_vec(ZERO, hit.normal),
					hit.hitpoint), light_dir), NULL, &t);
	if (t < INFINITY && t + ZERO > ZERO)
		return (1);
	return (0);
}

int	is_shaded(t_map *map, t_hit hit)
{
	size_t	i;

	i = 0;
	while (map->obj_count > i && !intercept_obj(map, hit, i))
		i++;
	if (i != map->obj_count)
		return (1);
	return (0);
}
