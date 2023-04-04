#include "minirt.h"

t_ray	new_ray(t_vector origin, t_vector direction)
{
	t_ray	new;

	new.origin = origin;
	new.direction = direction;
	return (new);
}

t_ray	get_ray(t_camera *camera, double x, double y)
{
	t_vector	dest;
	t_vector	nx;
	t_vector	ny;

	nx = mult_double_vec(x, camera->horizontal);
	ny = mult_double_vec(y, camera->vertical);
	dest = subtract_vec(add_to_vec(add_to_vec(camera->orientation, nx), ny),
			camera->pos);
	return (new_ray(camera->pos, dest));
}

t_vector	at(t_ray ray, double t)
{
	t_vector	dt;

	dt = mult_double_vec(t, ray.direction);
	return (add_to_vec(ray.origin, dt));
}

uint32_t	ray_color(t_ray	ray, t_object sp)
{
	t_vector	col;
	double		t;

	if (hit_sphere(sp, ray))
		return (color(sp.color.x, sp.color.y, sp.color.z, 255.0));
	t = 0.5 * normalize(ray.direction).y + 1.0;
	col = add_to_vec(mult_double_vec(1.0 - t, new_vec(255, 255, 255)),
			mult_double_vec(t, new_vec(127, 200, 255)));
	return (color(col.x, col.y, col.z, 255.0));
}
