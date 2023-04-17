#include "minirt.h"

static t_hit	new_hit(t_object obj, t_ray ray, double t, int index)
{
	t_hit	new;

	new.obj = obj;
	new.cam_ray = ray;
	new.hitpoint = at(ray, t);
	new.normal = get_object_normal(obj, new.hitpoint);
	new.index = index;
	return (new);
}

static void	loop_objects(t_map *map, t_ray ray, double *t, size_t *pos)
{
	while (map->obj_count > pos[INDEX])
	{
		if (map->objects[pos[INDEX]].type == SPHERE)
			hit_sphere(map->objects[pos[INDEX]], ray, pos, t);
		else if (map->objects[pos[INDEX]].type == PLANE)
			hit_plane(map->objects[pos[INDEX]], ray, pos, t);
		pos[INDEX]++;
	}
}

void	hit(t_map *map, int j, int i)
{
	double	x;
	double	y;
	size_t	pos[2];
	double	t;
	t_hit	hit;

	pos[INDEX] = 0;
	pos[INDEX_HIT] = 0;
	t = INFINITY;
	x = j / map->window->width;
	y = i / map->window->height;
	loop_objects(map, get_ray(map->camera, x, y), &t, pos);
	hit = new_hit(map->objects[pos[INDEX_HIT]], get_ray(map->camera, x, y),
			t, pos[INDEX_HIT]);
	if (is_shaded(map, hit))
		draw_pixel(map->window, j, i, write_color(0.0, 0.0, 0.0, 255.0));
	else if (t < INFINITY && t > ZERO)
		draw_pixel(map->window, j, i, vec_to_color(cast_light(map, hit)));
	else
		draw_pixel(map->window, j, i, write_color(0.0, 0.0, 0.0, 255.0));
}
