#include "minirt.h"

int	is_in_front(t_vector light_dir, t_ray light_ray, double t)
{
	double	source_length;
	double	hit_length;

	source_length = vec_length_squared(light_dir);
	hit_length = vec_length_squared(sub_vec(light_ray.origin,
				at(light_ray, t)));
	if (source_length > hit_length)
		return (1);
	return (0);
}

static int	intercept_obj(t_map *map, t_hit hit, size_t i)
{
	t_vector	light_dir;
	t_ray		light_ray;
	double		t;

	t = INFINITY;
	light_dir = sub_vec(map->lighting->pos, hit.hitpoint);
	light_ray = new_ray(hit.hitpoint, light_dir);
	if (map->objects[i].type == SPHERE)
		hit_sphere(map->objects[i],
			new_ray(add_vec(mult_double_vec(ZERO, hit.normal),
					hit.hitpoint), light_dir), NULL, &t);
	if (t < INFINITY && t + ZERO > ZERO
		&& is_in_front(light_dir, light_ray, t))
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
