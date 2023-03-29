#include "minirt.h"

t_ray	*new_ray(t_vector origin, t_vector direction)
{
	t_ray	*new;

	new = malloc(sizeof(t_ray));
	if (!new)
		return (NULL);
	new->origin = &origin;
	new->direction = &direction;
	return (new);
}

t_vector	at(t_ray *ray, double t)
{
	t_vector	dt;

	dt = mult_double_vec(t, *ray->direction);
	return (add_to_vec(*ray->origin, dt));
}

uint32_t	ray_color(t_ray	*ray, t_object *sp)
{
	double		t;
	t_vector	*co1;
	t_vector	*co2;
	t_vector	col;
	t_vector	n;

	t = hit_sphere(sp, ray);
	if (t < 0.0)
	{
		n = normalize(subtract_vec(at(ray, t), *sp->pos));
		free(ray);
		return (color(0.5 * (n.x + 1), 0.5 * (n.y + 1), (n.z + 1), 1.0));
	}
	co1 = new_vec(1.0, 1.0, 1.0);
	co2 = new_vec(0.5, 0.7, 1.0);
	t = 0.5 * normalize(*ray->direction).y + 1.0;
	col = add_to_vec(mult_double_vec(1.0 - t, *co1),
			mult_double_vec(t, *co2));
	free(co1);
	free(co2);
	return (free(ray), color(col.x, col.y, col.z, 1.0));
}
