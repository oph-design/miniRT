#include "minirt.h"

t_ray	new_ray(t_vector origin, t_vector direction)
{
	t_ray	new;

	new.origin = origin;
	new.direction = direction;
	return (new);
}

t_ray	get_ray(t_camera *cam, double x, double y)
{
	t_vector	dh;
	t_vector	dv;
	t_vector	dst;

	dh = mult_double_vec(x, cam->horizontal);
	dv = mult_double_vec(y, cam->vertical);
	dst = add_vec(add_vec(cam->orientation, dh), dv);
	return (new_ray(cam->pos, sub_vec(dst, cam->pos)));
}

t_vector	at(t_ray ray, double t)
{
	t_vector	dt;

	dt = mult_double_vec(t, ray.direction);
	return (add_vec(ray.origin, dt));
}

uint32_t	ray_color(t_ray	ray)
{
	t_vector	col;
	double		t;

	t = 0.5 * normalize(ray.direction).y + 1.0;
	col = add_vec(mult_double_vec(1.0 - t, new_vec(255, 255, 255)),
			mult_double_vec(t, new_vec(127, 200, 255)));
	return (write_color(col.x, col.y, col.z, 255.0));
}
