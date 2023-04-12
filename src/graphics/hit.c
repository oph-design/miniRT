#include "minirt.h"

void	loop_objects(t_map *map, t_ray ray, double *t, int *pos)
{
	while ((int)map->obj_count > pos[INDEX])
	{
		if (map->objects[pos[INDEX]].type == SPHERE)
			hit_sphere(map->objects[pos[INDEX]], ray, pos, t);
		pos[INDEX]++;
	}
}

int	intercept_sphere(t_object obj, t_ray ray)
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
		if (to > 1.0 && tl > 1.0)
			return (1);
	}
	return (0);
}
// if ((to > 0.0 && to <= sqrt(vec_length_squared(ray.direction)))
// 	|| (tl > 0.0 && tl <= sqrt(vec_length_squared(ray.direction))))

int	is_shaded(t_map *map, t_vector hit, int i)
{
	if (map->objects[i].type == SPHERE)
		if (intercept_sphere(map->objects[i],
				new_ray(hit, normalize(sub_vec(map->lighting->pos, hit)))))
			return (1);
	return (0);
}

int	shadow_cast(t_map *map, int pos, t_vector hit)
{
	int	i;

	i = 0;
	while ((int)map->obj_count > i)
	{
		if (i != pos && is_shaded(map, hit, i))
			return (1);
		i++;
	}
	return (0);
}

void	hit(t_map *map, int j, int i)
{
	double	x;
	double	y;
	int		pos[2];
	double	t;
	t_ray	ray;

	pos[INDEX] = 0;
	pos[INDEX_HIT] = 0;
	t = INFINITY;
	x = j / map->window->width;
	y = i / map->window->height;
	ray = get_ray(map->camera, x, y);
	loop_objects(map, ray, &t, pos);
	if (shadow_cast(map, pos[INDEX_HIT], at(ray, t)))
		draw_pixel(map->window, j, i, write_color(255.0, 255.0, 255.0, 255.0));
	else if (t < INFINITY && t >= 0)
		draw_pixel(map->window, j, i, vec_to_color(cast_light(map,
					pos[INDEX_HIT], at(ray, t))));
	else
		draw_pixel(map->window, j, i, write_color(0.0, 0.0, 0.0, 255.0));
}
// if (t < INFINITY && t >= 0 && !shadow_cast(map, pos[INDEX_HIT], at(ray, t)))
