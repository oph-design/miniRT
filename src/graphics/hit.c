#include "minirt.h"

void	check_root(int *t, int a, int b, int c)
{
	int	to;
	int	tl;

	to = (-b - sqrt((b * b) - 4 * a * c)) / 2;
	tl = (-b + sqrt((b * b) - 4 * a * c)) / 2;
	if (to < tl && *t > to)
		*t = to;
	else if (*t > tl)
		*t = tl;
}

int	hit_sphere(t_object sp, t_ray ray, int *pos, int *t)
{
	double		a;
	double		b;
	double		c;
	double		disc;
	t_vector	p;

	p = subtract_vec(ray.origin, sp.pos);
	a = dot(ray.direction, ray.direction);
	b = 2.0 * dot(p, ray.direction);
	c = dot(p, p) - (sp.radius * sp.radius);
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (0);
	else
	{
		if (disc == 0)
		{
			if (*t > (-b / 2 * a))
				*t = -b / 2 * a;
		}
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
	int		t;

	pos[0] = 0;
	pos[1] = 0;
	t = 9999;
	x = (double)j / map->window->width;
	y = (double)i / map->window->height;
	while ((int)map->obj_count > pos[1])
	{
		if (map->objects[pos[1]].type == sphere)
		{
			hit_sphere(map->objects[pos[1]], get_ray(map->camera, x, y),
				pos, &t);
		}
		pos[1]++;
	}
	if (t < 9999)
		draw_pixel(map->window, j, i, vec_to_color(map->objects[pos[0]].color));
	else
		draw_pixel(map->window, j, i, ray_color(get_ray(map->camera, x, y)));
}
