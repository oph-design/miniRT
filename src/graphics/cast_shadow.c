#include "minirt.h"

static int	intercept_sphere(t_object obj, t_ray ray)
{
	t_vector	h;
	double		disc;
	t_vector	p;
	double		to;
	double		tl;

	p = sub_vec(ray.origin, obj.pos);
	h.x = vec_length_squared(ray.direction);
	h.y = 2 * dot(p, ray.direction);
	h.z = vec_length_squared(p) - (obj.radius * obj.radius);
	disc = (h.y * h.y) - 4 * h.x * h.z;
	if (disc < 0)
		return (0);
	else
	{
		if (disc == 0)
			return (1);
		to = (-h.y + disc) / 2;
		tl = (-h.y - disc) / 2;
		if (to > 1.5 && tl > 1.5)
			return (1);
	}
	return (0);
}

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
