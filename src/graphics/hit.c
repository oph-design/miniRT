#include "minirt.h"

void	loop_objects(t_map *map, t_ray ray, double *t, int *pos)
{
	while ((int)map->obj_count > pos[INDEX])
	{
		if (map->objects[pos[INDEX]].type == SPHERE)
			hit_sphere(map->objects[pos[INDEX]], ray, pos, t);
		if (map->objects[pos[INDEX]].type == PLANE)
			hit_plane(map->objects[pos[INDEX]], ray, pos, t);
		if (map->objects[pos[INDEX]].type == CYLINDER)
			hit_cylinder(map->objects[pos[INDEX]], ray, pos, t);
		pos[INDEX]++;
	}
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
	if (t < INFINITY && t >= 0 && !is_shaded(map, pos[INDEX_HIT], at(ray, t)))
		draw_pixel(map->window, j, i, vec_to_color(cast_light(map,
					pos[INDEX_HIT], at(ray, t))));
	else
		draw_pixel(map->window, j, i, write_color(0.0, 0.0, 0.0, 255.0));
}
