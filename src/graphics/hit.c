#include "minirt.h"

void	loop_objects(t_map *map, t_ray ray, double *t, int *pos)
{
	while ((int)map->obj_count > pos[1])
	{
		if (map->objects[pos[1]].type == sphere)
			hit_sphere(map->objects[pos[1]], ray, pos, t);
		pos[1]++;
	}
}

void	hit(t_map *map, int j, int i)
{
	double	x;
	double	y;
	int		pos[2];
	double	t;
	t_ray	ray;

	pos[0] = 0;
	pos[1] = 0;
	t = INFINITY;
	x = j / map->window->width;
	y = i / map->window->height;
	ray = get_ray(map->camera, x, y);
	loop_objects(map, ray, &t, pos);
	if (t < INFINITY && t >= 0)
		draw_pixel(map->window, j, i, vec_to_color(cast_light(map, pos[0],
					at(ray, t))));
	else
		draw_pixel(map->window, j, i, write_color(0.0, 0.0, 0.0, 255.0));
}
