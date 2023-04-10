#include "minirt.h"

void	check_root(double *t, double a, double b, double c)
{
	double	to;
	double	tl;

	to = (-b - sqrt((b * b) - 4 * a * c)) / 2;
	tl = (-b + sqrt((b * b) - 4 * a * c)) / 2;
	if (to < tl && *t > to)
		*t = to;
	else if (*t > tl)
		*t = tl;
}

int	hit_sphere(t_object sp, t_ray ray, int *pos, double *t)
{
	double		a;
	double		b;
	double		c;
	double		disc;
	t_vector	p;

	p = sub_vec(ray.origin, sp.pos);
	a = vec_length_squared(ray.direction);
	b = 2 * dot(p, ray.direction);
	c = vec_length_squared(p) - (sp.radius * sp.radius);
	disc = (b * b) - 4 * a * c;
	if (disc < 0)
		return (0);
	else
	{
		if (disc == 0 && *t > (-b / 2 * a))
			*t = -b / 2 * a;
		else
			check_root(t, a, b, c);
		pos[0] = pos[1];
		return (1);
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
	while ((int)map->obj_count > pos[1])
	{
		if (map->objects[pos[1]].type == sphere)
			hit_sphere(map->objects[pos[1]], ray, pos, &t);
		pos[1]++;
	}
	if (t < INFINITY)
		draw_pixel(map->window, j, i, vec_to_color(cast_light(map, pos[0],
					at(ray, t))));
	else
		draw_pixel(map->window, j, i, write_color(0.0, 0.0, 0.0, 255.0));
}
