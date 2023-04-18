#include "minirt.h"

double	check_root(double *t, t_vector var, size_t *pos)
{
	double	to;
	double	tl;
	double	disc;

	disc = sqrt(var.y * var.y - var.x * var.z);
	to = (-var.y + disc) / var.x;
	tl = (-var.y - disc) / var.x;
	if (to < tl && *t > to)
	{
		if (pos)
			pos[INDEX_HIT] = pos[INDEX];
		return (to);
	}
	else if (*t > tl)
	{
		if (pos)
			pos[INDEX_HIT] = pos[INDEX];
		return (tl);
	}
	return (*t);
}

int	hit_sphere(t_object sp, t_ray ray, size_t *pos, double *t)
{
	t_vector	var;
	double		disc;
	t_vector	p;

	p = sub_vec(ray.origin, sp.pos);
	var.x = vec_length_squared(ray.direction);
	var.y = dot(p, ray.direction);
	var.z = vec_length_squared(p) - (sp.radius * sp.radius);
	disc = sqrt((var.y * var.y) - var.x * var.z);
	if (disc < 0.0)
		return (0);
	else
	{
		if (disc == 0 && *t > (-var.y / 2 * var.x))
		{
			*t = -var.y / 2 * var.x;
			if (pos)
				pos[INDEX_HIT] = pos[INDEX];
		}
		else
			*t = check_root(t, var, pos);
		return (1);
	}
}
