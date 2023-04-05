#include "minirt.h"

int	hit_sphere(t_object sp, t_ray ray)
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
		return (1);
}

void	hit(t_map *map, int j, int i)
{
	int		k;
	double	x;
	double	y;
	t_ray	ray;

	k = 0;
	x = (double)j / WIDTH;
	y = (double)i / HEIGHT;
	ray = get_ray(map->camera, x, y);
	while ((int)map->obj_count > k)
	{
		if (map->objects[k].type == sphere)
		{
			if (hit_sphere(map->objects[k], ray))
			{
				draw_pixel(map->window, j, i, color(map->objects[k].color.x,
						map->objects[k].color.y,
						map->objects[k].color.z, 255.0));
				break ;
			}
			draw_pixel(map->window, j, i,
				ray_color(ray));
		}
		k++;
	}
}
