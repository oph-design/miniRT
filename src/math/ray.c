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
	double		ratio;
	double		fov;
	double		nx;
	double		ny;

	ratio = 16.0 / 9.0;
	fov = tan((camera->fov / 2));
	nx = ((2 * x - 1.0) * ratio) * fov;
	// nx = (((2 * ((x + 0.5)) / 1080.0) - 1.0) * ratio) * fov;
	ny = (1.0 - 2.0 * y) * fov;
	// ny = (1.0 - 2.0 * (y + 0.5) / 1920.0) * fov;
	dest = new_vec(nx, ny, camera->orientation.z);
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
